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

bool Sen_StringArrayTop10::isPalindrome(std::string str, int low, int high)
{
	while (low < high)
	{
		if (str[low] != str[high])
			return false;
		low++;
		high--;
	}
	return true;
}

void Sen_StringArrayTop10::allPalPartUtil(std::vector<std::vector<std::string> > &allPart
	, std::vector<std::string> &currPart,	int start, int n, std::string str)
{
	// If 'start' has reached len
	if (start >= n)
	{
		allPart.push_back(currPart);
		return;
	}

	// Pick all possible ending points for substrings
	for (int i = start; i<n; i++)
	{
		// If substring str[start..i] is palindrome
		if (isPalindrome(str, start, i))
		{
			// Add the substring to result (one push, one pop, to make currPart alive)
			currPart.push_back(str.substr(start, i - start + 1));

			// Recur for remaining remaining substring
			allPalPartUtil(allPart, currPart, i + 1, n, str);

			// Remove substring str[start..i] from current 
			// (one push, one pop, to make currPart alive)
			currPart.pop_back();
		}
	}
}

void Sen_StringArrayTop10::allPalPartitions(std::string str)
{
	int n = str.length();

	// To Store all palindromic partitions
	std::vector<std::vector<std::string> > allPart;

	// To store current palindromic partition
	std::vector<std::string> currPart;

	// Call recursive function to generate all partiions
	// and store in allPart
	allPalPartUtil(allPart, currPart, 0, n, str);

	// Print all partitions generated by above call
	for (int i = 0; i< allPart.size(); i++)
	{
		for (int j = 0; j<allPart[i].size(); j++)
			std::cout << allPart[i][j] << " ";
		std::cout << "\n";
	}
}