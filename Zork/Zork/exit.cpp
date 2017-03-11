#include "exit.h"
#include "globals.h"
#include "entity.h"

Exit::Exit(
	Direction dir,
	Room *src,
	Room *dest,
	bool isOpen,
	Type type,
	const char *name,
	const char *desc,
	std::list<Entity*> &list) : direction(dir), source(src), destination(dest), isOpen(), Entity(type, name, desc,list) {}

Exit::~Exit(){}