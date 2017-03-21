#ifndef __OBSERVER_H__
#define __OBSERVER_H__
#include <list>
// The observer will check if the subject contains a specific item in order to trigger an event
class Entity;
class Observer
{
private:

	Entity *subject;
	char item[50];
	typedef std::list<Entity*> Inventory;

public:
	
	Observer(Entity *sbjt, const char *itm);
	~Observer();
	bool Update();

};



#endif // !__OBSERVER_H__
