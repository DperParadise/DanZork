#include "room.h"
#include "entity.h"
Room::Room(
	Type type,
	const char *name,
	const char *desc,
	std::list<Entity*> &list) : Entity(type, name, desc, list) {}