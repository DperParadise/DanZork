#include "globals.h"
#include <memory>
#include <ctype.h>
 
void ParseInput(const char *input, char *output)
{
	bool blank_read = true;
	int i = 0;
	int last_pos = 0;
	while (input[i] != '\0')
	{
		if (input[i] != ' ')
		{
			output[last_pos] = input[i];						
			blank_read = false;
			last_pos++;
		}
		else
		{
			if (!blank_read)
			{
				output[last_pos] = input[i];
				blank_read = true;
				last_pos++;
			}
		}
		i++;
	}
	//Add end of string character - needed only if it isn't provided in the input
	//if (output[last_pos - 1] == ' ')
	//	output[last_pos - 1] = '\0';
	//else
	//	output[last_pos] = '\0';
}

void ToUpper(const char *input, char *output)
{
	int i = 0;
	while (input[i] != '\0')
	{
		output[i] = toupper(input[i]);
		i++;
	}
	output[i] = '\0';
}



