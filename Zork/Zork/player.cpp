#include "player.h"
#include "entity.h"
#include "globals.h"
#include "room.h"
#include "item.h"
#include "world.h"

Player::Player(
	Room *loc,
	Type type,
	const char *name,
	const char *desc,
	std::list<Entity*> &list
	) : location(loc), Entity(type, name, desc, list) 
{
	mg_length = sizeof(message) / sizeof(char);
}

Player::~Player(){}

void Player::Pickup(const char *item)
{
	memset(message, '\0', mg_length);
	strcpy(message, "I can't pick that ");

	//look for the item inside the room of the player
	Inventory::iterator it;
	Inventory::iterator end = location->contains.end();
	Inventory::iterator to_delete;
	bool found = false;

	for(it = location->contains.begin(); !found && it != end; it++)
	{
		if(strcmp((*it)->name,item) == 0)
			if ((*it)->type == ITEM )
			{
				if ((Item*)((Item*)(*it))->parent == nullptr || ((Item*)((Item*)(*it))->parent)->isOpen)
				{
					if(((Item*)(*it))->size == SMALL)
					{
						found = true;
						((Item*)(*it))->parent = this;
						contains.push_back(*it);
						strcpy(message, item);
						strcat(message, " added to inventory");
						to_delete = it;
					}
				}
			}
	}
	if (found)
	{
		((Item*)(*it))->parent = this;
		((Item*)(*it))->loc = nullptr;
		location->contains.erase(to_delete);
	}
}

void Player::Drop(const char *item)
{
	

}

void Player::Open(const char *item) 
{

}

void Player::Close(const char *item) 
{

}

void Player::LookAt(const char *entity, const World *world) 
{
	memset(message, '\0', mg_length);
	strcpy(message, "I can't look at that ");

	bool found = false;
	bool visible = false;
	Inventory::const_iterator it;

	for (it = world->GetWorldInv().begin(); it != world->GetWorldInv().end() && !found; it++) 
	{
		if (strcmp(entity, (*it)->name) == 0)
		{
			found = true;
		}
	}

	if (found && (*it)->type == ROOM)
	{
		if (strcmp(location->name, entity) == 0)
		{
			visible = true;
		}
	}

	if (found && (*it)->type == ITEM)
	{
		if (strcmp(((Item*)(*it))->loc->name, location->name))
		{
			visible = true;			
		}
	}

	if (visible)
	{
		memset(message, '\0', mg_length);

		for (Inventory::iterator it = location->contains.begin(); it != location->contains.end(); it++)
		{
			if (((Item*)(*it))->parent == nullptr || ((Item*)(((Item*)(*it))->parent))->isOpen)
			{
				strcat(message, (*it)->name);
				strcat(message, " : ");
				strcat(message, (*it)->description);
				strcat(message, "\n");
			}
		}
	}

}

void Player::Go(Direction dir)
{

}

void Player::UseWith(const char *item1, const char *item2) 
{

}

void Player::ShowInv()
{
	memset(message, '\0', mg_length);
	strcpy(message, "Empty");
	Inventory::iterator it;
	Inventory::iterator end = contains.end();
	for (it = contains.begin(); it != end; it++)
	{
		strcat(message, ((Item*)(*it))->name);
		strcat(message, "\n");
	}
}

const char *Player::GetMessage()
{
	return message;
}