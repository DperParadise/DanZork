#ifndef ROOM_H
#define ROOM_H

#include "entity.h"
#include <string>
#include <memory>
#include <list>



class Room : public Entity
{
public:

	Room(Type type, const std::string &name, const std::string &desc, std::list<ptrEntity> &&list);	

};





#endif // !ROOM_H

