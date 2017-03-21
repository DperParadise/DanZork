#ifndef EXIT_H
#define EXIT_H

#include "globals.h"
#include "entity.h"

class Entity;
class Room;
class Exit : public Entity
{
public:

	Exit(Direction location, Room *src, Room *dest, bool isOpen, bool isLocked, Type type, const char *name, const char *desc, std::list<Entity*> &list);
	~Exit();

	bool isOpen;
	bool isLocked;
	const Direction GetDirection() const;
	Room *GetSource() const;
	Room *GetDestination() const;

private:

	Direction direction;
	Room *source;
	Room *destination;
	
};



#endif // !EXIT_H
