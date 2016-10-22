#include "Sen_StringArrayTop10.h"


Sen_StringArrayTop10::Sen_StringArrayTop10()
{
}


Sen_StringArrayTop10::~Sen_StringArrayTop10()
{
}

void Sen_StringArrayTop10::reverseStringAlphabet(std::string &alphabetString)
{
	int head = 0, tail = alphabetString.length() - 1;
	char temp;
	while (head < tail)	{
		if (!isAlphabet(alphabetString[head]))	head++;		// locate a head alphabet;
		else if (!isAlphabet(alphabetString[tail]))	tail--;	// locate a tail alphabet;
		else {	// swap if already find both alphabets of on the head and on the tail
			temp = alphabetString[tail];
			alphabetString[tail--] = alphabetString[head];
			alphabetString[head++] = temp;
		}
	}
}

