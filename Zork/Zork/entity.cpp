#include "entity.h"

using namespace std;

Entity::Entity() {};
Entity::Entity(Type t, string n, string d, list<Entity*> l) : type(t), name(n), description(d), contains(std::move(l)) {};
Entity::~Entity() {};