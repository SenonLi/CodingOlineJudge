#include "../pch.h"
#include "LeetCodeProblems.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>


/*	Problem 218, Skyline

	vector<vector<int>> left_left_buildings = { {2, 9, 10}, { 2, 7, 15 }, { 5, 12, 12 }, { 15, 20, 10 }, { 19, 24, 8 } };
	vector<vector<int>> right_right_buildings = { {1,2,1},{1,2,2},{1,2,3} };
	vector<vector<int>> left_right_buildings = { {0, 2, 3}, {2, 5, 3} };
	vector<pair<int, int>> keyPoints = leetTest.GetSkyline_218(buildings);

	for (pair<int, int> keyPoint : keyPoints) {
		cout << "[" << keyPoint.first << ", " << keyPoint.second << "]  ";
	}

*/
enum LineNodeSideType { LEFT, RIGHT };
struct BuildingLineNode {
	int m_X = 0;
	int m_Y = 0;
	LineNodeSideType m_SideType;
	BuildingLineNode(int x, int y, LineNodeSideType type) : m_X(x), m_Y(y), m_SideType(type) {};
};

vector<pair<int, int>> LeetCodeProblems::GetSkyline_218_PriorityQueue(vector<vector<int>>& buildings)
{
	vector<BuildingLineNode> buildingLineNodes;
	for (auto &b : buildings) {
		buildingLineNodes.push_back(BuildingLineNode(b[0], b[2], LEFT));
		buildingLineNodes.push_back(BuildingLineNode(b[1], b[2], RIGHT));
	}
	std::sort(buildingLineNodes.begin(), buildingLineNodes.end(), [](const BuildingLineNode &a, const BuildingLineNode &b) {
		// This sort algorithm for buildingLineNodes is for determination of keyPoints using heightPriorityQueue;
		// Every building has left and right, and keyPoints is based on left.
		if (a.m_X != b.m_X) return a.m_X < b.m_X;
		// Below covers buildings with same left or same right; our purpose is to only let keyPoint-buildings affact the heightPriorityQueue;

		// When same left (left is for keyPoint determination), put the heigher one in front, such that it will apear first in the priority_queue,
		//		and the lower one won't affect the top of the priority_queue, because it's covered by the front one.
		else if (a.m_SideType == LEFT && b.m_SideType == LEFT) return a.m_Y > b.m_Y;
		// When same right, the lower buildings should be in front, 
		// because we need their dirty-flags will be processed after the keyPoint-building;
		// we need to pop the lower buildings after the keyPoint-building is already processed.
		else if (a.m_SideType == RIGHT && b.m_SideType == RIGHT) return a.m_Y < b.m_Y;
		// When comparing a left lineNode and a right lineNode, always put left in front,
		// because right lineNode is for keyPoint determination, and we need to consider both buildings;
		// if put right lineNode (from left-Building) in front, the right-building will not be considered.
		else return a.m_SideType != LEFT;
	});

	
	/* 
	Every building has left and right, and keyPoints is based on left;
	to determine keyPoints, left values need to be sorted, and heightPriorityQueue is the best auto sorted data-structure
		1. heightPriorityQueue is used to co-operate with left values for determine keyPoints.
		2. when there is a left lineNode, heightPriorityQueue needs a insertion-update;
		3. when there is a right lineNode, one building is gone, so heightPriorityQueue needs an update (pop):
			*. pop() is the only way to remove an element from priority_queue, so whether or not we should pop is the problem;
			*. we can		only pop()		the top one in the priority_queue;
			*. we should	only pop() when the top building has ended (we already found its right lineNode);
			*. for those buildings already ended, but not the top of the queue, they need to wait using a dirty-flag;
			*. the dirty flag records how many buildings (at key-height) have ended and are waiting to be popped;
			*. Dirty-Flag: buildingEndedCountMap, map from height to ended-count.
	*/
	priority_queue<int> heightPriorityQueue;
	heightPriorityQueue.push(0); // Adding the bottom 0 is important, because we also need the ground keyPoints!
	unordered_map<int, int> buildingEndedCountMap;

	vector<pair<int, int>> result;
	int lastMaxHeight = 0, currentMaxHeight = 0;
	for (auto &lineNode : buildingLineNodes) {
		if (lineNode.m_SideType == LEFT) {
			heightPriorityQueue.push(lineNode.m_Y);
		}
		else {
			buildingEndedCountMap[lineNode.m_Y] += 1; // one building ended, update dirty-flag first, then check

			// Whenever found a right lineNode, it's the time to check and pop based on the updated dirty-flag
			// Need a while_loop to pop() all potentials buildings:  the first one is always the lineNode-building, 
			//     and the rest of qualified buildings are the ones covered under the silhouette.
			while (!heightPriorityQueue.empty()	&& buildingEndedCountMap[heightPriorityQueue.top()] > 0)
			{
				buildingEndedCountMap[heightPriorityQueue.top()] -= 1;
				heightPriorityQueue.pop();
			}
		}

		currentMaxHeight = heightPriorityQueue.top();
		if (currentMaxHeight != lastMaxHeight) {
			// currentMaxHeight is from the most updated heightPriorityQueue (either right after a left-lineNode-update, or a right-lineNode-update),
			// if not equal, currentMaxHeight is new, and should push the new one
			result.emplace_back(lineNode.m_X, currentMaxHeight);
			lastMaxHeight = currentMaxHeight;
		}
	}
	return result;
}

