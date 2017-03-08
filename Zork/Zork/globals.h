#ifndef GLOBALS_H
#define GLOBALS_H

void ParseInput(const char *input, char *output);

enum class Type { NPC, PLAYER, EXIT, ROOM, ITEM };

enum class Direction { NORTH, EAST, SOUTH, WEST };

enum class Scenario {
	CELL,
	AISLE,
	WARDROBE,
	MAIN_HALL,	
};

enum class ReturnState {
	CONTINUE,
	RESTART,
	QUIT,
	ENDGAME,
	ERROR
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
