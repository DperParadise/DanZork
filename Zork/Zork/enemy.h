#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Entity;
class Room;
class Enemy : public Entity
{
public:

	Enemy(Room *loc, Type type, const std::string &name, const std::string &desc, std::list<Entity*> list);
	~Enemy();

	Room *location;
	Type type;
	std::string name;
	std::string description;
	std::list<Entity*> contains;
};



#endif // !ENEMY_H

