#ifndef ITEM_H
#define ITEM_H

#include "entity.h"
#include <memory>

class Item : public Entity
{
public:

	typedef std::shared_ptr<Item> ptrParentItem;

	Item(ptrParentItem parentItem, bool isOpen, Type type, std::string name, std::string desc, std::list<ptrEntity> list);

	ptrParentItem parentItem;
	bool isOpen;

};



#endif // !ITEM_H