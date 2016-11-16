#include "entity.h"


Entity::Entity() {}
Entity::Entity(
	Type type, 
	const std::string &name, 
	const std::string &desc,
	std::list<ptrEntity> &&list) : type(type), name(name), description(desc), contains(std::move(list)) {}
Entity::~Entity() {}