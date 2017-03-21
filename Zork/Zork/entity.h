#ifndef ENTITY_H
#define ENTITY_H

#include "globals.h"
#include <string>
#include <list>

class Observer;
class Entity
{
	
public:
	
	Entity(Type type, const char *name, const char *description, std::list<Entity*> &list);
	virtual ~Entity();

	Type type;
	const char *name;
	const char *description;
	std::list<Entity*> &contains;

//Observer
private:
	Observer *observer;
public:	
	void RegisterObs(Observer *obs);
	bool NotifyObs();
};


#endif // end ENTITY_H