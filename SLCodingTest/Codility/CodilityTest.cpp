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



vector<int> CodilityTest::MaxCounters(int N, vector<int> &A)
{
	std::vector<int> counters(N);
	for (int cc : counters)
		cc = 0;

	int maxCounter = 0; // Actuall max
	int generalMax = 0; // to be applied to all at the end
	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] <= N)
		{
			// Apply generalMax first, then increase
			counters[A[i] - 1] = std::max(generalMax, counters[A[i] - 1]);
			counters[A[i] - 1] += 1;
			maxCounter = std::max(maxCounter, counters[A[i] - 1]);
		}
		else
		{
			// To avoid to many times of MaxCounters, we only do general Max at the end using max
			generalMax = maxCounter;
		}
	}

	for (int& cc : counters)
		cc = std::max(generalMax, cc);

	return counters;
}


int CodilityTest::MissingInteger(vector<int> &A)
{
	int result = 1;
	std::vector<bool> appear(A.size());
	int positiveCount = 0;

	for (bool aa : appear)
		aa = false;

	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] > 0) {
			if (A[i] <= A.size() && appear[A[i] - 1] == false) {
				positiveCount++;
				appear[A[i] - 1] = true;
			}
		}
	}

	bool allPositive = true;
	for (int i = 0; i < positiveCount; ++i)
	{
		if (!appear[i]) {
			result = i + 1;
			allPositive = false;
			break;
		}
	}

	// Below is important!!
	if (allPositive && positiveCount <= A.size())
		result = positiveCount + 1;
	return result;
}

int CodilityTest::PerfectSquare(int A, int B)
{
		if (B < 0)
			return 0;

		int start = 0;
		int end = B;
		if (A > 0) {
			start = A;
		}

		return std::floor(std::sqrt(end)) - std::ceil(std::sqrt(start)) + 1;
}


int CodilityTest::DecimalSubString(int A, int B)
{
	std::string aa = std::to_string(A);
	std::string bb = std::to_string(B);

	std::size_t foundIndex = bb.find(aa);
	if (foundIndex != std::string::npos)
		return foundIndex;
	else
		return -1;
}

/*
Array A contains only 0s and/or 1s:

0 represents a car traveling east,
1 represents a car traveling west.
The goal is to count passing cars. 

We say that a pair of cars (P, Q), where 0 ¡Ü P < Q < N, is passing when P is traveling to the east and Q is traveling to the west.

This can be improved to O(N) as follows: 
If we encounter a car going west (a 1), we know that it passes with every car before it that was going east (a 0).
By keeping track of how many cars going east we¡¯ve seen so far, we can easily compute the total number of passing cars.
*/
int CodilityTest::PassingCars(vector<int> &A)
{
	int eastCount = 0;
	int passingCount = 0;

	for (int i : A) {
		if (i == 0)
			eastCount++;
		else if (i == 1)
			passingCount += eastCount;

		if (passingCount > 1000000000)
			return -1;
	}

	return passingCount;
}


/*
Genomic Range Query

The optimal idea is to keep a prefix sum of the number of occurences of each letter from the set [G,C,T,A] for every position in the target string. 
Then, to evalute the minimal nucleotide between indices (a,b), 
we can easily compute the total number of occurences of each of the nucleotides in O(1) time, and pick the smallest one.
This leads to a total running time of O(N+M).

	std::vector<int> testVecP = { 2, 5, 0 };
	std::vector<int> testVecQ = { 4, 5, 6 };
	std::string S = "CAGCCTA";

	std::vector<int> result = test.GenomicRangeQuery(S, testVecP, testVecQ);

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << "  ";
Output:
	2	4	1
*/
vector<int> CodilityTest::GenomicRangeQuery(string &S, vector<int> &P, vector<int> &Q)
{
	vector<int> occurA(S.length());
	vector<int> occurC(S.length());
	vector<int> occurG(S.length());

	int countA = 0;
	int countC = 0;
	int countG = 0;

	for (int i = 0; i < S.length(); ++i) {
		if (S[i] == 'A')
			countA++;
		else if (S[i] == 'C')
			countC++;
		else if (S[i] == 'G')
			countG++;

		occurA[i] = countA;
		occurC[i] = countC;
		occurG[i] = countG;
	}

	vector<int> result(P.size());
	for (int i = 0; i < P.size(); ++i) {
		char letterP = S[P[i]];
		if (letterP == 'A'	|| occurA[Q[i]] > occurA[P[i]] )
			result[i] = 1;
		else if (letterP == 'C'	|| occurC[Q[i]] > occurC[P[i]])
			result[i] = 2;
		else if (letterP == 'G'	|| occurG[Q[i]] > occurG[P[i]])
			result[i] = 3;
		else 
			result[i] = 4;
	}

	return result;
}

