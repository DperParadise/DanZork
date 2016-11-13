#ifndef PLAYER_H
#define PLAYER_H
#include "creature.h"

class Player : public Creature
{
public:

	Player(ptrRoom loc, ptrParentItem parentItem, Type type, std::string name, std::string desc, std::list<ptrEntity> list, ptrRoom prevRoom, int lives, int score);

	int score;
	int lives;
	ptrRoom previousRoom;
	
};



#endif
