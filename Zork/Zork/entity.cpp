#include "entity.h"

Entity::Entity(
	Type type, 
	const char *name,
	const char *desc,
	std::list<Entity*> &list) : type(type), name(name), description(desc), contains(list) {}

Entity::~Entity()
{
	if (contains.size() != 0)
		contains.clear();
}

