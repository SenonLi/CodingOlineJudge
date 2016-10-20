#include <iostream>
#include <stack>
#include <vector>
#include <string>

#ifndef uint
#define uint unsigned int
#endif

using namespace std;


void printBinary(int num)	{
	vector<int> vecNum;
	uint uNum = uint(num);
	while (uNum != 0)	{
		if (uNum & 1)  vecNum.push_back(1);
		else 				 vecNum.push_back(0);
		uNum = uNum >> 1;
	}

	for (int i = vecNum.size() - 1; i >= 0; i--){
		cout << vecNum[i];
		if (i % 8 == 0) cout << " ";
	}

	cout << endl;
}

int insert(int n, int m, int i, int j)
{
	int mShifted = m << i;
	int nClearedLeft = -1 << (j + 1);
	int nClearedRight = (1 << i) - 1;
	int nMask = nClearedLeft | nClearedRight;
	int nCleared = n & nMask;
	return nCleared | mShifted;
}

int clearBitsIthough0(int num, int i)	{
	int mask = (-1) << (i + 1);
	num &= mask;
	return num;
}

string decimalToBinary(double decimal)	{
	string binaryOut = "";
	if (decimal >= 1 || decimal <= 0) return "ERROR";
	binaryOut += "0.";
	while (decimal > 0)	{
		if (binaryOut.length() > 31 + 2)
			return "ERROR";

		decimal *= 2;
		if (decimal >= 1)		{
			binaryOut += "1";
			decimal -= 1;
		}
		else	binaryOut += "0";
	};

	return binaryOut;
}

int main()
{
	//int N = 1024, M = 19, i = 2, j = 6;
	//int num = -1;
	//printBinary(N);
	//printBinary(M);
	//printBinary(insert(N, M, i, j));
	//printBinary(num);
	//printBinary(clearBitsIthough0(num, 3));
	//printBinary(clearBitsIthough0(num, 0));

	double decimal;
	cin >> decimal;
	cout << decimalToBinary(decimal);

	getchar();
	getchar();

	return 0;
}