#include "SenTravelSalesmanProb.h"


SenTravelSalesmanProb::SenTravelSalesmanProb()
{
	int tmpData[7][7] = {
		{ 0, 415, 20, 894, 340, 680, 110 },
		{ 415, 0, 29, 654, 140, 718, 243 },
		{ 20, 29, 0, 318, 914, 138, 14 },
		{ 894, 654, 318, 0, 683, 512, 890 },
		{ 340, 140, 917, 683, 0, 279, 414 },
		{ 680, 718, 138, 512, 279, 0, 659 },
		{ 110, 243, 14, 890, 414, 659, 0 }
	};

	for (int i = 0; i < 7; i++)	{
		for (int j = 0; j < 7; j++)	{
			data[i][j] = tmpData[i][j];
		}
	}

}


SenTravelSalesmanProb::~SenTravelSalesmanProb()
{
}

void SenTravelSalesmanProb::bruteForceLeastCost()	{

	int traverseSign_1[7] = { 0, 1, 1, 1, 1, 1, 1 };
	int fixedSign_1[7] = { 0, 1, 1, 1, 1, 1, 1 };

	int index_1;
	int totalTravel = 0;

	do{// step 1
		countLoop_1++;

		index_1 = 0;
		while (traverseSign_1[index_1] == 0 && index_1 < 6)	index_1++;
		firstCity = index_1;
		traverseSign_1[index_1] = 0;


		//*******************************************************************************
		int traverseSign_2[7], fixedSign_2[7];
		for (int i = 0; i < 7; i++)	{
			traverseSign_2[i] = fixedSign_1[i];  fixedSign_2[i] = fixedSign_1[i];
		}
		traverseSign_2[index_1] = 0; fixedSign_2[index_1] = 0;
		int index_2;
		countLoop_2 = 0;
		//*******************************************************************************

		do{//step 2
			countLoop_2++;

			index_2 = 0;
			while (traverseSign_2[index_2] == 0 && index_2 < 6)	index_2++;
			secondCity = index_2;
			traverseSign_2[index_2] = 0;

			//*******************************************************************************
			int traverseSign_3[7], fixedSign_3[7];
			for (int i = 0; i < 7; i++)	{
				traverseSign_3[i] = fixedSign_2[i];  fixedSign_3[i] = fixedSign_2[i];
			}
			traverseSign_3[index_2] = 0; fixedSign_3[index_2] = 0;
			int index_3;
			countLoop_3 = 0;
			//*******************************************************************************

			do{// step 3
				countLoop_3++;

				index_3 = 0;
				while (traverseSign_3[index_3] == 0 && index_3 < 6)	index_3++;
				thirdCity = index_3;	traverseSign_3[index_3] = 0;

				//*******************************************************************************
				int traverseSign_4[7], fixedSign_4[7];
				for (int i = 0; i < 7; i++)	{
					traverseSign_4[i] = fixedSign_3[i];  fixedSign_4[i] = fixedSign_3[i];
				}
				traverseSign_4[index_3] = 0; fixedSign_4[index_3] = 0;
				int index_4;
				countLoop_4 = 0;
				//*******************************************************************************

				do{// step 4
					countLoop_4++;

					index_4 = 0;
					while (traverseSign_4[index_4] == 0 && index_4 < 6)	index_4++;
					fourthCity = index_4;	traverseSign_4[index_4] = 0;

					//*******************************************************************************
					int traverseSign_5[7], fixedSign_5[7];
					for (int i = 0; i < 7; i++)	{
						traverseSign_5[i] = fixedSign_4[i];  fixedSign_5[i] = fixedSign_4[i];
					}
					traverseSign_5[index_4] = 0; fixedSign_5[index_4] = 0;
					int index_5;
					countLoop_5 = 0;
					//*******************************************************************************

					do{// step 5
						countLoop_5++;

						index_5 = 0;
						while (traverseSign_5[index_5] == 0 && index_5 < 6)	index_5++;
						fifthCity = index_5;	traverseSign_5[index_5] = 0;


						//*******************************************************************************
						int traverseSign_6[7], fixedSign_6[7];
						for (int i = 0; i < 7; i++)	{
							traverseSign_6[i] = fixedSign_5[i];  fixedSign_6[i] = fixedSign_5[i];
						}
						traverseSign_6[index_5] = 0; fixedSign_6[index_5] = 0;
						int index_6;
						countLoop_6 = 0;
						//*******************************************************************************

						do{ // step 6, last city before going back
							countLoop_6++;

							index_6 = 0;
							while (traverseSign_6[index_6] == 0 && index_6 < 6)	index_6++;
							sixthCity = index_6;	traverseSign_6[index_6] = 0;




							lastCity = sixthCity;

							totalTravel = data[0][firstCity] + data[firstCity][secondCity] + data[secondCity][thirdCity]
								+ data[thirdCity][fourthCity] + data[fourthCity][fifthCity] + data[fifthCity][sixthCity]
								+ data[lastCity][0];
							totalTravelVector.push_back(totalTravel);

							if (totalTravel < minTotalTravel)	{
								firstCity_SS = firstCity; secondCity_SS = secondCity; thirdCity_SS = thirdCity;
								fourthCity_SS = fourthCity; fifthCity_SS = fifthCity; sixthCity_SS = sixthCity;
								lastCity_SS = lastCity;
								minTotalTravel = totalTravel;
							}
							std::cout << "countLoop_5 = " << countLoop_5 << ",     countLoop_6 = " << countLoop_6 << std::endl;







						} while (traverseSign_6[1] == 1 || traverseSign_6[2] == 1 || traverseSign_6[3] == 1
							|| traverseSign_6[4] == 1 || traverseSign_6[5] == 1 || traverseSign_6[6] == 1);

					} while (traverseSign_5[1] == 1 || traverseSign_5[2] == 1 || traverseSign_5[3] == 1
						|| traverseSign_5[4] == 1 || traverseSign_5[5] == 1 || traverseSign_5[6] == 1);

				} while (traverseSign_4[1] == 1 || traverseSign_4[2] == 1 || traverseSign_4[3] == 1
					|| traverseSign_4[4] == 1 || traverseSign_4[5] == 1 || traverseSign_4[6] == 1);


			} while (traverseSign_3[1] == 1 || traverseSign_3[2] == 1 || traverseSign_3[3] == 1
				|| traverseSign_3[4] == 1 || traverseSign_3[5] == 1 || traverseSign_3[6] == 1);

		} while (traverseSign_2[1] == 1 || traverseSign_2[2] == 1 || traverseSign_2[3] == 1
			|| traverseSign_2[4] == 1 || traverseSign_2[5] == 1 || traverseSign_2[6] == 1);

	} while (traverseSign_1[1] == 1 || traverseSign_1[2] == 1 || traverseSign_1[3] == 1
		|| traverseSign_1[4] == 1 || traverseSign_1[5] == 1 || traverseSign_1[6] == 1);





	std::cout << "Total City Number: " << lastCity + 1 << std::endl;
	std::cout << "Total Options Num: " << totalTravelVector.size() << std::endl;
	std::cout << "Min Total Travel: " << data[0][firstCity_SS] << " ( 0 -> " << firstCity_SS << ") + "
		<< data[firstCity_SS][secondCity_SS] << " ( " << firstCity_SS << " -> " << secondCity_SS << " ) + "
		<< data[secondCity_SS][thirdCity_SS] << " ( " << secondCity_SS << " -> " << thirdCity_SS << " ) + "
		<< data[thirdCity_SS][fourthCity_SS] << " ( " << thirdCity_SS << " -> " << fourthCity_SS << " ) + "
		<< data[fourthCity_SS][fifthCity_SS] << " ( " << fourthCity_SS << " -> " << fifthCity_SS << " ) + "
		<< data[fifthCity_SS][sixthCity_SS] << " ( " << fifthCity_SS << " -> " << sixthCity_SS << " ) + "

		<< data[lastCity_SS][0] << " ( " << lastCity_SS << " -> 0)" << " = " << minTotalTravel << std::endl;



	// Least : 0->2->5->4->1->6->0 = 1622

}