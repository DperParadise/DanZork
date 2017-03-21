#include "entity.h"
#include "Observer.h"

Entity::Entity(
	Type type, 
	const char *name,
	const char *desc,
	std::list<Entity*> &list) : type(type), name(name), description(desc), contains(list), observer(nullptr) {}

Entity::~Entity()
{
	if (contains.size() != 0)
		contains.clear();
}

void Entity::RegisterObs(Observer *obs)
{
	if (obs != nullptr)
		observer = obs;
}
bool Entity::NotifyObs()
{
	return observer->Update();
}

