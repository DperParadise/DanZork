#include "commands.h"


void TransferItem(ptrItem ptrSrc, ptrEntity ptrDst)
{
	ptrDst->contains.push_back(ptrSrc);

	listIter found = FindEntity(ptrSrc, ptrSrc->parentEntity->contains);
	ptrSrc->parentEntity->contains.erase(found);
	ptrSrc->parentEntity = ptrDst;
}

//usable only with weapon + rope
//void TieTo(ptrWeapon ptrWeapon, ptrItem ptrItem)
//{
//	ptrWeapon->isAttachedToRope = true;
//}

//usable only with weapon + rope
//void Detach(ptrWeapon ptrWeapon, ptrItem ptrItem)
//{
//	ptrWeapon->isAttachedToRope = false;
//}

void Take(ptrPlayer player, ptrItem item) {
	TransferItem(item, player);
}

void Drop(ptrPlayer player, ptrItem item) {
	TransferItem(item, player->location);
}

void PutInto(ptrItem playerItem, ptrItem item) 
{
	TransferItem(playerItem, item);
}

void OpenExit(std::string  direction, ptrPlayer player)
{
	Direction dir;
	if (direction == "NORTH")
		dir = Direction::NORTH;
	else if (direction == "SOUTH")
		dir = Direction::SOUTH;
	else if (direction == "EAST")
		dir = Direction::EAST;
	else if (direction == "WEST")
		dir = Direction::WEST;

	bool found = false;
	for(std::list<ptrEntity>::iterator it = player->location->contains.begin(); it != player->location->contains.end() && !found; ++it)
	{ 
		if((*it)->type == Type::EXIT)
		{
			ptrExit exit = std::dynamic_pointer_cast<Exit>(*it);
			if (exit->direction == dir)
			{
				found = true;
				if (exit->isOpen)
					std::cout << "The door is open." << std::endl;
				if (!exit->isOpen && !exit->isLocked)
					exit->isOpen = true;
				if (!exit->isOpen && exit->isLocked)
				{
					listIter i = FindEntityByName("Key", player->contains);
					if (i != player->contains.end())
					{
						exit->isLocked = false;
						exit->isOpen = true;
						std::cout << "The door is open." << std::endl;
					}
					else
					{
						std::cout << "You need a key to open this door." << std::endl;
					}
				}
			}
		}
	}	
}

void OpenItem(ptrItem item)
{
	item->isOpen = true;
}

void CloseExit(std::string  direction, ptrPlayer player)
{
	Direction dir;
	if (direction == "NORTH")
		dir = Direction::NORTH;
	else if (direction == "SOUTH")
		dir = Direction::SOUTH;
	else if (direction == "EAST")
		dir = Direction::EAST;
	else if (direction == "WEST")
		dir = Direction::WEST;

	bool found = false;
	for (std::list<ptrEntity>::iterator it = player->location->contains.begin(); it != player->location->contains.end() && !found; ++it)
	{
		if ((*it)->type == Type::EXIT)
		{
			ptrExit exit = std::dynamic_pointer_cast<Exit>(*it);
			if (exit->direction == dir)
			{
				found = true;
				if (!exit->isOpen)
					std::cout << "The door is closed." << std::endl;
				if (exit->isOpen)
				{
					exit->isOpen = false;
					std::cout << "Door closed." << std::endl;
				}
			}
		}
	}
}

void LockDoor(std::string  direction, ptrPlayer player)
{
	Direction dir;
	if (direction == "NORTH")
		dir = Direction::NORTH;
	else if (direction == "SOUTH")
		dir = Direction::SOUTH;
	else if (direction == "EAST")
		dir = Direction::EAST;
	else if (direction == "WEST")
		dir = Direction::WEST;

	bool found = false;
	for (std::list<ptrEntity>::iterator it = player->location->contains.begin(); it != player->location->contains.end() && !found; ++it)
	{
		if ((*it)->type == Type::EXIT)
		{
			ptrExit exit = std::dynamic_pointer_cast<Exit>(*it);
			if (exit->direction == dir)
			{
				found = true;
				if (!exit->isLocked)
				{
					listIter i = FindEntityByName("Key", player->contains);
					if (i != player->contains.end())
					{
						exit->isLocked = true;
						exit->isOpen = false;
						std::cout << "The door is locked." << std::endl;
					}
					else
					{
						std::cout << "You need a key to lock this door." << std::endl;
					}
				}	
			}
		}
	}
}

