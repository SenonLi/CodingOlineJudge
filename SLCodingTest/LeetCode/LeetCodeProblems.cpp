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

vector<pair<int, int>> LeetCodeProblems::GetSkyline_218(vector<vector<int>>& buildings)
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




