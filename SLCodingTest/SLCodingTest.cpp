// SLCodingTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "Codility/CodilityTest.h"
#include "SolutionManual/CISolutionManual.h"

#include <vector>
using namespace std;


int main()
{
	CodilityTest test;
	//std::cout << "Max Binary Gap of 1041 : \t" << test.GetMaxBinaryGap(1041) << "\n";

	CISolutionManual testSolutionManal;


	std::vector<int> testVec = { 3, 4, 4, 6, 1, 4, 4 };
	std::vector<int> testVeccc = test.MaxCounters(5, testVec);

	getchar();
}

