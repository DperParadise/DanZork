#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"
#include <memory>

class Armor : public Item
{
public:

	typedef std::shared_ptr<Armor> ptrArmor;

	Armor(int defense, bool isOpen, Type type, std::string name, std::string description, std::list<ptrEntity> list);

	int defense;

};


#endif ARMOR_H //end ARMOR_H