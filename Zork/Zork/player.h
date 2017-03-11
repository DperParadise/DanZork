#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "entity.h"
#include <string>

class Room;
class Player : public Entity
{
public:

	Player(Room *loc, Type type, const char *name, const char *desc, std::list<Entity*> &list);
	~Player();

	void Pickup(const char *item);
	void Drop(const char *item);
	void Open(const char *item) const;
	void Close(const char *item) const;
	void LookAt(const char *entity) const;
	void Go(Direction);
	void UseWith(const char *item1, const char *item2) const;
	void Inventory() const;
	
	char *GetMessage();

	Room *location;
private:

	char message[100];

	
};



#endif
