#pragma once
class CodilityTest
{
public:
	CodilityTest();

	// Find longest sequence of zeros in binary representation of an integer
	int GetMaxBinaryGap(int N);

private:
	int GetNextBinaryGap(int& N);
};

