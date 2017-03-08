#ifndef NPC_H
#define NPC_H

class Entity;
class Room;
class Npc : public Entity
{
public:

	Npc(Room *loc, Type type, const std::string &name, const std::string &desc, std::list<Entity*> list);
	~Npc();

	Room *location;
	Type type;
	std::string name;
	std::string description;
	std::list<Entity*> contains;
};



#endif // !NPC_H

