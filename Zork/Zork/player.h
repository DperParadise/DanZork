#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "entity.h"
#include <string>
class World;
class Room;
class Item;
class Player : public Entity
{

private:

	typedef std::list<Entity*> Inventory;
	char message[400];
	size_t mg_length;

public:

	Player(Room *loc, Type type, const char *name, const char *desc, std::list<Entity*> &list);
	~Player();

	void Pickup(const char *item);
	void Drop(const char *item);
	void Open(const char *item);
	void Close(const char *item);
	void LookAt(const char *entity, const World *world);
	void Go(const char *dir);
	void UseWith(const char *item1, const char *item2);
	void ShowInv();
	void SetItemLoc(Inventory &inv, Room *ftr_loc);
	void LookInsideItem(Item *item);
	const char *GetMessage();

	Room *location;
	
};



#endif
