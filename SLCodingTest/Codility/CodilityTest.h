#pragma once

#include <vector>
#include <string>
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

	// Find the earliest time when a frog can jump to the other side of a river.
	int FrogRiverOne(int X, vector<int> &A);

	// Calculate the values of counters after applying all alternating operations 
	// : increase counter by 1; set value of all counters to current maximum.
	vector<int> MaxCounters(int N, vector<int> &A);

	// Find the smallest positive integer that does not occur in a given sequence.
	int MissingInteger(vector<int> &A);

	// Find the Number of perfect squares between two given numbers
	int PerfectSquare(int A, int B);

	// Find the positions at which the decimal representation of A occurs as a substring in a decimal representation of B
	int DecimalSubString(int A, int B);

	// Count the number of passing cars on the road.
	int PassingCars(vector<int> &A);

	// Find the minimal nucleotide from a range of sequence DNA.
	vector<int> GenomicRangeQuery(string &S, vector<int> &P, vector<int> &Q);

	// Find the minimal average of any slice containing at least two elements.
	int MinAvgTwoSlice(vector<int> &A);

	// Compute number of integers divisible by k in range [a..b].
	int CountDiv(int A, int B, int K);

	// Compute number of distinct values in an array.
	int Distinct(vector<int> &A);

	// Determine whether a triangle can be built from a given set of edges.
	int Triangle(vector<int> &A);

	// Maximize A[P] * A[Q] * A[R] for any triplet (P, Q, R).
	int MaxProductOfThree(vector<int> &A);

private:
	int GetNextBinaryGap(int& N);
};

