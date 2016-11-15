#include "item.h"

Item::Item(
	bool isOpen,
	Type type,
	std::string name,
	std::string desc,
	std::list<ptrEntity> list) : isOpen(isOpen), Entity(type, name, desc, list) {}

Item::~Item() {}
