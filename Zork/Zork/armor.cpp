
#include "armor.h"

Armor::Armor(int attack,
	ptrEntity parentEntity,
	bool isOpen,
	Type type,
	const std::string &name,
	const std::string &description,
	std::list<ptrEntity> &&list) : defense(defense), Item(parentEntity, isOpen, type, name, description, std::move(list)) {}
