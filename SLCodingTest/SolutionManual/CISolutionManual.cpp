#include "../pch.h"
#include "CISolutionManual.h"
#include <iostream>


CISolutionManual::CISolutionManual()
{
}

/*
Write a function that iterates over the numbers 1 through 100. If the number is divisible by 3, output
"Fizz". If the number is divisible by 5, output "Buzz". If the number is divisible by both 3 and 5, output
"FizzBuzz". If the number is divisible by none of these, output the number.
*/
void CISolutionManual::FizzBuzz()
{
	for (int i = 1; i <= 100; ++i)
	{
		if (i % 3 == 0 && i % 5 == 0)
			std::cout <<"Num: " << i << "\t FizzBuzz \n";
		else if (i % 3 == 0)
			std::cout << "Num: " << i << "\t Fizz \n";
		else if (i % 5 == 0)
			std::cout << "Num: " << i << "\t Buzz \n";
	}
}
