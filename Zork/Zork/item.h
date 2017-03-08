#ifndef ITEM_H
#define ITEM_H

#include "entity.h"
#include <memory>

class Item : public Entity
{
public:

	typedef std::shared_ptr<Item> ptrItem;
	typedef std::shared_ptr<Entity> ptrEntity;

	Item(ptrEntity parentEntity, ItemSize size, bool isOpen, bool canBeOpened, Type type, const std::string &name, const std::string &desc, std::list<ptrEntity> &&list);
	virtual ~Item();
	
	bool isOpen;
	bool canBeOpened;
	ItemSize size;
	ptrEntity parentEntity;

};



#endif // !ITEM_H