/*
We only need to check slices of size 2 and 3 as the min average should be in the those sub-slices.
For proof, see SLCodingTest\Codility\MinAvgTwoSlice_Proof.pdf written by Minh Tran Dao.

More interesting proof: https://codesays.com/2014/solution-to-min-avg-two-slice-by-codility/

*/
int CodilityTest::MinAvgTwoSlice(vector<int> &A)
{
	int minPosition = 0;
	double minAverage = (A[0] + A[1]) / 2.0;
	// Will compare the average of A[i] and A[i+1] with minAverage
	// Attension: the beginning of i must be 0 instead of 1
	//  because the initial of minAverage did not consider first 3-element average calculation
	for (int i = 0; i < A.size() - 1; ++i) {
		if (minAverage > ((A[i] + A[i + 1]) / 2.0))
		{
			minAverage = (A[i] + A[i + 1]) / 2.0;
			minPosition = i;
		}

		// Will compare the average of A[i], A[i+1] and A[i+2] with minAverage
		if ((i < A.size() - 2) 
			&& minAverage > ((A[i] + A[i + 1] + A[i + 2]) / 3.0))
		{
			minAverage = (A[i] + A[i + 1] + A[i + 2]) / 3.0;
			minPosition = i;
		}
	}

	return minPosition;
}

/*
0 is divisible by any positives.
(0 / N) == 0

*/
int CodilityTest::CountDiv(int A, int B, int K)
{
	// 1. There are N = (B - A) numbers of integers to be consider;
	// 2. There must be (N / K) or (N / K + 1) integers could be divisible;
	// 3. The hard point is to determine whether (N / K) or (N / K + 1);
	// 4. Easy to determine if (A % K == 0);
	// 5. if (A % K != 0), we move A to the closest larger one, but smaller than B.

	if (A % K == 0) {
		// A==0 also be covered in this block!!
		return (B - A) / K + 1;
	}
	else {
		int newA = (A / K + 1) * K;
		if (newA > B)
			return 0;
		else
			return (B - newA) / K + 1;
	}
}

/*
https://www.martinkysel.com/codility-distinct-solution/

Complexity:
Time complexity is O(N * log(N));
Space complexity is O(N)

Using C++, the std set is a Red-Black Tree,
and therefore has insertion complexity of log N. (overall N log N)

*/
#include <set>

int CodilityTest::Distinct(vector<int> &A) {
	set<int> orderedSet;
	for (auto i : A) {
		orderedSet.insert(i);
	}

	return orderedSet.size();
}



/*
By sorting the array, we have guaranteed that P+R > Q and Q+R > P 
(because R is always the biggest).
Now what remains, is the proof that P+Q > R, that can be found out by traversing the array.
The chance to find such a combination is with three adjacent values as they provide the highest P and Q.

std::sort is most likely to use QuickSort, or at least a variation over QuickSort called IntroSort,
which "degenerates" to HeapSort when the recursion goes too deep.

std::stable_sort is most likely to use MergeSort, because of the stability requirement.
However note that MergeSort requires extra space in order to be efficient.
*/
#include <algorithm>

int CodilityTest::Triangle(vector<int> &A)
{

	if (A.size() < 3)
		return 0;

	std::stable_sort(A.begin(), A.end());
	for (int i = 0; i < A.size() - 2; ++i) {
		// Need to use minus instead of A[i] + A[1] > A[2] in case of overflow
		if (A[i] > 0 && A[i] > A[i + 2] - A[i + 1])
			return 1;
	}

	return 0;
}

/*
 time complexity: O(N * log(N))
*/
#include <algorithm>

int CodilityTest::MaxProductOfThree(vector<int> &A)
{
	// sort in decending order
	std::sort(A.begin(), A.end(), std::greater<int>());

	if (A[0] < 0) {
		// all integers are negative, the product is nagetive;
		// chose the first three elements (e.g. -1, -2, -3)
		return A[0] * A[1] * A[2];
	}
	else if (A[0] == 0) {
		return 0;
	}
	else {
		// A[0] > 0, just compare first 3 and first multiple last two
		// Actually, this third case can also cover case A[0] < 0 and A[0] == 0
		return std::max(A[0] * A[A.size() - 1] * A[A.size() - 2], A[0] * A[1] * A[2]);
	}
}



