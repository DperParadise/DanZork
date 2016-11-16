#include "item.h"

Item::Item(
	ptrEntity parentEntity,
	bool isOpen,
	Type type,
	const std::string &name,
	const std::string &desc,
	std::list<ptrEntity> &&list) : parentEntity(parentEntity), isOpen(isOpen), Entity(type, name, desc, std::move(list)) {}

Item::~Item() {}
