#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Entity;
class Room;
class Enemy : public Entity
{
public:

	Enemy(Room *loc, Type type, const char *name, const char *desc, std::list<Entity*> &list);
	~Enemy();

	Room *location;
	
};



#endif // !ENEMY_H

