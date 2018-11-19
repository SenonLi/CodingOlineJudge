#include "../pch.h"
#include "CodilityTest.h"

#include <algorithm>

/// <param name="N">Decimal Interger [IN/OUT]</summary>
/// <return>The rightest binary gap </return>
int CodilityTest::GetNextBinaryGap(int& N)
{
	int gapCount = 0;
	bool startCount = false;
	while (N > 1)
	{
		startCount = N % 2 == 1;
		if (startCount)
		{
			while (startCount && N > 1)
			{
				N = N >> 1;
				if (N % 2 == 1)
				{
					if (gapCount > 0)
					{
						// Found gap
						return gapCount;
					}
					else
					{
						// new StartOneIndex
						continue;
					}
				}
				else
				{
					gapCount++;
				}
			}
		}
		else
		{
			N = N >> 1;
		}

	}

	return gapCount;
}

/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.
For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.
Write a function:
int solution(int N);
that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.
For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.
Write an efficient algorithm for the following assumptions:
N is an integer within the range [1..2,147,483,647].

GetMaxBinaryGap(15) should return 0;
GetMaxBinaryGap(1041) should return 5.
*/
int CodilityTest::GetMaxBinaryGap(int N) {
	// write your code in C++14 (g++ 6.2.0)

	int maxGap = 0;
	int newGap = 0;

	// if N <= 4, there won't be any Gap
	while (N > 4)
	{
		newGap = GetNextBinaryGap(N);
		maxGap = maxGap > newGap ? maxGap : newGap;
	}

	return maxGap;
}

/*
For example, given

	A = [3, 8, 9, 7, 6]
	K = 3
the function should return [9, 7, 6, 3, 8]. Three rotations were made:

	[3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
	[6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
	[7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
*/
vector<int> CodilityTest::CyclicRotation(vector<int> &A, int K) 
{
	// write your code in C++14 (g++ 6.2.0)
	int size = A.size();
	if (size == 0)
		return A;

	if (K >= size)
		K = K % size;
	if (K == size)
		return A;

	vector<int> result(A.size());
	for (int i = 0; i < K; ++i)
	{
		result[i] = A[size - K + i];
	}
	for (int i = 0; i < (size - K); ++i)
	{
		result[K + i] = A[i];
	}
	return result;
}


int CodilityTest::OddOccurrencesInArray(vector<int> &A) 
{
	int result = 0;

	for (int a : A)
	{
		result ^= a;
	}

	return result;
}

int CodilityTest::PermMissingElem(vector<int> &A) {
	// Need to use long, in case total is too large.
	unsigned long total = 0;
	for (int a : A) {
		total += a;
	}

	unsigned int nMax = A.size() + 1;

	return (nMax * (nMax + 1) / 2) - total;
}

/*
For example, consider array A such that

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
We can split this tape in four places:

P = 1, difference = |3 - 10| = 7
P = 2, difference = |4 - 9| = 5
P = 3, difference = |6 - 7| = 1
P = 4, difference = |10 - 3| = 7

the function should return 1, as explained above.
*/
int CodilityTest::TapeEquilibrium(vector<int> &A) 
{
	// This problem must traverse and calculate total sum for N times,
	// cannot just go for both head/tail and just test partial sum of both side,
	// because the rest in the middle could change the partial sum result.
	long total = 0;

	for (int a : A)
		total += a;

	long leftTotal = A[0];
	long rightTotal = total - leftTotal;

	// Have to initial minDiff using rightTotal - leftTotal
	// Otherwise, you will always fail unless using the maximum of long
	long minDiff = std::abs(rightTotal - leftTotal);

	// Have to start from i= 1, because leftTotal already counted A[0]
	// Have to End before the last one A.size() -2, because leftTotal should not count the last one
	for (int i = 1; i < A.size() - 1; ++i)
	{
		leftTotal += A[i];
		rightTotal = total - leftTotal;
		long diff = std::abs(leftTotal - rightTotal);
		minDiff = std::min(diff, minDiff);
	}

	return minDiff;
}



int CodilityTest::PermCheck(vector<int> &A) 
{
	int result = 1;
	std::vector<int> checkAppearance(A.size());

	for (unsigned int i = 0; i < A.size(); i++) {
		checkAppearance[i] = false;
	}

	for (unsigned int i = 0; i < A.size(); i++) {
		// 1. A[i] should be larger than size()
		// 2. same value should not appear more than once
		// 3. cannot simply calculate sum, cause same value may appear more than once
		if (A[i] <= A.size() && checkAppearance[A[i] - 1] == false) {
			checkAppearance[A[i] - 1] = true;
		}
		else {
			result = 0;
			break;
		}
	}

	return result;
}



int CodilityTest::FrogRiverOne(int X, vector<int> &A) 
{
	if (A.size() < X)
		return -1;

	std::vector<bool> appeared(X);
	for (bool a : appeared)
		a = false;

	int curStep = 0;
	for (int curIndex = 0; curIndex < A.size(); ++curIndex)
	{
		appeared[A[curIndex] - 1] = true;
		if (A[curIndex] == curStep + 1)
		{
			curStep += 1;

			for (int step = curStep + 1; step <= X; ++step)
			{
				if (appeared[step - 1] == true)
					curStep = step;
				else
					break;
			}

			if (curStep == X)
				return curIndex;
		}
	}

	return -1;
}
