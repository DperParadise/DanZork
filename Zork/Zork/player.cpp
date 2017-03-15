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
						
						//Erase item from from former parent inventory
						if (((Item*)(*it))->parent != nullptr)
						{
							bool fnd = false;
							Inventory::iterator to_delete;
							for (Inventory::iterator iter = ((Item*)(*it))->parent->contains.begin(); !fnd && iter != ((Item*)(*it))->parent->contains.end();)
							{
								if (*iter == *it)
								{
									fnd = true;
									to_delete = iter;
								}
								else
									it++;
							}
							((Item*)(*it))->parent->contains.erase(to_delete);

						}
						//Set new parent - player
						((Item*)(*it))->parent = this;
						contains.push_back(*it);
						sprintf(message, "%s added to inventory", item);					
					}
				}
			}
		if (!found) it++;
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
			if(((Item*)(*it))->parent == nullptr || ((Item*)(*it))->parent == this || ((Item*)(((Item*)(*it))->parent))->isOpen)
				visible = true;			
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
		sprintf(message, "%s: %s\n", (*it)->name, (*it)->description);
		
		if ((*it)->contains.size() != 0)
		{			
			sprintf(message, "Inside the %s:\n================\n", (*it)->name);
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
	strcpy(message, "I can't do that ");
	bool found1 = false;
	bool found2 = false;
	Inventory::iterator it1;
	Inventory::iterator it2;
	
	//Look for the item1 in the player's inventory
	for (it1 = contains.begin(); !found1 && it1 != contains.end();)
	{
		if (strcmp((*it1)->name, item1) == 0)
		{
			found1 = true;
		}
		if (!found1) it1++;
	}

	for (it2 = location->contains.begin(); !found2 && it2 != location->contains.end();)
	{
		if (strcmp((*it2)->name, item2) == 0)
		{
			found2 = true;
		}
		if (!found2) it2++;
	}

	if(!found2)
		for (it2 = contains.begin(); !found2 && it2 != contains.end();)
		{
			if (strcmp((*it2)->name, item2) == 0)
			{
				found2 = true;
			}
			if (!found2) it2++;
		}

	if (found1 && found2)
	{
		if ((*it2)->type == ITEM)
		{
			if (((Item*)(*it2))->isOpen && ((Item*)(*it1))->size <= ((Item*)(*it2))->size)
			{				
				//Get ready to delete it from player inventory
				Inventory::iterator to_delete = it1;
				
				//Use item2 as new parent of item1				
				((Item*)(*it1))->parent = ((Item*)(*it2));
				((Item*)(*it1))->loc = ((Item*)(*it2))->loc;
				(*it2)->contains.push_back(*it1);
				contains.erase((to_delete));
				sprintf(message, "%s put into %s", item1, item2);

			}
		}
	}

	//--------player haven't picked bread crumbs up or no item found
	if (!found1)
		sprintf(message, "I don't have %s", item1);

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