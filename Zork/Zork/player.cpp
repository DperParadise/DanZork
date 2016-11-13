#include "player.h"

Player::Player(
	ptrRoom loc,
	Type type,
	std::string name,
	std::string desc, std::list<ptrEntity> list) : Creature(loc, type, name, desc, list) {}