#ifndef EXIT_H
#define EXIT_H

#include "globals.h"
#include "entity.h"
#include <memory.h>
#include "room.h"

class Exit : public Entity
{
public:

	typedef std::shared_ptr<Room> ptrRoom;

	Exit(Direction dir, ptrRoom src, ptrRoom dest, bool isOpen, Type type, std::string name, std::string desc, std::list<ptrEntity> list);

	Direction direction;
	ptrRoom source;
	ptrRoom destination;
	bool isOpen;
};



#endif // !EXIT_H
