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
	//std::vector<int> testVecQ = { 4, 2, 2, 5, 1, 5, 8 };
	//std::string S = "CAGCCTA";

	int result = test.CountDiv(0, 0, 11);


	cout << "\n" << result;
	
	getchar();
}

