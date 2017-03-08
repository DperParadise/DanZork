#include "npc.h"
#include "entity.h"
#include "globals.h"

Npc::Npc(Room *loc,	Type type,	const std::string &name, const std::string &desc, std::list<Entity*> list) : Entity(type,name,desc,list) {}

Npc::~Npc()
{
	RELEASE(location);
}