void CloseItem(ptrItem item)
{
	item->isOpen = false;
}

listIter FindEntity(ptrEntity entity, std::list<ptrEntity> &list)
{
	bool found = false;
	listIter iterator = list.end();
	for (listIter it = list.begin(); it != list.end() && !found; std::advance(it, 1))
	{
		if ((*it)->name == entity->name)
		{
			found = true;
			iterator = it;
		}
	}

	return iterator;
}

listIter FindEntityByName(std::string entityName, std::list<ptrEntity> &list)
{
	bool found = false;
	listIter iterator = list.end();
	for (listIter it = list.begin(); it != list.end() && !found; std::advance(it, 1))
	{
		if (ToUpper((*it)->name) == ToUpper(entityName))
		{
			found = true;
			iterator = it;
		}
	}

	return iterator;
}

void StartCombat(ptrPlayer player, ptrNpc npc)
{
	//Player hits
	int damage = GetDamage();
	npc->hp -= (damage - npc->defense);
	
	//Guard hits
	if (FindEntityByName("Shield", player->contains) != player->contains.end())
	{
		int accurateHit = rand() % 3;
		if (accurateHit == 1)
		{
			damage = GetDamage();
			player->hp -= (damage - player->defense);
		}
	}
	else {
		damage = GetDamage();
		player->hp -= (damage - player->defense);
	}
}

int  GetDamage() {
	int hitArea = rand() % 6;
	int damage;
	switch (hitArea)
	{
	case HitArea::HEAD:
		damage = 100 + 500;
		break;
	case HitArea::LEFT_ARM:
		damage = 100 + 50;
		break;
	case HitArea::RIGHT_ARM:
	case HitArea::LEFT_LEG:
	case HitArea::RIGHT_LEG:
		damage = 100 + 40;
		break;
	}

	return damage;
}

GoDirection Go(ptrPlayer player,Direction dir) 
{
	ptrRoom room = player->location;
	ptrExit exit;

	for (ptrEntity elem : room->contains)
	{
		if (elem->type == Type::EXIT)
		{
			exit = std::dynamic_pointer_cast<Exit>(elem);
			if (exit->direction == dir)
			{
				if (exit->isOpen)
				{	
					player->previousRoom = player->location;
					player->location = exit->destination;
					return GoDirection::OK;	
				}
				else 
				{
					return GoDirection::CLOSED;
				}
			}	
		}
	}

	return GoDirection::NO_WAY;

}

void Search(ptrPlayer player, ptrNpc npc)
{
	listIter it = npc->contains.begin();
	while (it != npc->contains.end())
	{
		Take(player, std::dynamic_pointer_cast<Item>(*it));
		it = npc->contains.begin();
	}
	
}

void Look(ptrEntity entity, std::list<ptrEntity> &listCreatures)
{
	//Look items in room
	for (ptrEntity elem : entity->contains)
	{	
		std::cout << elem->description << std::endl;
		if (elem->contains.size() != 0 && elem->type == Type::ITEM)
		{
			if(std::dynamic_pointer_cast<Item>(elem)->isOpen)
			for (ptrEntity innerPtr : elem->contains) {
				std::cout << innerPtr->description << std::endl;
			}
		}
	}

	//Look creatures in room
	if (entity->type == Type::ROOM)
	{
		for (ptrEntity creature : listCreatures)
		{
			if (std::dynamic_pointer_cast<Creature>(creature)->location->name == entity->name && creature->name != "Player")
				std::cout << creature->description << std::endl;
		}
	}
	

}


std::map<std::string, std::string> GetItemsToCombine(const std::vector<std::string>& words)
{
	std::vector<std::string>::const_iterator it = words.cbegin();
	std::string firstItem;
	std::string secondItem;
	std::string firstItemNoSpace;
	std::string secondItemNoSpace;

	std::map<std::string, std::string> items = std::map<std::string, std::string>();

	++it;
	while (*it != "INTO")
	{
		firstItem += (*it + " ");
		++it;
	}

	++it;

	while (it != words.cend())
	{
		secondItem += (*it + " ");
		++it;
	}
	firstItemNoSpace = std::string(firstItem.begin(), firstItem.end() - 1);
	secondItemNoSpace = std::string(secondItem.begin(), secondItem.end() - 1);

	items["firstItem"] = firstItemNoSpace;
	items["secondItem"] = secondItemNoSpace;
	return items;
}


Scenario UpdateScenario(ptrExit exit)
{
	return Scenario::CELL;
}

