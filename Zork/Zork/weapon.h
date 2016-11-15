#ifndef WEAPON_H
#define WEAPON_H

#include <memory>
#include "item.h"

class Weapon : public Item
{
public:
	
	Weapon(int attack, bool isOpen, Type type, std::string name, std::string description, std::list<ptrEntity> list);

	int attack;
	

};



#endif WEAPON_H // end WEAPON_H