/*
GetSkyline_218_MultiSet is a short version of GetSkyline_218_PriorityQueue using MultiSet for easy Element-Erasing
Using the trick of negative left-height
and 
default sorting of pair<int, int> : when first int (x) is same with each other, sort with second int (y);
									the negative left-left-height will generate		abs-descending order;
									and positive right-right-height will generate	abs-ascending order;
									the easy erasing of MultiSet could help avoid left-right-height comparison.
See GetSkyline_218_PriorityQueue to understand how the sorting help solve all possible cases.
*/
#include <set>
vector<pair<int, int>> LeetCodeProblems::GetSkyline_218_MultiSet(vector<vector<int>>& buildings)
{
	vector<pair<int, int>> buildingLineNodes;
	for (auto &b : buildings) {
		// Add negative height for easy sorting of same left-left-height buildings problem
		buildingLineNodes.emplace_back(b[0], -b[2]);
		 // Default ascending order of rightLindNodes could avoid right-right-height buildings problem
		buildingLineNodes.emplace_back(b[1], b[2]);
	}
	std::sort(buildingLineNodes.begin(), buildingLineNodes.end());
	multiset<int> heightMultiSet;
	heightMultiSet.insert(0); // Adding the bottom 0 is important, because we also need the ground keyPoints!
	vector<pair<int, int>> result;
	int lastMaxHeight = 0, currentMaxHeight = 0;
	for (auto &lineNode : buildingLineNodes) {
		if (lineNode.second < 0) {
			heightMultiSet.insert(-lineNode.second);
		}
		else {
			heightMultiSet.erase(heightMultiSet.find(lineNode.second));
		}

		// The MultiSet default ascending sorting algorithm will help make sure below is correct;
		// To totally understand, see the explanation in GetSkyline_218_PriorityQueue.
		currentMaxHeight = *heightMultiSet.rbegin();
		if (currentMaxHeight != lastMaxHeight) {
			result.push_back({ lineNode.first, currentMaxHeight });
			lastMaxHeight = currentMaxHeight;
		}
	}
	return result;
}


/*
Since the array is already sorted, we can keep two pointers ii and jj,
where ii is the slow-runner while jj is the fast-runner.

As long as nums[i] = nums[j]nums[i]=nums[j], we increment jj to skip the duplicate
*/
int LeetCodeProblems::RemoveDuplicates_26(vector<int>& nums)
{
	if (nums.size() < 2) {
		return nums.size();
	}

	std::vector<int>::iterator slow = nums.begin();
	std::vector<int>::iterator fast = slow + 1;
	while (fast != nums.end()) {
		if (*fast == *slow)
			fast++;
		else {
			slow++;
			*slow = *fast;
		}
	}
	slow++;
	nums.erase(slow, nums.end());

	return nums.size();
}


string LeetCodeProblems::_38_CountAndSay(int n)
{
	string say = "1";
	if (n == 1)
		return say;

	string nextSay;
	for (int i = 2; i <= n; ++i) {
		// in each loop, say is the input, nextSay is the output
		int count = 1;
		// To decide the count, we need to compare, which means there will be at least two char needed;
		// std::string will always have '\0' at the end, which could be used (j will start from 1 to the end '\0')
		for (int j = 1; j <= say.length(); ++j) {
			if (say[j] == say[j-1]) {
				count++;
			}
			else {
				nextSay.push_back(count + '0');
				nextSay.push_back(say[j-1]);

				// Update and Reset
				count = 1;
			}
		}

		// Update and Reset
		say = nextSay;
		nextSay = "";
	}

	return say;
}



