#include "globals.h"
#include "world.h"
#include <iostream>
#include <list>
#include "literals.h"


World::World(){}

void World::Init()
{
	//Init scenario names
	scenarioNames[Scenario::CELL] = std::string("CELL");
	scenarioNames[Scenario::AISLE1] = std::string("AISLE1");
	scenarioNames[Scenario::AISLE2] = std::string("AISLE2");
	scenarioNames[Scenario::AISLE3] = std::string("AISLE3");
	scenarioNames[Scenario::ARMORY] = std::string("ARMORY");
	scenarioNames[Scenario::GUARDROOM] = std::string("GUARDROOM");
	scenarioNames[Scenario::TOOLROOM] = std::string("TOOLROOM");
	scenarioNames[Scenario::UPSTAIRS] = std::string("UPSTAIRS");
	scenarioNames[Scenario::GUARDS_BEDROOM] = std::string("GUARDS_BEDROOM");
	scenarioNames[Scenario::MEETINGS_ROOM] = std::string("MEETINGS_ROOM");
	scenarioNames[Scenario::MAIN_HALL] = std::string("MAIN_HALL");

	//Load literals
	LoadLiterals();
	
	//INSTANTIATE ITEMS (including weapons and armors)
	//cell
	mattress = ptrItem(new Item(cell, false, Type::ITEM, CELL_MATTRESS, CELL_LOOK_MATTRESS, {}));
	breadcrumbs = ptrItem(new Item(cell, false, Type::ITEM, CELL_BREADCRUMBS, CELL_LOOK_BREADCRUMBS, {}));
	bowl = ptrItem(new Item(cell, false, Type::ITEM, CELL_BOWL, CELL_LOOK_BOWL, {breadcrumbs}));
	pigeon = ptrItem(new Item(window, false, Type::ITEM, CELL_PIGEON, CELL_LOOK_PIGEON, {}));
	bar = ptrItem(new Item(window, false, Type::ITEM, CELL_IRON_BAR, CELL_LOOK_IRON_BAR, {}));
	window = ptrItem(new Item(cell, false, Type::ITEM, CELL_WINDOW, CELL_LOOK_WINDOW, {bar,pigeon, windowExit}));

	//aisle1
	chairAisle1 = ptrItem(new Item(aisle1, false, Type::ITEM, CHAIR, LOOK_CHAIR, {}));
	desk = ptrItem(new Item(aisle1, false, Type::ITEM, AISLE1_DESK, AISLE1_LOOK_DESK, {}));
	cellKey = ptrItem(new Item(guardAisle1, false, Type::ITEM, CELL_KEY, CELL_LOOK_KEY, {}));
	aisle1GuardSword = ptrWeapon(new Weapon(false, 5, guardAisle1, false, Type::WEAPON, CELL_GUARD_SWORD, CELL_GUARD_SWORD, {}));

	//armory
	shield = ptrArmor(new Armor(0, armory, false, Type::ITEM, ARMORY_SHIELD, ARMORY_LOOK_SHIELD, {}));
	armoryCloset = ptrItem(new Item(armory, false, Type::ITEM, ARMORY_CLOSET, ARMORY_LOOK_CLOSET, {}));

	//guardroom
	chairGuardroom = ptrItem(new Item(guardroom, false, Type::ITEM, CHAIR, LOOK_CHAIR, {}));
	smallClosetGuardRoom = ptrItem(new Item(guardroom, false, Type::ITEM, GUARDROOM_CLOSED_CLOSET, GUARDROOM_LOOK_CLOSED_CLOSET, { armoryKey,cleaningStaffKey }));
	armoryKey = ptrItem(new Item(smallClosetGuardRoom, false, Type::ITEM, GUARDROOM_KEY, GUARDROOM_KEY, {}));
	cleaningStaffKey = ptrItem(new Item(smallClosetGuardRoom, false, Type::ITEM,  GUARDROOM_KEY, GUARDROOM_KEY, {}));

	//toolroom
	rope = ptrItem(new Item(toolsCloset, false, Type::ITEM, TOOLROOM_ROPE, TOOLROOM_LOOK_ROPE, {}));
	twoHandedMace = ptrWeapon(new Weapon(false, 8, toolroom, false, Type::ITEM, TOOLROOM_TWOHANDED_MACE, TOOLROOM_LOOK_TWOHANDED_MACE, {}));
	toolsCloset = ptrItem(new Item(toolroom, false, Type::ITEM, TOOLROOM_CLOSET, TOOLROOM_CLOSET, {rope}));

	//guards bedroom
	wardrobe = ptrItem(new Item(guardsBedroom, false, Type::ITEM, GUARDS_BEDROOM_CLOSED_WARDROBE, GUARDS_BEDROOM_LOOK_CLOSED_WARDROBE, { guardClothes }));
	guardClothes = ptrItem(new Item(wardrobe, false, Type::ITEM, GUARDS_BEDROOM_LOOK_CLOTHES, GUARDS_BEDROOM_LOOK_CLOTHES, {}));
	bagOfCoins = ptrItem(new Item(guardSleeping, false, Type::ITEM, GUARDS_BEDROOM_LOOK_BAG_OF_COINS, GUARDS_BEDROOM_LOOK_BAG_OF_COINS, {coins}));
	coins = ptrItem(new Item(bagOfCoins, false, Type::ITEM, GUARDS_BEDROOM_LOOK_COINS, GUARDS_BEDROOM_LOOK_COINS, {}));
	leatherCuirass = ptrArmor(new Armor(5,guardSleeping, false, Type::ITEM, GUARDS_BEDROOM_CUIRASS, GUARDS_BEDROOM_LOOK_CUIRASS, {}));
	helmet = ptrArmor(new Armor(2, guardsBedroom, false, Type::ITEM, GUARDS_BEDROOM_HELMET, GUARDS_BEDROOM_LOOK_HELMET, {}));

	//meetings room
	tableMeetingsRoom = ptrItem(new Item(meetingsRoom, false, Type::ITEM, MEETINGS_ROOM_LOOK_LARGE_TABLE, MEETINGS_ROOM_LOOK_LARGE_TABLE, {}));
	chairMeetingsRoom1 = ptrItem(new Item(meetingsRoom, false, Type::ITEM, CHAIR, CHAIR, {}));
	chairMeetingsRoom2 = ptrItem(new Item(meetingsRoom, false, Type::ITEM, CHAIR, CHAIR, {}));
	chairMeetingsRoom3 = ptrItem(new Item(meetingsRoom, false, Type::ITEM, CHAIR, CHAIR, {}));
	chairMeetingsRoom4 = ptrItem(new Item(meetingsRoom, false, Type::ITEM, CHAIR, CHAIR, {}));
	officerSword = ptrWeapon(new Weapon(false, 5, officerMeetingRoom, false, Type::WEAPON, MEETINGS_ROOM_OFFICER_SWORD, MEETINGS_ROOM_LOOK_OFFICER_SWORD, {}));

	//INSTANTIATE ROOMS
	cell = ptrRoom(new Room(Type::ROOM, CELL_TITLE, CELL_INIT_DESC, { mattress, bowl, cellDoorExit, windowExit}));
	aisle1 = ptrRoom(new Room(Type::ROOM, AISLE1_TITLE, AISLE1_INIT_DESC, { aisle1WestExit, aisle1DoorExit }));
	aisle2 = ptrRoom(new Room(Type::ROOM, AISLE2_TITLE, AISLE2_INIT_DESC, { aisle2WestExit, aisle2ArmoryExit, aisle2GuadroomExit, aisle2EastExit }));
	aisle3 = ptrRoom(new Room(Type::ROOM, AISLE3_TITLE, AISLE3_INIT_DESC, { aisle3WestExit, aisle3NorthExit, aisle3ToolroomExit }));
	armory = ptrRoom(new Room(Type::ROOM, ARMORY_TITLE, ARMORY_INIT_DESC, {shield, armoryCloset, armoryDoorExit}));
	guardroom = ptrRoom(new Room(Type::ROOM, GUARDROOM_TITLE, GUARDROOM_INIT_DESC, { chairGuardroom, smallClosetGuardRoom, armoryKey, cleaningStaffKey, guardroomExit}));
	toolroom = ptrRoom(new Room(Type::ROOM, TOOLROOM_TITLE, TOOLROOM_INIT_DESC, { twoHandedMace, toolsCloset, toolroomExit }));
	upstairs = ptrRoom(new Room(Type::ROOM, UPSTAIRS_TITLE, TOOLROOM_INIT_DESC, {upstairsSouthExit,upstairsNorthExit, upstairsWestExit, upstairsEastExit}));
	guardsBedroom = ptrRoom(new Room(Type::ROOM, GUARDS_BEDROOM_TITLE, GUARDS_BEDROOM_INIT_DESC, { wardrobe, leatherCuirass, helmet, guardsBedroomExit }));
	meetingsRoom = ptrRoom(new Room(Type::ROOM, MEETINGS_ROOM_TITLE, MEETINGS_ROOM_INIT_DESC, {tableMeetingsRoom, chairMeetingsRoom1, chairMeetingsRoom2, chairMeetingsRoom3, chairMeetingsRoom4, meetingsRoomExit, }));
	mainHall = ptrRoom(new Room(Type::ROOM, MAIN_HALL_TITLE, MAIN_HALL_INIT_DESC, {mainHallWestExit, mainHallDoorExit}));

	//INSTANTIATE EXITS
	//cell
	windowExit = ptrExit(new Exit(Direction::WEST, cell, nullptr, false, Type::EXIT, CELL_WINDOW, CELL_LOOK_WINDOW, {}));
	cellDoorExit = ptrExit(new Exit(Direction::EAST, cell, aisle1, false, Type::EXIT, CELL_LOOK_DOOR, CELL_LOOK_DOOR, {}));

	//aisle1
	aisle1DoorExit = ptrExit(new Exit(Direction::EAST, aisle1, aisle2, false, Type::EXIT, DOOR_DESC, DOOR_DESC, {}));
	aisle1WestExit = ptrExit(new Exit(Direction::WEST, aisle1, cell, false, Type::EXIT, EXIT_DESC, EXIT_DESC, {}));

	//aisle2
	aisle2WestExit = ptrExit(new Exit(Direction::WEST, aisle2, aisle1, false, Type::EXIT, DOOR_DESC, DOOR_DESC, {}));
	aisle2ArmoryExit = ptrExit(new Exit(Direction::SOUTH, aisle2, armory, false, Type::EXIT, DOOR_DESC, DOOR_DESC, {}));
	aisle2GuadroomExit = ptrExit(new Exit(Direction::NORTH, aisle2, guardroom, false, Type::EXIT, DOOR_DESC, DOOR_DESC, {}));
	aisle2EastExit = ptrExit(new Exit(Direction::EAST, aisle2, aisle3, true, Type::EXIT, EXIT_DESC, EXIT_DESC, {}));

	//armory
	armoryDoorExit = ptrExit(new Exit(Direction::NORTH, armory, aisle2, false, Type::EXIT, DOOR_DESC, DOOR_DESC, {}));

	//guardroom
	guardroomExit = ptrExit(new Exit(Direction::SOUTH, guardroom, aisle2, false, Type::EXIT, DOOR_DESC,  DOOR_DESC, {}));

	//aisle3
	aisle3WestExit = ptrExit(new Exit(Direction::WEST, aisle3, aisle2, true, Type::EXIT, EXIT_DESC, EXIT_DESC, {}));
	aisle3NorthExit = ptrExit(new Exit(Direction::NORTH, aisle3, upstairs, true, Type::EXIT, EXIT_STAIRS_DESC, EXIT_STAIRS_DESC, {}));
	aisle3ToolroomExit = ptrExit(new Exit(Direction::SOUTH, aisle3, toolroom, true, Type::EXIT, DOOR_DESC, DOOR_DESC, {}));

	//toolroom
	toolroomExit = ptrExit(new Exit(Direction::NORTH, toolroom, aisle3, true, Type::EXIT, DOOR_DESC, DOOR_DESC, {}));

	//upstairs floor
	upstairsSouthExit = ptrExit(new Exit(Direction::SOUTH, upstairs, aisle3, true, Type::EXIT, EXIT_STAIRS_DESC, EXIT_STAIRS_DESC, {}));
	upstairsNorthExit = ptrExit(new Exit(Direction::NORTH, upstairs, meetingsRoom, false, Type::EXIT, DOOR_DESC, DOOR_DESC, {}));
	upstairsWestExit = ptrExit(new Exit(Direction::WEST, upstairs, guardsBedroom, false, Type::EXIT, DOOR_DESC, DOOR_DESC, {}));
	upstairsEastExit = ptrExit(new Exit(Direction::EAST, upstairs, mainHall, true, Type::EXIT, EXIT_DESC, EXIT_DESC, {}));

	//Guards bedroom 
	guardsBedroomExit = ptrExit(new Exit(Direction::EAST, guardsBedroom, upstairs, false, Type::EXIT, DOOR_DESC, DOOR_DESC, {}));

	//meetings room
	meetingsRoomExit = ptrExit(new Exit(Direction::SOUTH, meetingsRoom, upstairs, false, Type::EXIT, DOOR_DESC, DOOR_DESC, {}));

	//main hall
	mainHallWestExit = ptrExit(new Exit(Direction::WEST, mainHall, upstairs, false, Type::EXIT, EXIT_DESC, EXIT_DESC, {}));
	mainHallDoorExit = ptrExit(new Exit(Direction::EAST, mainHall, nullptr, false, Type::EXIT, MAIN_HALL_STREET_EXIT, MAIN_HALL_STREET_EXIT, {}));

	//INSTANTIATE CREATURES
	guardAisle1 = ptrCreature(new Npc(false, aisle1, 15, 5, 0, Type::NPC, GUARD, CELL_LOOK_GUARD, { cellKey, aisle1GuardSword}));
	guardToolRoom = ptrCreature(new Npc(false, toolroom, 15, 5, 8, Type::NPC, GUARD, TOOLROOM_GUARD_ALIVE, {}));
	guardSleeping = ptrCreature(new Npc(false, guardsBedroom, 15, 5, 0, Type::NPC, GUARD, GUARDS_BEDROOM_LOOK_GUARD_ALIVE, {bagOfCoins}));
	officerMeetingRoom = ptrCreature(new Npc(false, meetingsRoom, 20, 10, 5, Type::NPC, OFFICER, MEETINGS_ROOM_LOOK_OFFICER_ALIVE, { mainHallDoorKey, officerSword }));

	
	std::cout << "<><><><>  WELCOME TO ZORKY <><><><>" << std::endl;
	std::cout <<  GAME_INTRO  << std::endl;
}

