#include "npc.h"

Npc::Npc(
	bool isBoss,
	ptrRoom loc,
	int hp,
	int defense,
	int attack,
	Type type,
	std::string name,
	std::string desc,
	std::list<ptrEntity> list) : isBoss(isBoss), Creature(loc, hp, defense, attack, type, name, desc, list) {}