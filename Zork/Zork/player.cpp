#include "player.h"
#include "entity.h"
#include "globals.h"
#include "room.h"
#include "item.h"

Player::Player(
	Room *loc,
	Type type,
	const char *name,
	const char *desc,
	std::list<Entity*> &list
	) : location(loc), Entity(type, name, desc, list) {}

Player::~Player(){}

void Player::Pickup(const char *item)
{
	memset(message, '\0', 100);
	strcpy(message, "I can't pick that ");

	//look for the item inside the players room
	std::list<Entity*>::iterator it;
	std::list<Entity*>::iterator end = location->contains.end();
	bool found = false;

	for(it = location->contains.begin(); !found && it != end; it++)
	{
		if(strcmp((*it)->name,item) == 0)
			if ((*it)->type == ITEM && ((Item*)(*it))->size == SMALL)
			{
				found = true;
				((Item*)(*it))->parent = this;
				contains.push_back(*it);
				strcpy(message, item);
				strcat(message, " added to inventory");
			}
	}


}

void Player::Drop(const char *item)
{
	//look for the item inside player's inventory

}

void Player::Open(const char *item) const
{

}

void Player::Close(const char *item) const
{

}

void Player::LookAt(const char *entity) const
{

}

void Player::Go(Direction dir)
{

}

void Player::UseWith(const char *item1, const char *item2) const
{

}

void Player::Inventory() const
{

}

char *Player::GetMessage()
{
	return message;
}