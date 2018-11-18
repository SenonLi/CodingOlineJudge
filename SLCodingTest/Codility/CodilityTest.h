#pragma once

#include <vector>
using namespace std;


class CodilityTest
{
public:
	// Find longest sequence of zeros in binary representation of an integer
	int GetMaxBinaryGap(int N);
	
	// Rotate an array to the right by a given number of steps.
	vector<int> CyclicRotation(vector<int> &A, int K);

private:
	int GetNextBinaryGap(int& N);
};

