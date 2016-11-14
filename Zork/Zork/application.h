#ifndef APPLICATION_H
#define APPLICATION_H

#include "globals.h"
#include "world.h"
#include <memory>


class Application
{
public:

	typedef  std::shared_ptr<World> ptrWorld;

	Application(ptrWorld pw);
	void Init();
	void Start();
	ReturnState Update();

private:
	ptrWorld world;

};


#endif //APPLICATION_H


