#pragma once

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class LeetCodeProblems
{
public:
	// 218. The Skyline Problem
	vector<pair<int, int>> GetSkyline_218_PriorityQueue(vector<vector<int>>& buildings);
	vector<pair<int, int>> GetSkyline_218_MultiSet(vector<vector<int>>& buildings);

	// 26. Remove Duplicates from Sorted Array
	int RemoveDuplicates_26(vector<int>& nums);

	// 38. Count and Say
	string _38_CountAndSay(int n);

	// 743. Network Delay Time
	int _743_NetworkDelayTime(vector<vector<int>>& times, int N, int K);
	int _743_NetworkDelayTime_100(vector<vector<int>>& times, int N, int K);
	
	vector<int> Dijkstra(vector<vector<pair<int, int>>>& g, int src);
	int _743_NetworkDelayTime_Dijkstra(vector<vector<int>>& times, int N, int K);


};

