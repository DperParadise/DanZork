#ifndef EXIT_H
#define EXIT_H

#include "globals.h"
#include "entity.h"

class Entity;
class Room;
class Exit : public Entity
{
public:


	Exit(Direction location, Room *src, Room *dest, bool isOpen, Type type, const std::string &name, const std::string &desc, std::list<Entity*> list);
	~Exit();

	Direction direction;
	Room *source;
	Room *destination;
	bool isOpen;
	
};



#endif // !EXIT_H
