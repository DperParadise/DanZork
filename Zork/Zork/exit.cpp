#include "exit.h"

Exit::Exit(
	Direction dir,
	ptrRoom src,
	ptrRoom dest,
	Type type,
	std::string name,
	std::string desc,
	std::list<ptrEntity> list) : direction(dir), source(src), destination(dest), Entity(type, name, desc, list) {}