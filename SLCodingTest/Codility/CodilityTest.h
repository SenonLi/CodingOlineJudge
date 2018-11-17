#pragma once
class CodilityTest
{
public:
	CodilityTest();

	int GetMaxBinaryGap(int N);

private:
	int GetNextBinaryGap(int& N);
};

