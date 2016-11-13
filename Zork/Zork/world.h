#ifndef WORLD_H
#define WORLD_H

#include "entity.h"
#include <vector>
#include <memory>


class World : public Entity
{
	
public:
	
	World(std::vector<ptrEntity> v);
	virtual ~World();
	
	std::vector<ptrEntity> entities;
};



#endif // end WORLD_H

