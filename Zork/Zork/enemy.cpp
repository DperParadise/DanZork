#include "enemy.h"
#include "entity.h"
#include "globals.h"

Enemy::Enemy(Room *loc,	Type type,	const std::string &name, const std::string &desc, std::list<Entity*> list) : Entity(type,name,desc,list) {}

Enemy::~Enemy()
{
	RELEASE(location);
}