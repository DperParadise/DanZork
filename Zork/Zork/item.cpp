#include "item.h"

Item::Item(
	ptrEntity parentEntity,
	ItemSize size,
	bool isOpen,
	bool canBeOpened,
	Type type,
	const std::string &name,
	const std::string &desc,
	std::list<ptrEntity> &&list) : parentEntity(parentEntity), size(size), isOpen(isOpen), canBeOpened(canBeOpened), Entity(type, name, desc, std::move(list)) {}

Item::~Item() {}
