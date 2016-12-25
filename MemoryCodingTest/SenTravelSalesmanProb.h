#pragma once

#ifndef __SenTravelSalesmanProb__
#define __SenTravelSalesmanProb__

#include <vector>
#include <iostream>

class SenTravelSalesmanProb
{
public:
	SenTravelSalesmanProb();
	virtual ~SenTravelSalesmanProb();

	void bruteForceLeastCost();

private:
	std::vector<int> totalTravelVector;
	int totalTravel = 0;

	int countLoop_1 = 0, countLoop_2 = 0, countLoop_3 = 0, countLoop_4 = 0, countLoop_5 = 0, countLoop_6 = 0;
	int firstCity = 0, secondCity = 0, thirdCity = 0, fourthCity = 0, fifthCity = 0, sixthCity = 0, lastCity = 0;
	int firstCity_SS, secondCity_SS, thirdCity_SS, fourthCity_SS, fifthCity_SS, sixthCity_SS, lastCity_SS;
	int minTotalTravel = 99999999;


	int data[7][7];


};



#endif // __SenTravelSalesmanProb__
