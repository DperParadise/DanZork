#ifndef EXIT_H
#define EXIT_H

#include "globals.h"

class Entity;
class Room;
class Exit : public Entity
{
public:


	Exit(Direction dir, Room *src, Room *dest, bool isOpen, Type type, const std::string &name, const std::string &desc, std::list<Entity*> list);
	~Exit();

	Direction direction;
	Room *source;
	Room *destination;
	bool isOpen;
	
};



#endif // !EXIT_H
