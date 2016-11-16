#ifndef WEAPON_H
#define WEAPON_H

#include <memory>
#include "item.h"

class Weapon : public Item
{
public:
	
	Weapon(bool isAttachedToRope, int attack, ptrEntity parentEntity, bool isOpen, Type type, const std::string &name, const std::string &description, std::list<ptrEntity> &&list);

	int attack;
	bool isAttachedToRope;

};



#endif WEAPON_H // end WEAPON_H
