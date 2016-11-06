#include "globals.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
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
	}

	return 0;
}