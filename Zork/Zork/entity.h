#ifndef ENTITY_H
#define ENTITY_H

#include "globals.h"
#include <string>
#include <list>
#include <memory>



class Entity
{
	
public:
	typedef std::shared_ptr<Entity> ptrEntity;
	
	Entity();
	Entity(Type type, const std::string &name, const std::string &description, std::list<ptrEntity> &&list);
	virtual ~Entity();


	Type type;
	std::string name;
	std::string description;
	std::list<ptrEntity> contains;
};


#endif // end ENTITY_H