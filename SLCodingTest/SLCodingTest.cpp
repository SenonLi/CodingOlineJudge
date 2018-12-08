// SLCodingTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "Codility/CodilityTest.h"
#include "SolutionManual/CISolutionManual.h"


int main()
{
	CodilityTest test;
	//std::cout << "Max Binary Gap of 1041 : \t" << test.GetMaxBinaryGap(1041) << "\n";

	CISolutionManual testSolutionManal;


	//std::vector<int> testVecP = { 2, 5, 0 };
	std::vector<int> testVecQ = { 8, 8, 5, 7, 9, 8, 7, 4, 8 };
	//std::string S = "CAGCCTA";

	//std::string testStr = "{[()()]}";
	int result = test.StoneWall(testVecQ);


	cout << "\n" << result;
	
	getchar();
}

