#ifndef WORLD_H
#define WORLD_H

#include "entity.h"
#include <vector>

class World : public Entity
{
public:
	World(std::vector<Entity*> v);
	virtual ~World();
	
	std::vector<Entity*> entities;
};



#endif // end WORLD_H

