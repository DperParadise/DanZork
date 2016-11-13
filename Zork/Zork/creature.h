#ifndef CREATURE_H
#define CREATURE_H

#include "entity.h"
#include "room.h"
#include <memory>



class Creature : public Entity
{
	
public:

	typedef std::shared_ptr<Room> ptrRoom;
	
	Creature(ptrRoom location, Type type, std::string name, std::string desc, std::list<ptrEntity> list);
	virtual ~Creature();

	ptrRoom location;
	int hp;
	int defense;
	int attack;
};


#endif // !CREATURE_H
