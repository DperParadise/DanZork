#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>
#include <algorithm>
#include <vector>
#include <memory>


void ParseInput(const std::string &inputString, std::vector<std::string> &inputWordsVector);
std::string ToUpper(std::string s1);


enum class Type { NPC, PLAYER, EXIT, ROOM, ITEM, WEAPON, ARMOR };

enum class Direction { NORTH, EAST, SOUTH, WEST };

enum class Scenario {
	CELL,
	AISLE1,
	AISLE2,
	AISLE3,
	ARMORY,
	GUARDROOM,
	TOOLROOM,
	UPSTAIRS,
	GUARDS_BEDROOM,
	MEETINGS_ROOM,
	MAIN_HALL,
	MAIN_HALL_EXIT,
	CELL_EXIT
};

extern Scenario scenarioGlobal;

enum class ReturnState {
	STAY,
	NEXT_ROOM,
	ERROR,
	QUIT
};


#endif //end GLOBALS_H
