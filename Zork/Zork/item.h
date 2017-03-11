#ifndef ITEM_H
#define ITEM_H

#include "entity.h"

class Item : public Entity
{
public:

	Item(Entity *parentEntity, ItemSize size, bool isOpen, bool isContainer, bool isLocked, Type type, const char *name, const char *desc, std::list<Entity*> &list);
	virtual ~Item();

	Entity *parent;	
	bool isOpen;	
	bool isLocked;
	ItemSize size;
	bool isContainer;
};



#endif // !ITEM_H