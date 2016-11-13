#include "exit.h"

Exit::Exit(
	Direction dir,
	ptrRoom src,
	ptrRoom dest,
	bool isOpen,
	Type type,
	std::string name,
	std::string desc,
	std::list<ptrEntity> list) : direction(dir), source(src), destination(dest), isOpen(0), Entity(type, name, desc, list) {}