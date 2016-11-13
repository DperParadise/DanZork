#include "player.h"

Player::Player(
	ptrRoom loc,
	ptrParentItem parentItem,
	Type type,
	std::string name,
	std::string desc, 
	std::list<ptrEntity> list, 
	ptrRoom prevRoom, 
	int lives,
	int score) : previousRoom(prevRoom), lives(lives), score(score), Creature(loc, parentItem, type, name, desc, list) {}