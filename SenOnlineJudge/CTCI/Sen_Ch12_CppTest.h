#pragma once

#ifndef __Sen_Ch12_CppTest__
#define __Sen_Ch12_CppTest__

#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <algorithm>

using namespace std;


class Sen_Ch12_CppTest
{
public:
	Sen_Ch12_CppTest();
	virtual ~Sen_Ch12_CppTest();

	void printLastKLines(int k, string fileName = "CTCI/ReadFile.txt");

protected:
	string ReadFileName = "CTCI/ReadFile.txt";
	int k = 10;
};



#endif // __Sen_Ch12_CppTest__