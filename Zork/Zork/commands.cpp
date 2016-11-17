#include "commands.h"

void TransferItem(ptrItem ptrSrc, ptrEntity ptrDst)
{
	ptrDst->contains.push_back(ptrSrc);

	listIter found = FindEntity(ptrSrc, ptrSrc->parentEntity->contains);
	ptrSrc->parentEntity->contains.erase(found);
	ptrSrc->parentEntity = ptrDst;
}

//usable only with weapon + rope
void TieTo(ptrWeapon ptrWeapon, ptrItem ptrItem)
{
	ptrWeapon->isAttachedToRope = true;
}

//usable only with weapon + rope
void Detach(ptrWeapon ptrWeapon, ptrItem ptrItem)
{
	ptrWeapon->isAttachedToRope = false;
}

void Take(ptrPlayer player, ptrItem item) {
	TransferItem(item, player);
}

void Drop(ptrPlayer player, ptrItem item) {
	TransferItem(item, player->location);
}
//only if item isOpen
void PutInto(ptrItem playerItem, ptrItem item) {
	TransferItem(playerItem, item);
}

void OpenExit(ptrExit exit)
{
	exit->isOpen = true;
}
//take items to the room
void OpenItem(ptrItem item, ptrPlayer player)
{
	item->isOpen = true;
	TransferItem(item, player->location);
}

void CloseExit(ptrExit exit)
{
	exit->isOpen = false;
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
		if (ToUpper((*it)->name) == entityName)
		{
			found = true;
			iterator = it;
		}
	}

	return iterator;
}

void StartCombat(ptrPlayer player, ptrNpc npc)
{

}

bool Go(ptrPlayer player,Direction dir) 
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
					return true;
				}
				else 
				{
					return false;
				}
			}
		}
	}
	return false;
}

void Search(ptrNpc npc, ptrPlayer player)
{
	for (ptrEntity elem : npc->contains)
		TransferItem(std::dynamic_pointer_cast<Item>(elem), player->location);
}

void Look(ptrEntity entity)
{
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
}