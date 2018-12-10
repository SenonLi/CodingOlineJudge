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


};

