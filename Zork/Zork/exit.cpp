#include "exit.h"

Exit::Exit(
	Direction dir,
	ptrRoom src,
	ptrRoom dest,
	bool isOpen,
	Type type,
	const std::string &name,
	const std::string &desc,
	std::list<ptrEntity> &&list) : direction(dir), source(src), destination(dest), isOpen(0), Entity(type, name, desc, std::move(list)) {}