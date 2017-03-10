#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "entity.h"

class Room;
class Item;
class Player : public Entity
{
public:

	Player(Room *loc, Type type, const std::string &name, const std::string &desc, std::list<Entity*> &list);
	~Player();

	void Pickup(Item *item);
	void Drop(Item *item);
	void Open(Item *item);
	void Close(Item *item);
	void LookAt(Entity* entity);
	void Go(Direction);
	void UseWith(Item *item1, Item *item2);

	Room *location;

	
};



#endif
