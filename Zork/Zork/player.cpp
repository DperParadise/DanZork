#include "player.h"
#include "entity.h"
#include "globals.h"
#include "room.h"
#include "item.h"
#include "exit.h"
#include "world.h"
#include "enemy.h"

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
	strcpy(message, "I can't pick that\n");

	//look for the item inside the room of the player
	Inventory::iterator it;
	Inventory::iterator end = location->contains.end();
	bool found = false;

	for(it = location->contains.begin(); !found && it != end;)
	{
		if(strcmp((*it)->name,item) == 0)
			if ((*it)->type == ITEM )
			{
				if (((Item*)(*it))->parent != nullptr && ((Item*)(*it))->parent->type == PLAYER)
				{
					sprintf(message, "%s already in your inventory\n", item);
				}				
				else if (((Item*)(*it))->parent == nullptr || ((Item*)((Item*)(*it))->parent)->isOpen)
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
									iter++;
							}
							((Item*)(*it))->parent->contains.erase(to_delete);

						}
						//Set new parent - player
						((Item*)(*it))->parent = this;
						contains.push_back(*it);
						sprintf(message, "%s added to inventory\n", item);					
					}
				}
			}
		if (!found) it++;
	}
}

void Player::Drop(const char *item)
{
	strcpy(message, "I can't drop that\n");

	Entity* item_fnd = nullptr;
	for (Inventory::iterator it = contains.begin(); it != contains.end(); it++)
	{
		if (!strcmp((*it)->name, item))
		{
			item_fnd = (*it);
			contains.erase(it);
			break;
		}
	}

	if (item_fnd != nullptr)
	{
		((Item*)item_fnd)->parent = nullptr;
		strcpy(message, "Item dropped\n");
	}

}

void Player::Open(const char *item) 
{
	strcpy(message, "I can't open that\n");
	Entity* fnd = nullptr;
	
	for (Inventory::iterator it = location->contains.begin(); it != location->contains.end(); it++)
	{
		if (!strcmp(item, (*it)->name))
		{
			fnd = (*it);
			break;
		}
	}
	
	if (fnd != nullptr)
	{
		if (fnd->type == EXIT)
		{
			if (((Exit*)(fnd))->isLocked == false)
			{
				if (((Exit*)(fnd))->isOpen)
					strcpy(message, "Door already open\n");
				else
				{
					((Exit*)(fnd))->isOpen = true;
					Room *dest = ((Exit*)(fnd))->GetDestination();
					for (Inventory::iterator it_dst = dest->contains.begin(); it_dst != dest->contains.end(); it_dst++)
					{
						if (!strcmp(fnd->name, (*it_dst)->name))
						{
							((Exit*)(*it_dst))->isOpen = true;
						}
					}
					strcpy(message, "Door open\n");
				}
			}
			else
			{
				strcpy(message, "Door locked\n");
			}
		}
		else if (fnd->type == ITEM && ((Item*)(fnd))->isContainer)
		{
			if (((Item*)(fnd))->isLocked)// trying to open wardrobe closet
			{
				bool found = false;
				for (Inventory::iterator it = contains.begin(); it != contains.end(); it++)
				{
					if (!strcmp("closet key", (*it)->name))
					{
						sprintf(message, "You open the %s\n", fnd->name);
						((Item*)(fnd))->isLocked = false;
						((Item*)(fnd))->isOpen = true;
						found = true;
						break;
					}

				}

				if (!found)
					sprintf(message, "You need a key to open the %s", fnd->name);
			}
		}

	}
}

void Player::Close(const char *entity) 
{
	strcpy(message, "I can't do that\n");
	bool found = false;
	Entity *fnd = nullptr;
	for (Inventory::iterator it = location->contains.begin(); it != location->contains.end(); it++)
	{
		if (!strcmp(entity, (*it)->name))
		{
			found = true;
			fnd = *it;
		}
	}

	if (found)
	{
		if (fnd->type == EXIT)
		{
			if (((Exit*)fnd)->isOpen == true)
			{
				((Exit*)fnd)->isOpen = false;
				Room *dest = ((Exit*)(fnd))->GetDestination();
				for (Inventory::iterator it_dst = dest->contains.begin(); it_dst != dest->contains.end(); it_dst++)
				{
					if (!strcmp(fnd->name, (*it_dst)->name))
					{
						((Exit*)(*it_dst))->isOpen = false;
					}
				}
				sprintf(message, "%s closed\n", fnd->name);
			}
			else
				strcpy(message, "Already closed\n");
		}
		if (fnd->type == ITEM)
		{
			if (((Item*)fnd)->isContainer)
			{
				if (((Item*)fnd)->isOpen)
				{
					((Item*)fnd)->isOpen = false;
					sprintf(message, "%s closed\n", fnd->name);
				}
				else
					strcpy(message, "Already closed\n");
			}

		}
	}
}

