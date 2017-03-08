#ifndef ENTITY_H
#define ENTITY_H

#include "globals.h"
#include <string>
#include <list>


class Entity
{
	
public:
	
	Entity();
	Entity(Type type, const std::string &name, const std::string &description, std::list<Entity*> list);
	virtual ~Entity();

	Type type;
	std::string name;
	std::string description;
	std::list<Entity*> contains;
};


#endif // end ENTITY_H