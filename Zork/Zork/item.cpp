#include "item.h"

Item::Item(
	ptrParentItem parentItem,
	bool isOpen,
	bool discovered,
	Type type,
	std::string name,
	std::string desc,
	std::list<ptrEntity> list) : parentItem(parentItem), isOpen(isOpen), Entity(type, name, desc, list) {}