void Player::LookAt(const char *entity, const World *world) 
{
	strcpy(message, "I can't look at that\n");

	bool found = false;
	bool visible = false;
	Inventory::const_iterator it;

	for (it = world->GetWorldInv().begin(); it != world->GetWorldInv().end() && !found;) 
	{
		if ((*it)->type == EXIT)
		{
			if (!strcmp(entity, (*it)->name) && location == ((Exit*)(*it))->GetSource())
				found = true;
		}
		else
		{
			if(strcmp(entity, (*it)->name) == 0)
				found = true;
		}

		if (!found)
			it++;
	}

	if (found && (*it)->type == ROOM)
	{
		if (location == *it)
		{
			sprintf(message, "%s: %s\n", (*it)->name, (*it)->description);

			if ((*it)->contains.size() != 0)
			{				
				strcat(message, "Inside the ");
				strcat(message, (*it)->name);
				strcat(message, ":\n================\n");

				for (Inventory::iterator iter = (*it)->contains.begin(); iter != (*it)->contains.end(); iter++)
				{
					if ((*iter)->type == ENEMY || (*iter)->type == EXIT || (*iter)->type == ITEM && ((Item*)(*iter))->parent == nullptr)
					{
						strcat(message, (*iter)->name);
						strcat(message, "\n");
					}
				}
			}
		}
	}

	else if (found && (*it)->type == ITEM)
	{
		if (location == ((Item*)(*it))->loc)
		{		
			sprintf(message, "%s: %s\n", (*it)->name, (*it)->description);
			LookInsideItem((Item*)(*it));				
		}
	}
	
	else if (found && (*it)->type == EXIT)
	{
		if (location == ((Exit*)(*it))->GetSource())
		{
			sprintf(message, "%s: %s\n", (*it)->name, (*it)->description);
		}
	}

	else if (found && (*it)->type == ENEMY)
	{
		if (location == ((Enemy*)(*it))->location)
		{
			sprintf(message, "%s: %s\n", (*it)->name, (*it)->description);
		}
	}

}

void Player::Go(const char *dir)
{
	strcpy(message, "I can't go in that direction\n");

	Direction d;
	Room *dest;
	bool room_chg = false;
	bool wrong_dir = false;

	if (!strcmp(dir, "n") || !strcmp(dir, "north"))
		d = NORTH;
	else if (!strcmp(dir, "s") || !strcmp(dir, "south"))
		d = SOUTH;
	else if (!strcmp(dir, "w") || !strcmp(dir, "west"))
		d = WEST;
	else if (!strcmp(dir, "e") || !strcmp(dir, "east"))
		d = EAST;
	else
		wrong_dir = true;

	if (!wrong_dir)
	{
		//Check exit
		for (Inventory::iterator it = location->contains.begin(); it != location->contains.end(); it++)
		{
			if ((*it)->type == EXIT && ((Exit*)(*it))->GetDirection() == d)
			{
				if (((Exit*)(*it))->isOpen)
				{
					//Set items new location
					dest = ((Exit*)(*it))->GetDestination();
					SetItemLoc(contains, dest);
					room_chg = true;
					break;
				}
				else
				{
					strcpy(message, "The door is closed\n");
				}
			}
		}
	}
	if (room_chg)
	{
		//Set player new location
		location = dest;
		sprintf(message, "Current location: %s\n===========================\n%s\n", location->name, location->description);
	}
}

void Player::UseWith(const char *item1, const char *item2) 
{
	strcpy(message, "I can't do that\n");
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
				sprintf(message, "%s put into %s\n", item1, item2);

			}
		}
	}

	//--------player haven't picked bread crumbs up or no item found
	if (!found1)
		sprintf(message, "I don't have %s\n", item1);

}

void Player::ShowInv()
{
	memset(message, '\0', mg_length);
	
	if (contains.size() == 0)
	{
		strcpy(message, "Inventory is empty\n");
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

void Player::SetItemLoc(Inventory &inv, Room *ftr_loc)
{
	for (Inventory::iterator it = inv.begin(); it != inv.end(); it++)
	{
		//Set new location to items 
		for (Inventory::iterator it_room = location->contains.begin(); it_room != location->contains.end(); it_room++)
		{
			if (!strcmp((*it_room)->name, (*it)->name))
			{
				((Item*)(*it_room))->loc = ftr_loc;
				ftr_loc->contains.push_back(*it_room);
				location->contains.erase(it_room);
				break;
			}
		}

		if ((*it)->contains.size() != 0)
		{
			SetItemLoc((*it)->contains, ftr_loc);
		}	
	}
}

void Player::LookInsideItem(Item *item)
{
	if (item->contains.size() != 0 && item->isOpen)
	{
		strcat(message, "Inside the ");
		strcat(message, item->name);
		strcat(message, ":\n");

		for(Inventory::iterator it = item->contains.begin(); it != item->contains.end(); it++)
		{		
			strcat(message, (*it)->name);
			strcat(message, "\n");
			LookInsideItem((Item*)(*it));	
		}
	}
}