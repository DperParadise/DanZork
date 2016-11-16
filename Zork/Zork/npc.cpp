#include "npc.h"

Npc::Npc(
	bool isBoss,
	ptrRoom loc,
	int hp,
	int defense,
	int attack,
	Type type,
	const std::string &name,
	const std::string &desc,
	std::list<ptrEntity> &&list) : isBoss(isBoss), Creature(loc, hp, defense, attack, type, name, desc, std::move(list)) {}