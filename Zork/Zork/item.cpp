#include "item.h"

Item::Item(
	ptrParentItem parentItem,
	bool isOpen,
	bool isVisible,
	Type type,
	std::string name,
	std::string desc,
	std::list<ptrEntity> list) : parentItem(parentItem), isOpen(isOpen), isVisible(isVisible), Entity(type, name, desc, list) {}