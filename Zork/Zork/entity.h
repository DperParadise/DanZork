#ifndef ENTITY_H
#define ENTITY_H

#include "globals.h"
#include <string>
#include <list>

class Entity
{
public:
	Entity();
	Entity(Type t, std::string n, std::string d, std::list<Entity*> l);
	virtual ~Entity();

	Type type;
	std::string name;
	std::string description;
	std::list<Entity*> contains;
};


#endif // end ENTITY_H