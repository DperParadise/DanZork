#include "commands.h"

void TransferItem(ptrItem ptrSrc, ptrEntity ptrDst)
{
	ptrDst->contains.push_back(ptrSrc);

	ptrEntity  parentEntity = ptrSrc->parentEntity;
	std::list<ptrEntity> listParent = parentEntity->contains;

	listIter found = FindEntity(ptrSrc, listParent);
	listParent.erase(found);
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

void PutInto(ptrItem playerItem, ptrItem item) {
	TransferItem(playerItem, item);
}

void OpenExit(ptrExit exit)
{
	exit->isOpen = true;
}

void OpenItem(ptrItem item)
{
	item->isOpen = true;
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
	listIter iterator;
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
	std::cout << entity->description << std::endl;
}