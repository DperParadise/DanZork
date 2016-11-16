#ifndef WORLD_H
#define WORLD_H

#include "globals.h"
#include "entity.h"
#include "room.h"
#include "item.h"
#include "creature.h"
#include "npc.h"
#include "player.h"
#include "exit.h"
#include <memory>
#include <map>
#include "armor.h"
#include "weapon.h"

class World
{
public:

	typedef  std::shared_ptr<Creature> ptrCreature;
	typedef  std::shared_ptr<Room> ptrRoom;
	typedef  std::shared_ptr<Item> ptrItem;
	typedef  std::shared_ptr<Exit> ptrExit;
	typedef  std::shared_ptr<Weapon> ptrWeapon;
	typedef  std::shared_ptr<Armor> ptrArmor;
	typedef  std::shared_ptr<Entity> ptrEntity;
	

	World();
	void Init();
	ReturnState Start();
	ReturnState Update();

private:

	std::map<Scenario, std::string> scenarioNames;
	std::map<std::string, std::string> literalsMap;
	std::vector<std::string> playerWordsVector;
	std::string playerCleanInput;

	//void LoadLiterals();
	ptrEntity GetLocation(const Scenario& sc) const;

;	////ITEMS (including weapons and armors)
	//cell
	ptrItem mattress;
	ptrItem bowl;
	ptrItem pigeon;
	ptrItem bar;
	ptrItem breadcrumbs;
	ptrItem window;
	

	//aisle1
	ptrItem chairAisle1;
	ptrItem desk;
	ptrItem cellKey;
	ptrWeapon aisle1GuardSword;

	//armory
	ptrArmor shield;
	ptrItem armoryCloset;
	

	//guardroom
	ptrItem chairGuardroom;
	ptrItem armoryKey;
	ptrItem cleaningStaffKey;
	ptrItem smallClosetGuardRoom;

	//toolroom
	ptrItem rope;
	ptrWeapon twoHandedMace;
	ptrItem toolsCloset;
	
	//guards bedroom
	ptrItem wardrobe;
	ptrItem guardClothes;
	ptrItem bagOfCoins;
	ptrArmor leatherCuirass;
	ptrArmor helmet;
	ptrItem coins;

	//meetings room
	ptrItem tableMeetingsRoom;
	ptrItem chairMeetingsRoom1;
	ptrItem chairMeetingsRoom2;
	ptrItem chairMeetingsRoom3;
	ptrItem chairMeetingsRoom4;
	ptrItem smallClosetMeetingsRoom;
	ptrItem mainHallDoorKey;
	ptrWeapon officerSword;

	//ROOMS
	ptrRoom cell;
	ptrRoom aisle1;
	ptrRoom aisle2;
	ptrRoom aisle3;
	ptrRoom armory;
	ptrRoom guardroom;
	ptrRoom toolroom;
	ptrRoom upstairs;
	ptrRoom guardsBedroom ;
	ptrRoom meetingsRoom;
	ptrRoom mainHall;
	
	//EXITS 
	//Cell
	ptrExit windowExit;
	ptrExit cellDoorExit;

	//Aisle1
	ptrExit aisle1DoorExit;
	ptrExit aisle1WestExit;

	//Aisle2
	ptrExit aisle2WestExit;
	ptrExit aisle2ArmoryExit;
	ptrExit aisle2GuadroomExit;
	ptrExit aisle2EastExit;

	//Armory
	ptrExit armoryDoorExit;

	//Guardroom
	ptrExit guardroomExit;

	//Aisle3
	ptrExit aisle3WestExit;
	ptrExit aisle3NorthExit;
	ptrExit aisle3ToolroomExit;

	//Toolroom
	ptrExit toolroomExit;

	//Upstairs floor
	ptrExit upstairsSouthExit;
	ptrExit upstairsNorthExit;
	ptrExit upstairsWestExit;
	ptrExit upstairsEastExit;

	//Guards bedroom
	ptrExit guardsBedroomExit;

	//Meetings room
	ptrExit meetingsRoomExit;

	//Main Hall
	ptrExit mainHallWestExit;
	ptrExit mainHallDoorExit;

	//CREATURES
	ptrCreature player;
	ptrCreature guardAisle1;
	ptrCreature guardToolRoom;
	ptrCreature guardSleeping;
	ptrCreature officerMeetingRoom;

};


#endif //WORLD_H


