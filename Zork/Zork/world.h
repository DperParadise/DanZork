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
	char input[50];
	char command[50];
};


#endif //WORLD_H


