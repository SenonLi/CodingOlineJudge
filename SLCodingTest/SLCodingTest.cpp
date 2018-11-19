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


	std::vector<int> testVec = { 1, 3, 1, 4, 2, 3, 5, 4 };
	int a = test.FrogRiverOne(5, testVec);

	getchar();
}

