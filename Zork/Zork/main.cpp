#include "globals.h"
#include "world.h"
#include <iostream>

int main() 
{
	World *world = new World();
	world->Init();
	world->Start();
	ReturnState ret = ReturnState::CONTINUE;

	while (ret == ReturnState::CONTINUE || ret == ReturnState::RESTART)
	{	
		if (ret == ReturnState::CONTINUE)
		{
			ret = world->Update();
		}
		if (ret == ReturnState::RESTART)
		{
			world->Start();
			ret = ReturnState::CONTINUE;
		}
	}
	
	if (ret == ReturnState::QUIT)
	{
		std::cout << "Thanks for Playing Dan Zork\n" << std::endl;
		world->CleanUp();
	}
	if (ret == ReturnState::ERROR)
		std::cout << "Error" << std::endl;

	if (ret == ReturnState::ENDGAME)
	{
		std::cout << "At last you are free. Good job!" << std::endl;
		world->CleanUp();
	}

	
	return 0;
}
	
