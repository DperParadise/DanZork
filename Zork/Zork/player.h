#ifndef PLAYER_H
#define PLAYER_H

class Room;
class Player : public Entity
{
public:

	Player(Room *loc, Type type, const std::string &name, const std::string &desc, std::list<Entity*> list);
	~Player();

	Room *location;

	
};



#endif
