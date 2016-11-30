
#include <string>
//#include <stdio.h>
//#include <stdlib.h>
#include <iostream>

//using namespace std;


//#include "ArchieMD_Test/Manager.h"
//#include "CTCI/Sen_Ch12_CppTest.h"
//#include "GeeksforGeeks/Sen_StringArrayTop10.h"
//#include "GeeksforGeeks/Sen_LinkedListTop10.h"

class FARO_Solution	{

public:
	void setTotal_N()	{
		do{
			std::cout << "Please input integer N (must be larger than 1) : ";
			std::cin >> total_N;
		} while (total_N <= 1);
	}

	void setScratch_X()	{
		do{
			std::cout << "Please input interger X (must be smaller than N) : ";
			std::cin >> scratch_X;
		} while (scratch_X >= total_N);
	}

	float getWinProbab();

private:
	int total_N;
	int scratch_X;
	float winProbab;
};


float FARO_Solution::getWinProbab()	{

	//if (total_N < 2) return -1.1;
	//else if (scratch_X >= total_N) return -2.1;

	float winProbab = 0;
	float continueProbab = 1.0;
	int leftBucketsNum = total_N;


	for (int i = 1; i <= scratch_X; i++)	{
		winProbab += continueProbab * (1 / static_cast<float>(leftBucketsNum));
		continueProbab *= 1 - (2 / static_cast<float>(leftBucketsNum));
		leftBucketsNum--;
	}

	return winProbab;
}

int main(){


	FARO_Solution ss;
	//while (1)	{
	ss.setTotal_N();
	ss.setScratch_X();
	std::cout << "Win Probability: " << ss.getWinProbab() << std::endl;
	//};




	//Sen_StringArrayTop10 stringArrayObject;
	//stringArrayObject.showAlphabetStringReverse();
	//stringArrayObject.allPalPartitions(string("nitin"));

	//mainManager();



	getchar();
	getchar();
	return 0;
}

