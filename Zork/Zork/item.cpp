#include "Item.h"

Item::Item(
	Type type,
	std::string name,
	std::string desc,
	std::list<ptrEntity> list) : Entity(type, name, desc, list) {}