#include "room.h"

Room::Room(
	Type type,
	const std::string &name,
	const std::string &desc,
	std::list<ptrEntity> &&list) : Entity(type, name, desc, std::move(list)) {}