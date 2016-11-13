#include "creature.h"
#include "globals.h"

Creature::Creature(
	ptrRoom location,
	Type type,
	std::string name,
	std::string desc,
	std::list<ptrEntity> list) : location(location), Entity(type, name, desc, list) {}

Creature::~Creature() {}