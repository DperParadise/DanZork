#include "world.h"

using namespace std;

World::World(vector<Entity*> v) : entities(std::move(v)) {};
World::~World() {}