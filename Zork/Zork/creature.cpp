#include "creature.h"
#include "globals.h"

Creature::Creature(
	ptrRoom location,
	int hp,
	int defense, 
	int attack,
	Type type,
	const std::string &name,
	const std::string &desc,
	std::list<ptrEntity> &&list) : location(location), hp(hp), defense(defense), attack(attack), Entity(type, name, desc, std::move(list)) {}

Creature::~Creature() {}