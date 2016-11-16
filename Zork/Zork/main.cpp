#include "globals.h"
#include "world.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

Scenario scenarioGlobal = Scenario::CELL;

int main() 
{
	
	std::unique_ptr<World> ptrWorld = std::unique_ptr<World>(new World());
	ReturnState ret = ReturnState::STAY;
	ptrWorld->Init();
	
	while (ret != ReturnState::ERROR && ret != ReturnState::QUIT)
	{	
		switch (scenarioGlobal)
		{
		case Scenario::CELL:
			ret = ptrWorld->Start();
			while (ret == ReturnState::STAY)
			{
				ret = ptrWorld->Update();


				//getchar(); //wait
			}
			break;
		
		}
	}
	// Miro si salgo por un error o por Q
	if (ret == ReturnState::QUIT)
		std::cout << "Thanks for Playing Zorky\n" << std::endl;
	if (ret == ReturnState::ERROR)
		std::cout << "Error" << std::endl;

	return 0;
}
	
