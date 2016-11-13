#ifndef ITEM_H
#define ITEM_H

#include "entity.h"

class Item : public Entity
{
public:
	Item(Type type, std::string name, std::string desc, std::list<ptrEntity> list);
};



#endif // !ITEM_H