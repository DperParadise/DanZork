#include "exit.h"

Exit::Exit(
	Direction dir,
	ptrRoom src,
	ptrRoom dest,
	bool isOpen,
	bool isLocked,
	Type type,
	const std::string &name,
	const std::string &desc,
	std::list<ptrEntity> &&list) : direction(dir), source(src), destination(dest), isOpen(), isLocked(isLocked), Entity(type, name, desc, std::move(list)) {}