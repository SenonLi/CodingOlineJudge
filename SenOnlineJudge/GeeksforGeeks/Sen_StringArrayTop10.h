#pragma once

#ifndef __Sen_StringArrayTop10__
#define __Sen_StringArrayTop10__

#include <string>
#include <iostream>

class Sen_StringArrayTop10
{
public:
	Sen_StringArrayTop10();
	virtual ~Sen_StringArrayTop10();

	void reverseStringAlphabet(std::string &alphabetString);

	void showAlphabetStringReverse()	{ 
		std::cout << "Input String:\t" << strReverseMe << std::endl;
		reverseStringAlphabet(strReverseMe);
		std::cout << "Output String:\t" << strReverseMe << std::endl;
	}


protected:

	std::string strReverseMe = "a!!!b.c.d,e'f,ghi";


	bool isAlphabet(char x){
		return ((x >= 'A' && x <= 'Z') || (x >= 'a' && x<= 'z'));
	}


};



#endif   // __Sen_StringArrayTop10__
