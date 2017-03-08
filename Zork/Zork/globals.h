#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>
#include <algorithm>
#include <vector>
#include <memory>


void ParseInput(const char *input, char *output);
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
	QUIT,
	FREEDOM
};

enum HitArea {
	HEAD,
	LEFT_ARM,
	RIGHT_ARM,
	TORSE,
	LEFT_LEG,
	RIGHT_LEG
};

enum class GoDirection {
	OK,
	CLOSED,
	NO_WAY,
	FREEDOM
};

enum class ItemSize {
	EXTRA_SMALL,
	SMALL,
	MEDIUM,
	LARGE,
	EXTRA_LARGE
};

#define RELEASE(x) if(x != nullptr) {delete x; x = nullptr;}

#endif //end GLOBALS_H
