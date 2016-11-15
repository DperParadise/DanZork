#ifndef ITEM_H
#define ITEM_H

#include "entity.h"
#include <memory>

class Item : public Entity
{
public:

	typedef std::shared_ptr<Item> ptrItem;

	Item(bool isOpen, Type type, std::string name, std::string desc, std::list<ptrEntity> list);
	virtual ~Item();
	
	bool isOpen;

};



#endif // !ITEM_H