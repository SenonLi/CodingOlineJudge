// SLCodingTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <string>
#include <vector>

#include "Codility/CodilityTest.h"
#include "SolutionManual/CISolutionManual.h"
#include "LeetCode/LeetCodeProblems.h"

using namespace std;

int main()
{
	CodilityTest test;

	//std::vector<int> testVecP = { 2, 5, 0 };
	//std::vector<int> testVecQ = { 8, 8, 5, 7, 9, 8, 7, 4, 8 };
	//std::string testStr = "{[()()]}";


	LeetCodeProblems leetTest;
	vector<vector<int>> buildings = { {1,2,1},{1,2,2},{1,2,3} };
	//vector<pair<int, int>> keyPoints = leetTest.GetSkyline_218_MultiSet(buildings);
	//for (pair<int, int> keyPoint : keyPoints) {
	//	cout << "[" << keyPoint.first << ", " << keyPoint.second << "]  ";
	//}
	std::vector<int> testVecQ = { 0,0,1,1,1,2,2,3,3,4 };
	string result = leetTest._38_CountAndSay(4);
	cout << "\n" << result;





	getchar();
	return 1;
}