#include "world.h"
#include <iostream>

void World::Init()
{
	//Create game objects
}

void World::Start()
{
	//Initial message
}

ReturnState World::Update()
{
	ReturnState ret = ReturnState::CONTINUE;
	//Receive Input and make player execute actions
	memset(input, '\0', sizeof(input)/sizeof(char));
	memset(command, '\0', sizeof(command) / sizeof(char));
	printf(">");
	int i = 0;
	char c = ' ';

	while ('\n' != (c = getchar()))
	{
		input[i] = c;
		i++;
	}

	ParseInput(input, command);
	


	return ret;
}