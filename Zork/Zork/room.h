#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <list>
#include "entity.h"

class Room : public Entity
{
public:

	Room(Type type, const char *name, const char *desc, std::list<Entity*> &list);

};





#endif // !ROOM_H

