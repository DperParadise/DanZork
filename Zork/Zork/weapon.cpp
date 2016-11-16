#include "weapon.h"

Weapon::Weapon(
	bool isAttachedToRope,
	int attack,
	ptrEntity parentEntity,
	bool isOpen,
	Type type,
	const std::string &name,
	const std::string &description,
	std::list<ptrEntity> &&list) : isAttachedToRope(isAttachedToRope), attack(attack), Item(parentEntity, isOpen, type, name, description, std::move(list)) {}

