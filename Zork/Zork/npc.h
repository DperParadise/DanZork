#ifndef NPC_H
#define NPC_H

#include "creature.h"

class Npc : public Creature
{
public:

	Npc(bool isBoss, ptrRoom loc, int hp, int defense, int attack, Type type, const std::string &name, const std::string &desc, std::list<ptrEntity> &&list);

	bool isBoss;
};



#endif // !NPC_H

