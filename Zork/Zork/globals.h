#ifndef GLOBALS_H
#define GLOBALS_H

void TrimInput(const char *input, char *output);
void ToLower(const char *input, char *output);

enum Type { ENEMY, PLAYER, EXIT, ROOM, ITEM };

enum Direction { NORTH, EAST, SOUTH, WEST };

enum ReturnState {
	CONTINUE,
	RESTART,
	QUIT,
	ENDGAME,
	ERROR
};


enum ItemSize {
	SMALL,
	MEDIUM,
	LARGE	
};

#define RELEASE(x) if(x != nullptr) {delete x; x = nullptr;}


#endif //end GLOBALS_H
