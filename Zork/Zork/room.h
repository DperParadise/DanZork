#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <list>
#include "entity.h"

class Room : public Entity
{
public:

	Room(Type type, const std::string &name, const std::string &desc, std::list<Entity*> list);	

};





#endif // !ROOM_H

