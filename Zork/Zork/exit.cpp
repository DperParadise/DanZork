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
	std::list<Entity*> &list) : direction(dir), source(src), destination(dest), isOpen(isOpen), Entity(type, name, desc,list) {}

Exit::~Exit(){}

const Direction Exit::GetDirection() const
{
	return direction;
}

Room* Exit::GetSource() const
{
	return source;
}

Room* Exit::GetDestination() const
{
	return destination;
}