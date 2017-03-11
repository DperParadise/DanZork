#include "enemy.h"
#include "entity.h"
#include "globals.h"

Enemy::Enemy(Room *loc,	Type type,	const char *name, const char *desc, std::list<Entity*> &list) : location(loc), Entity(type,name,desc,list) {}

Enemy::~Enemy(){}