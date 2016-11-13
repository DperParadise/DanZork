#include "world.h"


World::World(std::vector<ptrEntity> v) : entities(std::move(v)) {}
World::~World() {}