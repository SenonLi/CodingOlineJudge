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

};

