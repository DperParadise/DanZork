#include "creature.h"
#include "globals.h"

Creature::Creature(
	ptrRoom location,
	ptrParentItem parentItem,
	Type type,
	std::string name,
	std::string desc,
	std::list<ptrEntity> list) : location(location), parentItem(parentItem), Entity(type, name, desc, list) {}

Creature::~Creature() {}