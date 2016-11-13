#ifndef CREATURE_H
#define CREATURE_H

#include "entity.h"
#include "room.h"
#include "item.h"
#include <memory>



class Creature : public Entity
{
	
public:

	typedef std::shared_ptr<Room> ptrRoom;
	typedef std::shared_ptr<Item> ptrParentItem;
	
	Creature(ptrRoom location, ptrParentItem parentItem, Type type, std::string name, std::string desc, std::list<ptrEntity> list);
	virtual ~Creature();

	ptrRoom location;
	ptrParentItem parentItem;
	int hp;
	int defense;
	int attack;
};


#endif // !CREATURE_H

