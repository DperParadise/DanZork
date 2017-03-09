#include "player.h"
#include "entity.h"
#include "globals.h"

class Room;
Player::Player(
	Room *loc,
	Type type,
	const std::string &name,
	const std::string &desc,
	std::list<Entity*> list
	) : location(loc), Entity(type, name, desc, list) {}

Player::~Player()
{
	RELEASE(location);
}

void Player::Pickup(Item *item)
{

}

void Player::Drop(Item *item)
{

}

void Player::Open(Item *item)
{

}

void Player::Close(Item *item)
{

}

void Player::LookAt(Entity *entity)
{

}

void Player::Go(Direction dir)
{

}

void Player::UseWith(Item *item1, Item *item2)
{

}