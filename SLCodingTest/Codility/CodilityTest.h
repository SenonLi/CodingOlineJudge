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

	// Find value that occurs in odd number of elements.
	int OddOccurrencesInArray(vector<int> &A);

	// Find the missing element in a given permutation.
	int PermMissingElem(vector<int> &A);

	// Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|
	int TapeEquilibrium(vector<int> &A);

	// Check whether array A is a permutation.
	int PermCheck(vector<int> &A);

private:
	int GetNextBinaryGap(int& N);
};

