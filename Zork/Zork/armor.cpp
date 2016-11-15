
#include "armor.h"

Armor::Armor(int attack,
	bool isOpen,
	Type type,
	std::string name,
	std::string description,
	std::list<ptrEntity> list) : defense(defense), Item(isOpen, type, name, description, list) {}
