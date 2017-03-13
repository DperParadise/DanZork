#include "item.h"
#include "globals.h"

Item::Item(
	Room *loc,
	Entity *pnt,
	ItemSize size,
	bool isOpen,
	bool isContainer,
	bool isLocked,
	Type type,
	const char *name,
	const char *desc,
	std::list<Entity*> &list) : loc(loc), parent(pnt), size(size), isOpen(isOpen), isContainer(isContainer), isLocked(isLocked), Entity(type, name, desc, list) {}

Item::~Item(){}
