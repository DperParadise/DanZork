#include "weapon.h"

Weapon::Weapon(int defense,
	bool isOpen,
	Type type,
	std::string name,
	std::string description,
	std::list<ptrEntity> list) : attack(attack), Item(isOpen, type, name, description, list) {}

