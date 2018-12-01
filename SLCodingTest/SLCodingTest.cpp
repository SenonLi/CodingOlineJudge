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


	std::vector<int> testVecP = { 2, 5, 0 };
	std::vector<int> testVecQ = { 4, 5, 6 };
	std::string S = "CAGCCTA";

	std::vector<int> result = test.GenomicRangeQuery(S, testVecP, testVecQ);

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << "  ";


	getchar();
}

