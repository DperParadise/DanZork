#include "npc.h"

Npc::Npc(
	bool isBoss,
	ptrRoom loc,
	Type type,
	std::string name,
	std::string desc, std::list<ptrEntity> list) : isBoss(isBoss), Creature(loc, type, name, desc, list) {}