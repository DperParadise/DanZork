#include "player.h"

Player::Player(
	ptrRoom loc,
	Type type,
	std::string name,
	std::string desc, 
	std::list<ptrEntity> list, 
	ptrRoom prevRoom, 
	int lives,
	int score=0) : previousRoom(prevRoom), lives(lives), score(score), Creature(loc, type, name, desc, list) {}