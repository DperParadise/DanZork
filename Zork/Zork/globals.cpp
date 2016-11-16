#include "globals.h"
#include <memory>

 
void ParseInput(const std::string &inputString, std::vector<std::string> &inputWordsVector) 
{
	bool processingWords = false;
	size_t parsedChars = 0;

	const char *begin = inputString.c_str();
	const char *end = inputString.c_str();
	size_t inputLength = inputString.length();

	while (parsedChars <= inputLength && inputLength != 0)
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
				inputWordsVector.push_back(std::string(begin, end));
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