/*
	Directed-Edges times[i] = (fromNode, toNode, timeCost);
	There are N network nodes, labelled 1 to N.
	send a signal from a certain node K, K will be in the range [1, N]
	How long will it take for all nodes to receive the signal?
*/
int LeetCodeProblems::_743_NetworkDelayTime_Dijkstra(vector<vector<int>>& times, int N, int K)
{
	// Creat directedEdges, a vector based on fromNodeIndex, each element contains a vector of {toNode, timeCost}
	// the directedEdges is based on times, no size requirements (doesn't have to be N*N), but still fromNode-traceable
	vector<vector<std::pair<int, int>>> directedEdges(N);
	for (int i = 0; i < times.size(); i++) {
		int fromNode = times[i][0] - 1, toNode = times[i][1] - 1, timeCost = times[i][2];
		directedEdges[fromNode].push_back({toNode, timeCost});
	}
	
	// start from the sourceNode, then to the next closest connected node, 
	// priority_queue will be used to get the closest connected node (all connected nodes will be pushed, and the shortest will be popped)
	// the loop will end when all connected nodes have been popped (all connected nodes are calculated)
	// priority_queue will sort based on timeCost, and toNode is the auxiliary paired data: std::pair<int timeCost, int toNode>
	priority_queue<pair<int, int>, vector<std::pair<int, int>>, std::greater<void>> curNodeLeastTimeCostQueue;
	
	// The source Node is always zero, and we start traversing the directedEdges from the sourceNode 
	curNodeLeastTimeCostQueue.push({ 0, K - 1});
	
	// The while loop below is to calculate the shortest timeCostFromSrcNode from SourceNode to all the other nodes, saved into leastSrcToNodesTimeCosts
	vector<int> leastSrcToNodesTimeCosts(N, -1);
	while (!curNodeLeastTimeCostQueue.empty()) {
		// always start from top(), which toNode has the least timeCostFromSrcNode (fromSrcNode to toNode)
		pair<int, int> newClosestNode = curNodeLeastTimeCostQueue.top();
		curNodeLeastTimeCostQueue.pop();
		int timeCostFromSrcNode = newClosestNode.first;
		int targetNode = newClosestNode.second;

		if (leastSrcToNodesTimeCosts[targetNode] != -1)
			continue; // if not -1, toNode must alreay got the least timeCostFromSrcNode
		else
		{
			leastSrcToNodesTimeCosts[targetNode] = timeCostFromSrcNode;
			for (pair<int, int> edgeTimeCost : directedEdges[targetNode])
				curNodeLeastTimeCostQueue.push({ edgeTimeCost.second + timeCostFromSrcNode, edgeTimeCost.first });
		}

	}
	
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (leastSrcToNodesTimeCosts[i] == -1) 
			return -1;
		result = std::max(result, leastSrcToNodesTimeCosts[i]);
	}
	return result;
}


int LeetCodeProblems::_743_NetworkDelayTime(vector<vector<int>>& times, int N, int K)
{
	vector<int> dist(N + 1, INT_MAX);
	dist[K] = 0;
	for (int i = 0; i < N; i++) {
		for (vector<int> e : times) {
			int u = e[0], v = e[1], w = e[2];
			if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
			}
		}
	}

	int maxwait = 0;
	for (int i = 1; i <= N; i++)
		maxwait = max(maxwait, dist[i]);
	return maxwait == INT_MAX ? -1 : maxwait;
}

#include <stack>
int LeetCodeProblems::_743_NetworkDelayTime_100(vector<vector<int>>& times, int N, int K)
{
	vector<int> currentTime(N, -1);
	K = K - 1; // make zero based.

	// convert to a matrix for fast access, and make indexes zero based
	vector<vector<int>> travelMap(N, vector<int> {});
	for (auto& tm : travelMap) {
		tm.assign(N, -1);
	}
	for (auto& t : times) {
		travelMap[t[0] - 1][t[1] - 1] = t[2];
	}

	stack<int> toProcess;
	toProcess.push(K);
	currentTime[K] = 0;

	do {
		int node = toProcess.top();
		toProcess.pop();
		int curNodeTime = currentTime[node];

		for (int target = 0; target < N; target++) {
			int travelTime = travelMap[node][target];
			if (travelTime < 0) {
				continue;
			}
			const int newTime = curNodeTime + travelTime;
			if (currentTime[target] == -1 || newTime < currentTime[target]) {
				currentTime[target] = newTime;
				toProcess.push(target);
			}
		}
	} while (toProcess.size() > 0);

	int maxTime = 0;
	for (int t : currentTime) {
		if (t == -1) {
			return -1;
		}
		maxTime = max(maxTime, t);
	}

	return maxTime;
}
