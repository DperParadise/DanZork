#include "Observer.h"
#include <cstring>
#include "entity.h"

Observer::Observer(Entity *sbjt, const char *itm)
{
	subject = sbjt;
	strcpy(item, itm);
}

Observer::~Observer() {}

bool Observer::Check()
{
	bool ret = false;
	for (Inventory::iterator it = subject->contains.begin(); it != subject->contains.end(); it++)
	{
		if (!strcmp(item, (*it)->name))
		{
			ret = true;
			break;
		}
	}

	return ret;
}