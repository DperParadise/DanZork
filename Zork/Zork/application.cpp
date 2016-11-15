#include "globals.h"
#include "application.h"
#include <list>

Application::Application(){}

void Application::Init()
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

	
	//INSTANTIATE ITEMS (including weapons and armors)
	//cell
	mattress = ptrItem(new Item(false,Type::ITEM, CELL_MATTRESS, CELL_LOOK_MATTRESS, {}));
	breadcrumbs = ptrItem(new Item(false, Type::ITEM, CELL_BREADCRUMBS, CELL_LOOK_BREADCRUMBS, {}));
	bowl = ptrItem(new Item(false, Type::ITEM, CELL_BOWL, CELL_LOOK_BOWL, {breadcrumbs}));
	pigeon = ptrItem(new Item(false, Type::ITEM, CELL_PIGEON, CELL_LOOK_PIGEON, {}));
	bar = ptrItem(new Item(false, Type::ITEM, CELL_IRON_BAR, CELL_LOOK_IRON_BAR, {}));
	window = ptrItem(new Item(false, Type::ITEM, CELL_WINDOW, CELL_LOOK_WINDOW, {bar,pigeon, windowExit}));

	//aisle1
	chairAisle1 = ptrItem(new Item(false, Type::ITEM, CHAIR, LOOK_CHAIR, {}));
	desk = ptrItem(new Item(false, Type::ITEM, AISLE1_DESK, AISLE1_LOOK_DESK, {}));
	cellKey = ptrItem(new Item(false, Type::ITEM, CELL_KEY, CELL_LOOK_KEY, {}));
	aisle1GuardSword = ptrWeapon(new Weapon(5, false, Type::WEAPON, CELL_GUARD_SWORD, CELL_GUARD_SWORD, {}));

	//armory
	shield = ptrArmor(new Armor(0,false, Type::ITEM, ARMORY_SHIELD, ARMORY_LOOK_SHIELD, {}));
	armoryCloset = ptrItem(new Item(false, Type::ITEM, ARMORY_CLOSET, ARMORY_LOOK_CLOSET, {}));

	//guardroom
	chairGuardroom = ptrItem(new Item(false, Type::ITEM, CHAIR, LOOK_CHAIR, {}));
	smallClosetGuardRoom = ptrItem(new Item(false, Type::ITEM, GUARDROOM_CLOSED_CLOSET, GUARDROOM_LOOK_CLOSED_CLOSET, { armoryKey,cleaningStaffKey }));
	armoryKey = ptrItem(new Item(false, Type::ITEM, GUARDROOM_KEY, GUARDROOM_KEY, {}));
	cleaningStaffKey = ptrItem(new Item(false, Type::ITEM,  GUARDROOM_KEY, GUARDROOM_KEY, {}));

	//toolroom
	rope = ptrItem(new Item(false, Type::ITEM, TOOLROOM_ROPE, TOOLROOM_LOOK_ROPE, {}));
	twoHandedMace = ptrWeapon(new Weapon(8,false, Type::ITEM, TOOLROOM_TWOHANDED_MACE, TOOLROOM_LOOK_TWOHANDED_MACE, {}));
	toolsCloset = ptrItem(new Item(false, Type::ITEM, TOOLROOM_CLOSET, TOOLROOM_CLOSET, {rope}));

	//guards bedroom
	wardrobe = ptrItem(new Item(false, Type::ITEM, GUARDS_BEDROOM_CLOSED_WARDROBE, GUARDS_BEDROOM_LOOK_CLOSED_WARDROBE, { guardClothes }));
	guardClothes = ptrItem(new Item(false, Type::ITEM, GUARDS_BEDROOM_LOOK_CLOTHES, GUARDS_BEDROOM_LOOK_CLOTHES, {}));
	bagOfCoins = ptrItem(new Item(false, Type::ITEM, GUARDS_BEDROOM_LOOK_BAG_OF_COINS, GUARDS_BEDROOM_LOOK_BAG_OF_COINS, {coins}));
	coins = ptrItem(new Item(false, Type::ITEM, GUARDS_BEDROOM_LOOK_COINS, GUARDS_BEDROOM_LOOK_COINS, {}));
	leatherCuirass = ptrArmor(new Armor(5,false, Type::ITEM, GUARDS_BEDROOM_CUIRASS, GUARDS_BEDROOM_LOOK_CUIRASS, {}));
	helmet = ptrArmor(new Armor(2, false, Type::ITEM, GUARDS_BEDROOM_LOOK_HELMET, GUARDS_BEDROOM_LOOK_HELMET, {}));

	//meetings room
	tableMeetingsRoom = ptrItem(new Item(false, Type::ITEM, MEETINGS_ROOM_LOOK_LARGE_TABLE, MEETINGS_ROOM_LOOK_LARGE_TABLE, {}));
	chairMeetingsRoom1 = ptrItem(new Item(false, Type::ITEM, CHAIR, CHAIR, {}));
	chairMeetingsRoom2 = ptrItem(new Item(false, Type::ITEM, CHAIR, CHAIR, {}));
	chairMeetingsRoom3 = ptrItem(new Item(false, Type::ITEM, CHAIR, CHAIR, {}));
	chairMeetingsRoom4 = ptrItem(new Item(false, Type::ITEM, CHAIR, CHAIR, {}));
	officerSword = ptrWeapon(new Weapon(5, false, Type::WEAPON, MEETINGS_ROOM_OFFICER_SWORD, MEETINGS_ROOM_LOOK_OFFICER_SWORD, {}));

	//INSTANTIATE ROOMS
	cell = ptrRoom(new Room(Type::ROOM, CELL_TITLE, CELL_INIT_DESC, { mattress, bowl, cellDoorExit, windowExit}));
	aisle1 = ptrRoom(new Room(Type::ROOM, AISLE1_TITLE, AISLE1_INIT_DESC, { aisle1WestExit, aisle1DoorExit }));
	aisle2 = ptrRoom(new Room(Type::ROOM, AISLE2_TITLE, AISLE2_INIT_DESC, { aisle2WestExit, aisle2ArmoryExit, aisle2GuadroomExit, aisle2EastExit }));
	aisle3 = ptrRoom(new Room(Type::ROOM, AISLE3_TITLE, AISLE3_INIT_DESC, { aisle3WestExit, aisle3NorhtExit, aisle3ToolroomExit }));
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
	aisle3NorhtExit = ptrExit(new Exit(Direction::NORTH, aisle3, upstairs, true, Type::EXIT, EXIT_STAIRS_DESC, EXIT_STAIRS_DESC, {}));
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


}

void Application::Start()
{
	
}

ReturnState Application::Update()
{

	return ReturnState::CONTINUE;
}