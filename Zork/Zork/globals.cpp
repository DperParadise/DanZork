#include "globals.h"

void ParseInput(const string &inputString, vector<string> &inputWordsVector) 
{
	size_t currentWord = 1;
	bool processingWords = false;
	size_t parsedChars = 0;

	//auto begin = inputString.cbegin();
	//auto end = inputString.cbegin();

	const char *begin = inputString.c_str();
	const char *end = inputString.c_str();

	while (parsedChars <= inputString.length() && inputString.length() != 0)
	{
		if (*end != ' ' && *end !='\0')
		{
			processingWords = true;
			++end;
		}
		else
		{	// we have read one word
			if (processingWords)
			{
				inputWordsVector.push_back(string(begin, end));
				processingWords = false;
				++end;
				begin = end;
			}
			else {
				++begin;
				++end;
			}		
		}
		
		++parsedChars;
	}
}