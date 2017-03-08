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
	

	/*std::unique_ptr<World> ptrWorld = std::unique_ptr<World>(new World());
	ReturnState ret = ReturnState::STAY;
	ptrWorld->Init();
	
	while (ret != ReturnState::ERROR && ret != ReturnState::QUIT && ret != ReturnState::FREEDOM)
	{	
		ret = ptrWorld->Start();
		while (ret == ReturnState::STAY)
		{
			ret = ptrWorld->Update();

		}	
	}
	
	if (ret == ReturnState::QUIT)
		std::cout << "Thanks for Playing Danzork\n" << std::endl;
	if (ret == ReturnState::ERROR)
		std::cout << "Error" << std::endl;
	if (ret == ReturnState::FREEDOM)
		std::cout << "You enter the woods.\nAt last you are free. Good job!" << std::endl;*/

	char *input = "abc  def";
	char output[20];

	ParseInput(input, output);

	std::cout << output << std::endl;

	return 0;
}
	
