#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <algorithm> 
//#include <stdio.h>
//#include <stdlib.h>

using namespace std;

void printLastKLines(string fileName, int k){
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

int main(){
	string fileName = "ReadMe.txt";
	int k = 10;
	printLastKLines(fileName, k);

	getchar();
	return 0;
}

