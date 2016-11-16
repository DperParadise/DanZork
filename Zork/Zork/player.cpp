#include "player.h"

Player::Player(
	ptrRoom loc,
	int hp,
	int defense,
	int attack,
	Type type,
	const std::string &name,
	const std::string &desc,
	std::list<ptrEntity> &&list, 
	ptrRoom prevRoom, 
	int lives,
	int score) : previousRoom(prevRoom), lives(lives), score(score), Creature(loc, hp, defense, attack, type, name, desc, std::move(list)) {}