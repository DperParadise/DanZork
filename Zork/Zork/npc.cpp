#include "npc.h"

Npc::Npc(
	bool isBoss,
	ptrParentItem parentItem,
	ptrRoom loc,
	Type type,
	std::string name,
	std::string desc, std::list<ptrEntity> list) : isBoss(isBoss), Creature(loc, parentItem, type, name, desc, list) {}