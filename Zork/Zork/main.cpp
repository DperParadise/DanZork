#include "globals.h"
#include "world.h"
//#include "literals.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

Scenario scenarioGlobal = Scenario::CELL;

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
		std::cout << "Thanks for Playing Dan Zork\n" << std::endl;
	if (ret == ReturnState::ERROR)
		std::cout << "Error" << std::endl;
	if (ret == ReturnState::ENDGAME)
		std::cout << "At last you are free. Good job!" << std::endl;

	RELEASE(world);

	return 0;
}
	