/*
 Input: a vector of float values, size 0 <= N <= 1,000,000;   -250.0 <= A[i] <= 250.0
 return:
	1. find the max drop = A[i] - A[j], where 0 <= i < j <= N-1;
	2. if the values are monotonically increasing (no drop), return -1;

E.g.:
	A = [8, 2, 4, 1, 10, 7, 2]
	return 8 (= A[4] - A[6]) intead of 9, because i < j.
 */
int CodilityTest::MaxDrop(vector<float> A)
{
	if (A.size() < 2)
		return -1;

	float maxDrop = -250.0f;
	float curMax = A[0];

	for (int i = 1; i < A.size(); ++i) {

		if (A[i] >= curMax) {
			// update curMax, no update for maxDrop
			curMax = A[i];
		}
		else {
			// no update for curMax
			float newDrop = curMax - A[i];
			if (newDrop > maxDrop) {
				maxDrop = newDrop;
			}
		}
	}

	if (maxDrop == -250.0f) // No drop, monotonous increasing
		return -1;
	else
		return std::round(maxDrop);
}


/*
 The purpose of this function is to find the intersection between to 1D segments.
 Every segment: left, right
 Every intersection pair: 
 If seg_1.right >=seg_2.right, we could call seg_1 "rightSeg";
 Intersection Pair Condition:
      a. rightSeg.left <= leftSeg.right;
      b. rightSeg.right >= leftSeg.right;
 Basically, to find out whether two segments are intersected, we need rightSeg.right, rightSeg.left, and leftSeg.right. We don't need leftSeg.left because we count the intersectio no matter leftSeg is partially overlapped or entirely overlapped;
 Algorithm trick: 
        We only count the number, no need to log the index;
          we only need to compare sortedLeft[leftIndex] and sortedRight[rightIndex], and calculate "leftIndex - rightIndex - 1", no need to consider "Condition b", because all situations that doesn't apply "Condition b" has been deducted by "- rightIndex"; the end part of "- 1" is to make sure the rightSeg itself is not counted.

Example test:    [1, 5, 2, 1, 4, 0]
Expected Answer: 11

*/
#include <algorithm>
int CodilityTest::NumberOfDiscIntersections(vector<int> &A)
{
	if (A.size() < 2)
		return 0;

	// In case of overflow, lefts and rights must be long value instead of int value;
	// Attention: the index "i" in the for_loop was used to calculate lefts and rights, it must be type long instead of type int
	vector<long> lefts;
	vector<long> rights;
	for (int i = 0; i < A.size(); ++i) {
		lefts.push_back(static_cast<long>(i) - A[i]);
		rights.push_back(static_cast<long>(i) + A[i]);
	}

	std::sort(lefts.begin(), lefts.end());
	std::sort(rights.begin(), rights.end());

	int intersectionCount = 0;
	for (int leftIndex = 0, rightIndex = 0; rightIndex < A.size(); ++rightIndex) {
		// Traverse the sorted rights array, and count the intersections one by one
		while (leftIndex < A.size() && rights[rightIndex] >= lefts[leftIndex])
			++leftIndex;

		intersectionCount += leftIndex - rightIndex - 1;
		// Explanation:
		//      1. "leftIndex" contains all segments that apply "Condition a";
		//      2. "leftIndex - rightIndex" applied "Condition b";
		//      3. "- 1" makes sure that the curSeg itself was not counted.
		if (intersectionCount > 1e7)
			return -1;
	}

	return intersectionCount;

}

/*
S is empty;
S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, the string "{[()()]}" is properly nested but "([)()]" is not.
*/
#include <stack>
int CodilityTest::Brackets(string &S)
{
	if (S.empty())
		return 1;
	if (S.size() % 2 == 1 || S[0] == '}' || S[0] == ']' || S[0] == ')')
		return 0;

	std::stack<char> check;
	check.push(S[0]);
	for (int i = 1; i < S.length(); ++i) {
		if (S[i] == '{' || S[i] == '[' || S[i] == '(') {
			check.push(S[i]);
		}
		else if (S[i] == '}') {
			if (check.top() == '{')     check.pop();
			else        				return 0;
		}
		else if (S[i] == ']') {
			if (check.top() == '[')     check.pop();
			else        				return 0;
		}
		else if (S[i] == ')') {
			if (check.top() == '(')     check.pop();
			else        				return 0;
		}
	}

	// only empty means a match, otherwise, "{({[" would also pass
	return check.empty() ? 1 : 0;
}