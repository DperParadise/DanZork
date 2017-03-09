#include "entity.h"


Entity::Entity() {}

Entity::Entity(
	Type type, 
	const std::string &name, 
	const std::string &desc,
	std::list<Entity*> list) : type(type), name(name), description(desc), contains(list) {}

Entity::~Entity()
{
	for (std::list<Entity*>::iterator it = contains.begin(); it != contains.end(); it++)
	{
		RELEASE(*it);
	}

	contains.clear();
}

