#ifndef WORLD_H
#define WORLD_H

#include "entity.h"

class World
{
public:
	
	//Create game objects
	void Init();

	//Start initial message
	void Start();

	ReturnState Update();
	

private:
	std::list<Entity*> world;

};


#endif //WORLD_H