ReturnState World::Start()
{	
	ptrEntity location = GetLocation(scenarioGlobal);
	if (nullptr == location)
	{
		std::cout << "Error on Start()\n";
		return ReturnState::ERROR;
	}
	std::cout << "****" << location->name << "****" << std::endl;
	std::cout << location->description << std::endl;

	return ReturnState::CONTINUE;
}

ReturnState World::Update()
{
	scenarioGlobal = Scenario::CELL;

	return ReturnState::CONTINUE;
}

void World::LoadLiterals() 
{
	literalsMap["CELL_TITLE"] = CELL_TITLE;
	literalsMap["CELL_INIT_DESC"] = CELL_INIT_DESC;
	literalsMap["CELL_MATTRESS"] = CELL_MATTRESS;
	literalsMap["CELL_LOOK_MATTRESS"] = CELL_LOOK_MATTRESS;
	literalsMap["CELL_BOWL"] = CELL_BOWL;
	literalsMap["CELL_LOOK_BOWL"] = CELL_LOOK_BOWL;
	literalsMap["CELL_PIGEON"] = CELL_PIGEON;
	literalsMap["CELL_LOOK_PIGEON"] = CELL_LOOK_PIGEON;
	literalsMap["CELL_IRON_BAR"] = CELL_IRON_BAR;
	literalsMap["CELL_LOOK_IRON_BAR"] = CELL_LOOK_IRON_BAR;
	literalsMap["CELL_BREADCRUMBS"] = CELL_BREADCRUMBS;
	literalsMap["CELL_LOOK_BREADCRUMBS"] = CELL_LOOK_BREADCRUMBS;
	literalsMap["CELL_LOOK_WINDOW_NO_BARS"] = CELL_LOOK_WINDOW_NO_BARS;
	literalsMap["CELL_WINDOW"] = CELL_WINDOW;
	literalsMap["CELL_LOOK_WINDOW"] = CELL_LOOK_WINDOW;
	literalsMap["CELL_LOOK_DOOR"] = CELL_LOOK_DOOR;
	literalsMap["CELL_LOOK_GUARD"] = CELL_LOOK_GUARD;
	literalsMap["CELL_LOOK_DEAD_GUARD"] = CELL_LOOK_DEAD_GUARD;
	literalsMap["CELL_SEARCH_GUARD_DEAD"] = CELL_SEARCH_GUARD_DEAD;
	literalsMap["CELL_SEARCH_GUARD_ALIVE"] = CELL_SEARCH_GUARD_ALIVE;
	literalsMap["CELL_KEY"] = CELL_KEY;
	literalsMap["CELL_LOOK_KEY"] = CELL_LOOK_KEY;
	literalsMap["CELL_GUARD_SWORD"] = CELL_GUARD_SWORD;
	
	literalsMap["CELL_EXIT_HIT_MACE"] = CELL_EXIT_HIT_MACE;
	literalsMap["CELL_EXIT_HIT_BAREHANDED"] = CELL_EXIT_HIT_BAREHANDED;
	literalsMap["CELL_EXIT_COMBINE_ROPE_SWORD"] = CELL_EXIT_COMBINE_ROPE_SWORD;
	literalsMap["CELL_EXIT_USE_ROPE"] = CELL_EXIT_USE_ROPE;
	literalsMap["CELL_EXIT_SUCCESS"] = CELL_EXIT_SUCCESS;

	literalsMap["AISLE1_TITLE"] = AISLE1_TITLE;
	literalsMap["AISLE1_INIT_DESC"] = AISLE1_INIT_DESC;
	literalsMap["AISLE1_LOOK_DOOR"] = AISLE1_LOOK_DOOR;
	literalsMap["AISLE1_DESK"] = AISLE1_DESK;
	literalsMap["AISLE1_LOOK_DESK"] = AISLE1_LOOK_DESK;

	literalsMap["AISLE2_TITLE"] = AISLE2_TITLE;
	literalsMap["AISLE2_INIT_DESC"] = AISLE2_INIT_DESC;
	literalsMap["AISLE2_LOOK_NORTH_DOOR"] = AISLE2_LOOK_NORTH_DOOR;
	literalsMap["AISLE2_LOOK_SOUTH_DOOR"] = AISLE2_LOOK_SOUTH_DOOR;

	literalsMap["AISLE3_TITLE"] = AISLE3_TITLE;
	literalsMap["AISLE3_INIT_DESC"] = AISLE3_INIT_DESC;
	literalsMap["AISLE3_LOOK_UPSTAIRS"] = AISLE3_LOOK_UPSTAIRS;
	literalsMap["AISLE3_LOOK_SOUTH_DOOR"] = AISLE3_LOOK_SOUTH_DOOR;

	literalsMap["ARMORY_TITLE"] = ARMORY_TITLE;
	literalsMap["ARMORY_INIT_DESC"] = ARMORY_INIT_DESC;
	literalsMap["ARMORY_CLOSET"] = ARMORY_CLOSET;
	literalsMap["ARMORY_LOOK_CLOSET"] = ARMORY_LOOK_CLOSET;
	literalsMap["ARMORY_SHIELD"] = ARMORY_SHIELD;
	literalsMap["ARMORY_LOOK_SHIELD"] = ARMORY_LOOK_SHIELD;
	literalsMap["ARMORY_CANT_TAKE_SHIELD"] = ARMORY_CANT_TAKE_SHIELD;

	literalsMap["GUARDROOM_TITLE"] = GUARDROOM_TITLE;
	literalsMap["GUARDROOM_INIT_DESC"] = GUARDROOM_INIT_DESC;
	literalsMap["GUARDROOM_LOOK_CLOSED_CLOSET"] = GUARDROOM_LOOK_CLOSED_CLOSET;
	literalsMap["GUARDROOM_CLOSED_CLOSET"] = GUARDROOM_CLOSED_CLOSET;
	literalsMap["GUARDROOM_LOOK_OPEN_CLOSET"] = GUARDROOM_LOOK_OPEN_CLOSET;
	literalsMap["GUARDROOM_KEY"] = GUARDROOM_KEY;

	literalsMap["TOOLROOM_TITLE"] = TOOLROOM_TITLE;
	literalsMap["TOOLROOM_INIT_DESC"] = TOOLROOM_INIT_DESC;
	literalsMap["TOOLROOM_LOOK_CLOSET_LOCKED"] = TOOLROOM_LOOK_CLOSET_LOCKED;
	literalsMap["TOOLROOM_CLOSET"] = TOOLROOM_CLOSET;
	literalsMap["TOOLROOM_ROPE"] = TOOLROOM_ROPE;
	literalsMap["TOOLROOM_LOOK_ROPE"] = TOOLROOM_LOOK_ROPE;
	literalsMap["TOOLROOM_TWOHANDED_MACE"] = TOOLROOM_TWOHANDED_MACE;
	literalsMap["TOOLROOM_LOOK_TWOHANDED_MACE"] = TOOLROOM_LOOK_TWOHANDED_MACE;
	literalsMap["TOOLROOM_GUARD_ALIVE"] = TOOLROOM_GUARD_ALIVE;
	literalsMap["TOOLROOM_GUARD_DEAD"] = TOOLROOM_GUARD_DEAD;
	literalsMap["TOOLROOM_SEARCH_GUARD"] = TOOLROOM_SEARCH_GUARD;
	literalsMap["TOOLROOM_PLAYER_DEAD"] = TOOLROOM_PLAYER_DEAD;

	literalsMap["UPSTAIRS_TITLE"] = UPSTAIRS_TITLE;
	literalsMap["UPSTAIRS_INIT_DESC"] = UPSTAIRS_INIT_DESC;
	literalsMap["UPSTAIRS_DESC_GUARD_DEAD"] = UPSTAIRS_DESC_GUARD_DEAD;
	literalsMap["UPSTAIRS_LOOK_NORTH_DOOR"] = UPSTAIRS_LOOK_NORTH_DOOR;
	literalsMap["UPSTAIRS_LOOK_WEST_DOOR"] = UPSTAIRS_LOOK_WEST_DOOR;
	literalsMap["UPSTAIRS_LOOK_EAST"] = UPSTAIRS_LOOK_EAST;

	literalsMap["GUARDS_BEDROOM_TITLE"] = GUARDS_BEDROOM_TITLE;
	literalsMap["GUARDS_BEDROOM_INIT_DESC"] = GUARDS_BEDROOM_INIT_DESC;
	literalsMap["GUARDS_BEDROOM_GUARD_ALIVE"] = GUARDS_BEDROOM_GUARD_ALIVE;
	literalsMap["GUARDS_BEDROOM_LOOK_GUARD_ALIVE"] = GUARDS_BEDROOM_LOOK_GUARD_ALIVE;
	literalsMap["GUARDS_BEDROOM_LOOK_GUARD_DEAD"] = GUARDS_BEDROOM_LOOK_GUARD_DEAD;
	literalsMap["GUARDS_BEDROOM_SEARCH_GUARD_ALIVE"] = GUARDS_BEDROOM_SEARCH_GUARD_ALIVE;
	literalsMap["GUARDS_BEDROOM_SEARCH_GUARD_DEAD"] = GUARDS_BEDROOM_SEARCH_GUARD_DEAD;
	literalsMap["GUARDS_BEDROOM_CLOSED_WARDROBE"] = GUARDS_BEDROOM_CLOSED_WARDROBE;
	literalsMap["GUARDS_BEDROOM_LOOK_CLOSED_WARDROBE"] = GUARDS_BEDROOM_LOOK_CLOSED_WARDROBE;
	literalsMap["GUARDS_BEDROOM_LOOK_OPEN_WARDROBE"] = GUARDS_BEDROOM_LOOK_OPEN_WARDROBE;
	literalsMap["GUARDS_BEDROOM_LOOK_CLOTHES"] = GUARDS_BEDROOM_LOOK_CLOTHES;
	literalsMap["GUARDS_BEDROOM_LOOK_BAG_OF_COINS"] = GUARDS_BEDROOM_LOOK_BAG_OF_COINS;
	literalsMap["GUARDS_BEDROOM_LOOK_COINS"] = GUARDS_BEDROOM_LOOK_COINS;
	literalsMap["GUARDS_BEDROOM_CUIRASS"] = GUARDS_BEDROOM_CUIRASS;
	literalsMap["GUARDS_BEDROOM_LOOK_CUIRASS"] = GUARDS_BEDROOM_LOOK_CUIRASS;
	literalsMap["GUARDS_BEDROOM_HELMET"] = GUARDS_BEDROOM_HELMET;
	literalsMap["GUARDS_BEDROOM_LOOK_HELMET"] = GUARDS_BEDROOM_LOOK_HELMET;

	literalsMap["MEETINGS_ROOM_TITLE"] = MEETINGS_ROOM_TITLE;
	literalsMap["MEETINGS_ROOM_INIT_DESC"] = MEETINGS_ROOM_INIT_DESC;
	literalsMap["MEETINGS_ROOM_LOOK_OFFICER_ALIVE"] = MEETINGS_ROOM_LOOK_OFFICER_ALIVE;
	literalsMap["MEETINGS_ROOM_LOOK_OFFICER_DEAD"] = MEETINGS_ROOM_LOOK_OFFICER_DEAD;
	literalsMap["MEETINGS_ROOM_SEARCH_OFFICER_DEAD"] = MEETINGS_ROOM_SEARCH_OFFICER_DEAD;
	literalsMap["MEETINGS_ROOM_PLAYER_DEAD"] = MEETINGS_ROOM_PLAYER_DEAD;
	literalsMap["MEETINGS_ROOM_LOOK_LARGE_TABLE"] = MEETINGS_ROOM_LOOK_LARGE_TABLE;
	literalsMap["MEETINGS_ROOM_OFFICER_SWORD"] = MEETINGS_ROOM_OFFICER_SWORD;
	literalsMap["MEETINGS_ROOM_LOOK_OFFICER_SWORD"] = MEETINGS_ROOM_LOOK_OFFICER_SWORD;

	literalsMap["MAIN_HALL_TITLE"] = MAIN_HALL_TITLE;
	literalsMap["MAIN_HALL_INIT_DESC"] = MAIN_HALL_INIT_DESC;
	literalsMap["MAIN_HALL_STREET_EXIT"] = MAIN_HALL_STREET_EXIT;

	literalsMap["MAIN_HALL_EXIT_NO_CLOTHES_NO_MONEY"] = MAIN_HALL_EXIT_NO_CLOTHES_NO_MONEY;
	literalsMap["MAIN_HALL_EXIT_NO_CLOTHES_WITH_MONEY"] = MAIN_HALL_EXIT_NO_CLOTHES_WITH_MONEY;
	literalsMap["MAIN_HALL_BRIBE_SUCCESS"] = MAIN_HALL_BRIBE_SUCCESS;
	literalsMap["MAIN_HALL_BRIBE_FAILURE"] = MAIN_HALL_BRIBE_FAILURE;
	literalsMap["MAIN_HALL_EXIT_GUARD_CLOTHES"] = MAIN_HALL_EXIT_GUARD_CLOTHES;
	literalsMap["MAIN_HALL_EXIT_SUCCESS"] = MAIN_HALL_EXIT_SUCCESS;

	literalsMap["BAD_IDEA"] = BAD_IDEA;
	literalsMap["CANT_DO"] = CANT_DO;
	literalsMap["DOOR_LOCKED"] = DOOR_LOCKED;
	literalsMap["GAME_INTRO"] = GAME_INTRO;
	literalsMap["DONT_UNDERSTAND"] = DONT_UNDERSTAND;
	literalsMap["NOT_DOING_THAT"] = NOT_DOING_THAT;
	literalsMap["EXIT_DESC"] = EXIT_DESC;
	literalsMap["DOOR"] = DOOR;
	literalsMap["DOOR_DESC"] = DOOR_DESC;
	literalsMap["EXIT_STAIRS_DESC"] = EXIT_STAIRS_DESC;
	literalsMap["CHAIR"] = CHAIR;
	literalsMap["LOOK_CHAIR"] = LOOK_CHAIR;
	literalsMap["GUARD"] = GUARD;
	literalsMap["OFFICER"] = OFFICER;




	
}

World::ptrEntity World::GetLocation(const Scenario& sc) const{
	
	switch (sc) {
		case Scenario::CELL:
			return cell;
			break;
		case Scenario::AISLE1:
			return aisle1;
			break;
		case Scenario::AISLE2:
			return aisle2;
			break;			
		case Scenario::AISLE3:
			return aisle3;
			break;
		case Scenario::ARMORY:
			return armory;
			break;
		case Scenario::GUARDROOM:
			return guardroom;
			break;
		case Scenario::TOOLROOM:
			return toolroom;
			break;
		case Scenario::UPSTAIRS:
			return upstairs;
			break;
		case Scenario::GUARDS_BEDROOM:
			return guardsBedroom;
			break;
		case Scenario::MEETINGS_ROOM:
			return meetingsRoom;
			break;
		case Scenario::MAIN_HALL:
			return mainHall;
			break;
		case Scenario::MAIN_HALL_EXIT:
			return mainHallDoorExit;
			break;
		case Scenario::CELL_EXIT:
			return windowExit;
			break;
		default:
			return nullptr;
	}
}