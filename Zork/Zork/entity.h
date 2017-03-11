#ifndef ENTITY_H
#define ENTITY_H

#include "globals.h"
#include <string>
#include <list>


class Entity
{
	
public:
	
	Entity(Type type, const char *name, const char *description, std::list<Entity*> &list);
	virtual ~Entity();

	Type type;
	const char *name;
	const char *description;
	std::list<Entity*> &contains;
};


#endif // end ENTITY_H