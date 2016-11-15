#include "entity.h"


Entity::Entity() {}
Entity::Entity(
	Type type, 
	std::string name, 
	std::string desc,
	std::list<ptrEntity> list) : type(type), name(name), description(desc), contains(std::move(list)) {}
Entity::~Entity() {}