#include "room.h"
#include "entity.h"
Room::Room(
	Type type,
	const std::string &name,
	const std::string &desc,
	std::list<Entity*> &list) : Entity(type, name, desc, list) {}