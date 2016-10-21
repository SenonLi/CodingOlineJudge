#include "Sen_Ch12_CppTest.h"


Sen_Ch12_CppTest::Sen_Ch12_CppTest()
{
}


Sen_Ch12_CppTest::~Sen_Ch12_CppTest()
{
}


void Sen_Ch12_CppTest::printLastKLines(int k, string fileName){
	ifstream inFile(fileName);

	if (inFile)	{
		string* linesArray = new string[k];
		int linesCount = 0;
		string tmp;

		while (getline(inFile, tmp)){
			linesArray[linesCount % k] = tmp;
			linesCount++;
		}

		int startIdx = linesCount > k ? (linesCount % k) : 0;
		int validLinesCount = min(k, linesCount);

		for (int i = 0; i < validLinesCount; ++i)
			cout << linesArray[(startIdx + i) % k] << endl;

		delete[] linesArray;
	}

	inFile.close();
}

