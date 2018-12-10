// SLCodingTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "Codility/CodilityTest.h"
#include "SolutionManual/CISolutionManual.h"
#include "LeetCode/LeetCodeProblems.h"

int main()
{
	CodilityTest test;
	//std::cout << "Max Binary Gap of 1041 : \t" << test.GetMaxBinaryGap(1041) << "\n";

	CISolutionManual testSolutionManal;


	////std::vector<int> testVecP = { 2, 5, 0 };
	//std::vector<int> testVecQ = { 8, 8, 5, 7, 9, 8, 7, 4, 8 };
	////std::string testStr = "{[()()]}";
	//int result = test.StoneWall(testVecQ);
	//cout << "\n" << result;


	LeetCodeProblems leetTest;


	//vector<vector<int>> buildings = { {2, 9, 10}, { 2, 7, 15 }, { 5, 12, 12 }, { 15, 20, 10 }, { 19, 24, 8 } };
	vector<vector<int>> buildings = { {1,2,1},{1,2,2},{1,2,3} };
	//vector<vector<int>> buildings = { {0, 2, 3}, {2, 5, 3} };
	vector<pair<int, int>> keyPoints = leetTest.GetSkyline_218_MultiSet(buildings);

	for (pair<int, int> keyPoint : keyPoints) {
		cout << "[" << keyPoint.first << ", " << keyPoint.second << "]  ";
	}


	getchar();
}

