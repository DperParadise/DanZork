#include "globals.h"
#include "application.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

using namespace std;

int main() 
{
	
	Scenario scenario = Scenario::START;
	bool play = true;
	std::unique_ptr<Application> ptrApp(new Application);
	
	ptrApp->Init();

	while (play)
	{
		switch (scenario)
		{
		case Scenario::START:
			std::cout << "Hello World!\n";
		}
	}
	









	/*
	string input;
	vector<string> wordsVector;
	
	cout << "> ";
	getline(cin, input);

	if (input.length() == 0)
	{
		cout << "Cadena vacia" << endl;
	}
	else
	{
		ParseInput(input, wordsVector);
	}

	for (const auto &elem : wordsVector) {
		cout << elem << endl;
	}*/

	return 0;
}