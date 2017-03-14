#include "player.h"
#include "entity.h"
#include "globals.h"
#include "room.h"
#include "item.h"
#include "exit.h"
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
	strcpy(message, "I can't pick that ");

	//look for the item inside the room of the player
	Inventory::iterator it;
	Inventory::iterator end = location->contains.end();
	Inventory::iterator to_delete;
	bool found = false;

	for(it = location->contains.begin(); !found && it != end;)
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
		if (!found) it++;
	}
	if (found)
	{
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
	strcpy(message, "I can't look at that ");

	bool found = false;
	bool visible = false;
	Inventory::const_iterator it;

	for (it = world->GetWorldInv().begin(); it != world->GetWorldInv().end() && !found;) 
	{
		if (strcmp(entity, (*it)->name) == 0)
		{
			found = true;
		}
		if (!found)
			it++;
	}

	
	if (found && (*it)->type == ROOM)
	{
		if (location == *it)
		{
			visible = true;
		}
	}

	else if (found && (*it)->type == ITEM)
	{
		if (location == ((Item*)(*it))->loc)
		{
			visible = true;			
		}
		else
		{
			bool fnd = false;
			for (Inventory::iterator iter = contains.begin(); iter != contains.end() && !fnd; iter++)
			{
				if (*it == (*iter))
				{
					visible = true;
					fnd = true;
				}
			}
		}
	}
	
	else if (found && (*it)->type == EXIT)
	{
		if (location == ((Exit*)(*it))->GetSource())
		{
			visible = true;
		}
	}


	if (visible)
	{
		strcpy(message, (*it)->name);
		strcat(message, " : ");
		strcat(message, (*it)->description);
		strcat(message, "\n");
		
		if ((*it)->contains.size() != 0)
		{
			strcat(message, "Inside the ");
			strcat(message, location->name);
			strcat(message, ":\n");
			strcat(message, "================\n");
		}

		for (Inventory::iterator iter = (*it)->contains.begin(); iter != (*it)->contains.end(); iter++)
		{
			if (((Item*)(*iter))->parent == nullptr || ((Item*)(((Item*)(*iter))->parent))->isOpen)
			{
				strcat(message, (*iter)->name);
				strcat(message, " : ");
				strcat(message, (*iter)->description);
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
	
	if (contains.size() == 0)
	{
		strcpy(message, "Inventory is empty");
	}
	else
	{
		strcpy(message, "Inventory:\n");
		strcat(message, "==========\n");
		Inventory::iterator it;
		Inventory::iterator end = contains.end();
		for (it = contains.begin(); it != end; it++)
		{
			strcat(message, ((Item*)(*it))->name);
			strcat(message, "\n");
		}
	}
}

const char *Player::GetMessage()
{
	return message;
}