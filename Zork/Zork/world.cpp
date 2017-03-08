#include "globals.h"
#include "commands.h"
#include "world.h"
#include <iostream>
#include <list>
#include <utility>
#include "literals.h"


void World::Init()
{
	//Init scenario names
	//scenarioNames[Scenario::CELL] = std::string("CELL");
	//scenarioNames[Scenario::AISLE1] = std::string("AISLE1");
	//scenarioNames[Scenario::AISLE2] = std::string("AISLE2");
	//scenarioNames[Scenario::AISLE3] = std::string("AISLE3");
	//scenarioNames[Scenario::ARMORY] = std::string("ARMORY");
	//scenarioNames[Scenario::GUARDROOM] = std::string("GUARDROOM");
	//scenarioNames[Scenario::TOOLROOM] = std::string("TOOLROOM");
	//scenarioNames[Scenario::UPSTAIRS] = std::string("UPSTAIRS");
	//scenarioNames[Scenario::GUARDS_BEDROOM] = std::string("GUARDS_BEDROOM");
	//scenarioNames[Scenario::MEETINGS_ROOM] = std::string("MEETINGS_ROOM");
	//scenarioNames[Scenario::MAIN_HALL] = std::string("MAIN_HALL");

	//Load literals
	//LoadLiterals();

	//INSTANTIATE EXITS
	//cell
	windowExit = ptrExit(new Exit(Direction::WEST, cell, nullptr, false, true, Type::EXIT, CELL_EXIT_WINDOW, CELL_EXIT_WINDOW, {}));
	cellDoorExit = ptrExit(new Exit(Direction::EAST, cell, aisle1, false, true, Type::EXIT, CELL_DOOR, CELL_LOOK_DOOR, {}));

	//aisle1
	aisle1DoorExit = ptrExit(new Exit(Direction::EAST, aisle1, aisle2, false, true, Type::EXIT, AISLE1_DOOR, DOOR_DESC, {}));
	aisle1WestExit = ptrExit(new Exit(Direction::WEST, aisle1, cell, false, true, Type::EXIT, EXIT_DESC, EXIT_DESC, {}));

	//aisle2
	aisle2WestExit = ptrExit(new Exit(Direction::WEST, aisle2, aisle1, false, true, Type::EXIT, DOOR, DOOR_DESC, {}));
	aisle2ArmoryExit = ptrExit(new Exit(Direction::SOUTH, aisle2, armory, false, true, Type::EXIT, DOOR, DOOR_DESC, {}));
	aisle2GuadroomExit = ptrExit(new Exit(Direction::NORTH, aisle2, guardroom, false, true, Type::EXIT, DOOR, DOOR_DESC, {}));
	aisle2EastExit = ptrExit(new Exit(Direction::EAST, aisle2, aisle3, false, false, Type::EXIT, EXIT_DESC, EXIT_DESC, {}));

	//armory
	armoryDoorExit = ptrExit(new Exit(Direction::NORTH, armory, aisle2, false, true,Type::EXIT, DOOR, DOOR_DESC, {}));

	//guardroom
	guardroomExit = ptrExit(new Exit(Direction::SOUTH, guardroom, aisle2, false, true, Type::EXIT, DOOR, DOOR_DESC, {}));

	//aisle3
	aisle3WestExit = ptrExit(new Exit(Direction::WEST, aisle3, aisle2, true, false, Type::EXIT, EXIT_DESC, EXIT_DESC, {}));
	aisle3NorthExit = ptrExit(new Exit(Direction::NORTH, aisle3, upstairs, true, false, Type::EXIT, EXIT_STAIRS_DESC, EXIT_STAIRS_DESC, {}));
	aisle3ToolroomExit = ptrExit(new Exit(Direction::SOUTH, aisle3, toolroom, true, false, Type::EXIT, DOOR, DOOR_DESC, {}));

	//toolroom
	toolroomExit = ptrExit(new Exit(Direction::NORTH, toolroom, aisle3, true, false, Type::EXIT, DOOR, DOOR_DESC, {}));

	//upstairs floor
	upstairsSouthExit = ptrExit(new Exit(Direction::SOUTH, upstairs, aisle3, true, false,Type::EXIT, EXIT_STAIRS_DESC, EXIT_STAIRS_DESC, {}));
	upstairsNorthExit = ptrExit(new Exit(Direction::NORTH, upstairs, meetingsRoom, false, false, Type::EXIT, DOOR, DOOR_DESC, {}));
	upstairsWestExit = ptrExit(new Exit(Direction::WEST, upstairs, guardsBedroom, false, false,Type::EXIT, DOOR, DOOR_DESC, {}));
	upstairsEastExit = ptrExit(new Exit(Direction::EAST, upstairs, mainHall, true, false,Type::EXIT, EXIT_DESC, EXIT_DESC, {}));

	//Guards bedroom 
	guardsBedroomExit = ptrExit(new Exit(Direction::EAST, guardsBedroom, upstairs, false, true, Type::EXIT, DOOR, DOOR_DESC, {}));

	//meetings room
	meetingsRoomExit = ptrExit(new Exit(Direction::SOUTH, meetingsRoom, upstairs, false, true, Type::EXIT, DOOR, DOOR_DESC, {}));

	//main hall
	mainHallWestExit = ptrExit(new Exit(Direction::WEST, mainHall, upstairs, true, false, Type::EXIT, EXIT_DESC, EXIT_DESC, {}));
	mainHallDoorExit = ptrExit(new Exit(Direction::EAST, mainHall, nullptr, false, true, Type::EXIT, MAIN_HALL_STREET_EXIT, MAIN_HALL_STREET_EXIT, {}));

	//INSTANTIATE ROOMS
	cell = ptrRoom(new Room(Type::ROOM, CELL_TITLE, CELL_INIT_DESC, {}));
	aisle1 = ptrRoom(new Room(Type::ROOM, AISLE1_TITLE, AISLE1_INIT_DESC, {}));
	aisle2 = ptrRoom(new Room(Type::ROOM, AISLE2_TITLE, AISLE2_INIT_DESC, {}));
	aisle3 = ptrRoom(new Room(Type::ROOM, AISLE3_TITLE, AISLE3_INIT_DESC, {}));
	armory = ptrRoom(new Room(Type::ROOM, ARMORY_TITLE, ARMORY_INIT_DESC, {}));
	guardroom = ptrRoom(new Room(Type::ROOM, GUARDROOM_TITLE, GUARDROOM_INIT_DESC, {}));
	toolroom = ptrRoom(new Room(Type::ROOM, TOOLROOM_TITLE, TOOLROOM_INIT_DESC, {}));
	upstairs = ptrRoom(new Room(Type::ROOM, UPSTAIRS_TITLE, TOOLROOM_INIT_DESC, {}));
	guardsBedroom = ptrRoom(new Room(Type::ROOM, GUARDS_BEDROOM_TITLE, GUARDS_BEDROOM_INIT_DESC, {}));
	meetingsRoom = ptrRoom(new Room(Type::ROOM, MEETINGS_ROOM_TITLE, MEETINGS_ROOM_INIT_DESC, {}));
	mainHall = ptrRoom(new Room(Type::ROOM, MAIN_HALL_TITLE, MAIN_HALL_INIT_DESC, {}));

	//UPDATE EXITS' ROOMS
	windowExit->source = cell;
	windowExit->destination = nullptr;

	cellDoorExit->source = cell;
	cellDoorExit->destination = aisle1;

	aisle1DoorExit->source = aisle1;
	aisle1DoorExit->destination = aisle2;

	aisle1WestExit->source = aisle1;
	aisle1WestExit->destination = cell;

	aisle2WestExit->source = aisle2;
	aisle2WestExit->destination = aisle1;

	aisle2ArmoryExit->source = aisle2;
	aisle2ArmoryExit->destination = armory;

	aisle2GuadroomExit->source = aisle2;
	aisle2GuadroomExit->destination = guardroom;

	aisle2EastExit->source = aisle2;
	aisle2EastExit->destination = aisle3;

	armoryDoorExit->source = armory;
	armoryDoorExit->destination = aisle2;

	guardroomExit->source = guardroom;
	guardroomExit->destination = aisle2;

	aisle3WestExit->source = aisle3;
	aisle3WestExit->destination = aisle2;

	aisle3NorthExit->source = aisle3;
	aisle3NorthExit->destination = upstairs;

	aisle3ToolroomExit->source = aisle3;
	aisle3ToolroomExit->destination = toolroom;

	toolroomExit->source = toolroom;
	toolroomExit->destination = aisle3;

	upstairsSouthExit->source = upstairs;
	upstairsSouthExit->destination = aisle3;

	upstairsNorthExit->source = upstairs;
	upstairsNorthExit->destination = meetingsRoom;

	upstairsWestExit->source = upstairs;
	upstairsWestExit->destination = guardsBedroom;

	upstairsEastExit->source = upstairs;
	upstairsEastExit->destination = mainHall;

	guardsBedroomExit->source = guardsBedroom;
	guardsBedroomExit->destination = upstairs;

	meetingsRoomExit->source = meetingsRoom;
	meetingsRoomExit->destination = upstairs;

	mainHallWestExit->source = mainHall;
	mainHallWestExit->destination = nullptr;
	
	//INSTANTIATE ITEMS (including weapons and armors)
	//cell
	mattress = ptrItem(new Item(cell, ItemSize::EXTRA_LARGE, false, false, Type::ITEM, CELL_MATTRESS, CELL_LOOK_MATTRESS, {}));
	breadcrumbs = ptrItem(new Item(cell, ItemSize::EXTRA_SMALL, false, false, Type::ITEM, CELL_BREADCRUMBS, CELL_LOOK_BREADCRUMBS, {}));
	//bowl = ptrItem(new Item(cell, ItemSize::SMALL, false, false, Type::ITEM, CELL_BOWL, CELL_LOOK_BOWL, {}));
	pigeon = ptrItem(new Item(nullptr, ItemSize::SMALL, false, false, Type::ITEM, CELL_PIGEON, CELL_LOOK_PIGEON, {}));
	bar = ptrItem(new Item(cell, ItemSize::MEDIUM, false, false, Type::ITEM, CELL_BAR, CELL_LOOK_IRON_BAR, {}));
	window = ptrItem(new Item(cell, ItemSize::SMALL, true, true, Type::ITEM, CELL_WINDOW, CELL_LOOK_WINDOW, {windowExit}));
	bar->parentEntity = cell;
	doorOpening = ptrItem(new Item(cell, ItemSize::EXTRA_LARGE, true, true, Type::ITEM, CELL_DOOR_OPENING, CELL_LOOK_DOOR_OPENING, {}));

	//aisle1
	chairAisle1 = ptrItem(new Item(aisle1, ItemSize::LARGE, false, false, Type::ITEM, CHAIR, LOOK_CHAIR, {}));
	desk = ptrItem(new Item(aisle1, ItemSize::LARGE, false, false, Type::ITEM, AISLE1_DESK, AISLE1_LOOK_DESK, {}));
	cellKey = ptrItem(new Item(nullptr, ItemSize::SMALL, false, false, Type::ITEM, CELL_KEY, CELL_LOOK_KEY, {}));
	aisle1GuardSword = ptrWeapon(new Weapon(100, nullptr,ItemSize::LARGE, Type::WEAPON, CELL_GUARD_SWORD, CELL_GUARD_SWORD, {}));

	//armory
	shield = ptrArmor(new Armor(0, armory, ItemSize::LARGE, Type::ITEM, ARMORY_SHIELD, ARMORY_LOOK_SHIELD, {}));
	armoryCloset = ptrItem(new Item(armory, ItemSize::EXTRA_LARGE, false, true, Type::ITEM, ARMORY_CLOSET, ARMORY_LOOK_CLOSET, {}));
	leatherCuirass = ptrArmor(new Armor(5, armory, ItemSize::LARGE, Type::ITEM, GUARDS_BEDROOM_CUIRASS, GUARDS_BEDROOM_LOOK_CUIRASS, {}));
	helmet = ptrArmor(new Armor(2, armory, ItemSize::MEDIUM, Type::ITEM, GUARDS_BEDROOM_HELMET, GUARDS_BEDROOM_LOOK_HELMET, {}));

	//guardroom
	chairGuardroom = ptrItem(new Item(guardroom, ItemSize::LARGE, false, false, Type::ITEM, CHAIR, LOOK_CHAIR, {}));
	smallClosetGuardRoom = ptrItem(new Item(guardroom, ItemSize::MEDIUM, false, true, Type::ITEM, GUARDROOM_CLOSED_CLOSET, GUARDROOM_LOOK_CLOSED_CLOSET, {}));
	armoryKey = ptrItem(new Item(smallClosetGuardRoom, ItemSize::SMALL, false, false, Type::ITEM, GUARDROOM_KEY, GUARDROOM_KEY, {}));
	cleaningStaffKey = ptrItem(new Item(smallClosetGuardRoom, ItemSize::SMALL, false, false, Type::ITEM, CLEANING_STAFF_KEY, CLEANING_STAFF_KEY, {}));
	smallClosetGuardRoom->contains = { armoryKey,cleaningStaffKey };
	rope = ptrItem(new Item(guardroom, ItemSize::LARGE, false, false, Type::ITEM, TOOLROOM_ROPE, TOOLROOM_LOOK_ROPE, {}));
	twoHandedMace = ptrItem(new Item(guardroom, ItemSize::LARGE, false, false, Type::ITEM, GUARDROOM_TWOHANDED_MACE, GUARDROOM_LOOK_TWOHANDED_MACE, {}));

	//toolroom
	toolsCloset = ptrItem(new Item(toolroom, ItemSize::EXTRA_LARGE, false, true,Type::ITEM, TOOLROOM_CLOSET, TOOLROOM_CLOSET, {}));
	/*rope = ptrItem(new Item(toolsCloset, false, Type::ITEM, TOOLROOM_ROPE, TOOLROOM_LOOK_ROPE, {}));
	twoHandedMace = ptrWeapon(new Weapon(false, 8, toolroom, false, Type::ITEM, TOOLROOM_TWOHANDED_MACE, TOOLROOM_LOOK_TWOHANDED_MACE, {}));*/
	toolsCloset->contains = { rope };

	//guards bedroom
	wardrobe = ptrItem(new Item(guardsBedroom, ItemSize::EXTRA_LARGE, false, true, Type::ITEM, GUARDS_BEDROOM_CLOSED_WARDROBE, GUARDS_BEDROOM_LOOK_CLOSED_WARDROBE, {}));
	guardClothes = ptrItem(new Item(wardrobe, ItemSize::LARGE, false, false, Type::ITEM, GUARDS_BEDROOM_LOOK_CLOTHES, GUARDS_BEDROOM_LOOK_CLOTHES, {}));
	wardrobe->contains = {guardClothes};
	bagOfCoins = ptrItem(new Item(nullptr, ItemSize::SMALL, false, true, Type::ITEM, GUARDS_BEDROOM_LOOK_BAG_OF_COINS, GUARDS_BEDROOM_LOOK_BAG_OF_COINS, {}));
	coins = ptrItem(new Item(bagOfCoins, ItemSize::SMALL, false, false, Type::ITEM, GUARDS_BEDROOM_LOOK_COINS, GUARDS_BEDROOM_LOOK_COINS, {}));
	bagOfCoins->contains = { coins };
	
	/*leatherCuirass = ptrArmor(new Armor(5,nullptr, false, Type::ITEM, GUARDS_BEDROOM_CUIRASS, GUARDS_BEDROOM_LOOK_CUIRASS, {}));*/
	/*helmet = ptrArmor(new Armor(2, guardsBedroom, false, Type::ITEM, GUARDS_BEDROOM_HELMET, GUARDS_BEDROOM_LOOK_HELMET, {}));*/

	//meetings room
	tableMeetingsRoom = ptrItem(new Item(meetingsRoom, ItemSize::EXTRA_LARGE, false, false, Type::ITEM, MEETINGS_ROOM_LOOK_LARGE_TABLE, MEETINGS_ROOM_LOOK_LARGE_TABLE, {}));
	chairMeetingsRoom1 = ptrItem(new Item(meetingsRoom, ItemSize::LARGE, false, false, Type::ITEM, CHAIR + "MeetingsRoom1", CHAIR, {}));
	chairMeetingsRoom2 = ptrItem(new Item(meetingsRoom, ItemSize::LARGE, false, false, Type::ITEM, CHAIR + "MeetingsRoom2", CHAIR, {}));
	chairMeetingsRoom3 = ptrItem(new Item(meetingsRoom, ItemSize::LARGE, false, false, Type::ITEM, CHAIR + "MeetingsRoom3", CHAIR, {}));
	chairMeetingsRoom4 = ptrItem(new Item(meetingsRoom, ItemSize::LARGE, false, false, Type::ITEM, CHAIR + "MeetingsRoom4", CHAIR, {}));
	officerSword = ptrWeapon(new Weapon(5, officerMeetingRoom, ItemSize::LARGE, Type::WEAPON, MEETINGS_ROOM_OFFICER_SWORD, MEETINGS_ROOM_LOOK_OFFICER_SWORD, {}));
	mainHallDoorKey = ptrItem(new Item(nullptr, ItemSize::SMALL, false, false, Type::ITEM, MAIN_HALL_KEY, MAIN_HALL_KEY, {}));

	//UPDATE ROOMS' ITEMS
	cell->contains = { mattress, breadcrumbs, cellDoorExit, window, bar, doorOpening };
	aisle1->contains = { aisle1WestExit, aisle1DoorExit };
	aisle2->contains = { aisle2WestExit, aisle2EastExit, aisle2ArmoryExit, aisle2GuadroomExit };
	aisle3->contains = { aisle3WestExit, aisle3NorthExit, aisle3ToolroomExit };
	armory->contains = { shield, armoryCloset, armoryDoorExit, helmet, leatherCuirass };
	guardroom->contains = { chairGuardroom, smallClosetGuardRoom, armoryKey, cleaningStaffKey, guardroomExit };
	toolroom->contains = { twoHandedMace, toolsCloset, toolroomExit };
	upstairs->contains = { upstairsSouthExit,upstairsNorthExit, upstairsWestExit, upstairsEastExit };
	guardsBedroom->contains = { wardrobe, guardsBedroomExit };
	meetingsRoom->contains = { tableMeetingsRoom, chairMeetingsRoom1, chairMeetingsRoom2, chairMeetingsRoom3, chairMeetingsRoom4, meetingsRoomExit };
	mainHall->contains = { mainHallWestExit, mainHallDoorExit };

	//INSTANTIATE CREATURES
	guardAisle1 = ptrNpc(new Npc(false, aisle1, 300, 0, 0, Type::NPC, GUARD, CELL_LOOK_GUARD, { cellKey, aisle1GuardSword}));
	cellKey->parentEntity = guardAisle1;
	aisle1GuardSword->parentEntity = guardAisle1;

	guardToolRoom = ptrNpc(new Npc(false, toolroom, 15, 5, 8, Type::NPC, GUARD, TOOLROOM_GUARD_ALIVE, {}));
	guardGuardroom = ptrNpc(new Npc(false, guardroom, 300, 0, 100, Type::NPC, GUARD, TOOLROOM_GUARD_ALIVE, {}));
	
	guardSleeping = ptrNpc(new Npc(false, guardsBedroom, 15, 5, 0, Type::NPC, GUARD, GUARDS_BEDROOM_LOOK_GUARD_ALIVE, {bagOfCoins}));
	bagOfCoins->parentEntity = guardSleeping;
	//leatherCuirass->parentEntity = guardSleeping;
	
	officerMeetingRoom = ptrNpc(new Npc(false, meetingsRoom, 20, 10, 5, Type::NPC, OFFICER, MEETINGS_ROOM_LOOK_OFFICER_ALIVE, { mainHallDoorKey, officerSword }));
	mainHallDoorKey->parentEntity = officerMeetingRoom;
	officerSword->parentEntity = officerMeetingRoom;
	
	player = ptrPlayer(new Player(cell, 20, 10, 0, Type::PLAYER, PLAYER, LOOK_PLAYER, {}, nullptr, 3, 0));

	listCreatures = { guardAisle1 , guardToolRoom , guardGuardroom, guardSleeping, player};


	std::cout << "<><><><>  WELCOME TO ZORKY <><><><>" << std::endl;
	std::cout <<  GAME_INTRO  << std::endl << std::endl;
}

ReturnState World::Start()
{	
	ptrEntity location = player->location;
	if (nullptr == location)
	{
		std::cout << "Error on Start()\n";
		return ReturnState::ERROR;
	}
	std::cout << "****" << location->name << "****" << std::endl;
	std::cout << location->description << std::endl << std::endl;

	return ReturnState::STAY;
}

ReturnState World::Update()
{
	std::string inputCommand;
	std::getline(std::cin, inputCommand);
	fflush(stdin);
	std::vector<std::string> playerWordsVector = {};
//	ParseInput(inputCommand, playerWordsVector);

	if (playerWordsVector.size() == 1)
	{

		if (playerWordsVector[0] == "H")
		{
			std::cout << COMMANDS_LIST << std::endl;
			return ReturnState::STAY;
		}
		else if (playerWordsVector[0] == "I")
		{
			if ((player->contains).size() != 0)
			{
				for (ptrEntity elem : player->contains)
				{
					ptrItem item = std::dynamic_pointer_cast<Item>(elem);
					std::cout << item->name << std::endl;

				}
				std::cout << std::endl << std::endl;
				return ReturnState::STAY;
			}
			else {
				std::cout << PLAYER_NO_ITEMS << std::endl << std::endl;
				return ReturnState::STAY;
			}
		}
		else if (playerWordsVector[0] == "Q")
		{
			return ReturnState::QUIT;
		}
		else
		{
			std::cout << DONT_UNDERSTAND << std::endl << std::endl;
			return ReturnState::STAY;
		}
	}
	if (playerWordsVector.size() == 2 && playerWordsVector[0] == "LOOK")
	{
		if (playerWordsVector[1] == "PLAYER" || playerWordsVector[1] == "ME" || playerWordsVector[1] == "MYSELF")
		{
			std::cout << LOOK_PLAYER << std::endl << std::endl;
			return ReturnState::STAY;
		}
	}

	if (playerWordsVector.size() == 2 && playerWordsVector[0] == "LOOK")
	{
		if (playerWordsVector[1] == "CELL")
		{
			Look(cell, listCreatures);
			std::cout << std::endl;
			return ReturnState::STAY;
		}
		if (playerWordsVector[1] == "CELLS AISLE")
		{
			Look(aisle1, listCreatures);
			std::cout << std::endl;
			return ReturnState::STAY;
		}
		if (playerWordsVector[1] == "ARMORY AISLE")
		{
			Look(aisle2, listCreatures);
			std::cout << std::endl;
			return ReturnState::STAY;
		}
		if (playerWordsVector[1] == "ARMORY")
		{
			Look(armory, listCreatures);
			std::cout << std::endl;
			return ReturnState::STAY;
		}
		if (playerWordsVector[1] == "GUARDROOM")
		{
			Look(guardroom, listCreatures);
			std::cout << std::endl;
			return ReturnState::STAY;
		}

		listIter iterItemInPlayer = FindEntityByName(playerWordsVector[1], player->contains);
		if (iterItemInPlayer == player->contains.end())
		{
			for (ptrEntity itemInPlayer : player->contains)
			{
				if (itemInPlayer->type == Type::ITEM)
				{
					if (std::dynamic_pointer_cast<Item>(itemInPlayer)->isOpen)
					{
						listIter iterInside = FindEntityByName(playerWordsVector[1], itemInPlayer->contains);
						if (iterInside != player->location->contains.end())
						{
							std::cout << (*iterInside)->description << std::endl << std::endl;
							return ReturnState::STAY;
						}
					}
				}
			}
		}
		else
		{
			std::cout << (*iterItemInPlayer)->description << std::endl << std::endl;
			return ReturnState::STAY;
		}
				
		listIter iterItemInRoom = FindEntityByName(playerWordsVector[1], player->location->contains);
		if (iterItemInRoom == player->location->contains.end())
		{
			for (ptrEntity element : player->location->contains)
			{
				if (element->type == Type::ITEM)
				{
					if (std::dynamic_pointer_cast<Item>(element)->isOpen)
					{
						listIter iterInside = FindEntityByName(playerWordsVector[1], element->contains);
						if (iterInside != player->location->contains.end())
						{
							std::cout << (*iterInside)->description << std::endl << std::endl;
							return ReturnState::STAY;
						}
					}
				}
			}
		}
		else
		{
			std::cout << (*iterItemInRoom)->description << std::endl << std::endl;
			return ReturnState::STAY;
		}
		
	
		std::cout << NO_ITEM_IN_ROOM << std::endl << std::endl;
		return ReturnState::STAY;		

	}
	else if (playerWordsVector.size() == 2 && playerWordsVector[0] == "TAKE")
	{

		listIter iter = FindEntityByName(playerWordsVector[1], player->contains);
		if (iter != player->contains.end())
		{
			std::cout << ALREADY_GOT_ITEM << std::endl << std::endl;
			return ReturnState::STAY;
		}
		
		iter = FindEntityByName(playerWordsVector[1], player->location->contains);
		if (iter != player->location->contains.end())
		{
			Take(player, std::dynamic_pointer_cast<Item>(*iter));
			std::cout << TAKE_ITEM << std::endl << std::endl;
			return ReturnState::STAY;
		}
		else if(iter == player->location->contains.end())
		{
			for (ptrEntity element : player->location->contains)
			{
				if (element->type == Type::ITEM)
				{
					if (std::dynamic_pointer_cast<Item>(element)->isOpen)
					{
						listIter iterInside = FindEntityByName(playerWordsVector[1], element->contains);
						if (iterInside != element->contains.end())
						{
							Take(player, std::dynamic_pointer_cast<Item>(*iterInside));
							std::cout << TAKE_ITEM << std::endl << std::endl;
							return ReturnState::STAY;
						}
					}
				}
			}
		}
		else
		{
			std::cout << NO_ITEM_IN_ROOM << std::endl << std::endl;
			return ReturnState::STAY;
		}
	}
	else if (playerWordsVector.size() == 2 && playerWordsVector[0] == "DROP")
	{
		listIter iter = FindEntityByName(playerWordsVector[1], player->contains);

		if (iter != player->contains.end())
		{
			Drop(player, std::dynamic_pointer_cast<Item>(*iter));
			std::cout << DROP_ITEM << std::endl << std::endl;
			return ReturnState::STAY;
		}
		else
		{
			std::cout << NO_ITEM_IN_INV << std::endl << std::endl;
			return ReturnState::STAY;
		}
	}
	else if (playerWordsVector.size() == 2 && playerWordsVector[0] == "GO")
	{
		Direction playerDirection;
		if (playerWordsVector[1] == "NORTH" || playerWordsVector[1] == "N") {
			playerDirection = Direction::NORTH;
		}

		if (playerWordsVector[1] == "SOUTH" || playerWordsVector[1] == "S") {
			playerDirection = Direction::NORTH;
		}

		if (playerWordsVector[1] == "EAST" || playerWordsVector[1] == "E") {
			playerDirection = Direction::NORTH;
		}

		if (playerWordsVector[1] == "WEST" || playerWordsVector[1] == "W") {
			playerDirection = Direction::NORTH;
		}

		GoDirection canGo = Go(player, playerDirection);
		switch (canGo)
		{
		case GoDirection::OK:
			return ReturnState::NEXT_ROOM;

		case GoDirection::CLOSED:
			std::cout << DOOR_CLOSED << std::endl << std::endl;
			return ReturnState::STAY;

		case GoDirection::NO_WAY:
			std::cout << WRONG_DIRECTION << std::endl << std::endl;
			return ReturnState::STAY;
		
		default: ReturnState::STAY;
		}

		//We've exited the jail
		if (player->location == nullptr)
			return ReturnState::FREEDOM;

	}
	//command: put into
	else if (playerWordsVector.size() > 2 && playerWordsVector[0] == "PUT")
	{
		std::map<std::string, std::string> items = GetItemsToCombine(playerWordsVector);
		ptrItem firstItem;
		ptrItem secondItem;

		listIter iterFirstItem = FindEntityByName(items["firstItem"], player->contains);
		if (iterFirstItem == player->contains.end())
		{
			std::cout << NO_ITEM_IN_INV << std::endl << std::endl;
			return ReturnState::STAY;
		}

		listIter iterSecondItemInPlayer = FindEntityByName(items["secondItem"], player->contains);
		listIter iterSecondItemInRoom = FindEntityByName(items["secondItem"], player->location->contains);
		if (iterSecondItemInPlayer != player->contains.end())
		{
			//Check if item can be opened 
			if (std::dynamic_pointer_cast<Item>(*iterSecondItemInPlayer)->canBeOpened)
			{
				//Check if it's open
				if (std::dynamic_pointer_cast<Item>(*iterSecondItemInPlayer)->isOpen)
				{
					//check item size
					if (std::dynamic_pointer_cast<Item>(*iterFirstItem)->size < std::dynamic_pointer_cast<Item>(*iterSecondItemInPlayer)->size)
					{
						//put item1 into item2
						PutInto(std::dynamic_pointer_cast<Item>(*iterFirstItem), std::dynamic_pointer_cast<Item>(*iterSecondItemInPlayer));
					}
					else
					{
						std::cout << CANT_PUT_ITEM_TOO_BIG << std::endl << std::endl;
						return ReturnState::STAY;
					}
				}
				else
				{
					std::cout << CANT_PUT_ITEM_CLOSED << std::endl << std::endl;
					return ReturnState::STAY;
				}
			}
			else
			{
				std::cout << BAD_IDEA << std::endl << std::endl;
				return ReturnState::STAY;
			}

		}
		if (iterSecondItemInRoom != player->location->contains.end())
		{
			//Check if item can be opened 
			if (std::dynamic_pointer_cast<Item>(*iterSecondItemInRoom)->canBeOpened)
			{
				//Check if it's open
				if (std::dynamic_pointer_cast<Item>(*iterSecondItemInRoom)->isOpen)
				{
					//check item size
					if (std::dynamic_pointer_cast<Item>(*iterFirstItem)->size < std::dynamic_pointer_cast<Item>(*iterSecondItemInRoom)->size)
					{

						//put item1 into item2
						PutInto(std::dynamic_pointer_cast<Item>(*iterFirstItem), std::dynamic_pointer_cast<Item>(*iterSecondItemInRoom));
						TriggerConsequences();
						
					}
					else
					{
						std::cout << CANT_PUT_ITEM_TOO_BIG << std::endl << std::endl;
						return ReturnState::STAY;
					}
				}
				else
				{
					std::cout << CANT_PUT_ITEM_CLOSED << std::endl << std::endl;
					return ReturnState::STAY;
				}
			}
			else
			{
				std::cout << BAD_IDEA << std::endl << std::endl;
				return ReturnState::STAY;
			}
		}
	}
	else if (playerWordsVector.size() == 2 && playerWordsVector[0] == "SEARCH")
	{
		listIter li = FindEntityByName(playerWordsVector[1], listCreatures);
		
		if (li != listCreatures.end())
		{
			ptrNpc npc = std::dynamic_pointer_cast<Npc>(*li);
			if (npc->location->name == player->location->name)
			{
				if (npc->hp <= 0)
				{
					std::cout << LOOT << std::endl;
					Search(player, npc);
				}
				else
				{
					std::cout << BAD_IDEA << std::endl;
				}
			}
		}
		else 
		{
			std::cout << NO_SEARCH << std::endl;
		}		
	}
	else if (playerWordsVector.size() == 2 && playerWordsVector[0] == "OPEN")
	{
		listIter itItemRoom = FindEntityByName(playerWordsVector[1], player->location->contains);
		if (itItemRoom != player->location->contains.end())
		{
			OpenItem(std::dynamic_pointer_cast<Item>(*itItemRoom));
			std::cout << OPENED << std::endl;

		}
		else
		{
			listIter itItemPlayer = FindEntityByName(playerWordsVector[1], player->contains);
			if (itItemPlayer != player->contains.end())
			{
				OpenItem(std::dynamic_pointer_cast<Item>(*itItemPlayer));
				std::cout << OPENED << std::endl;
			}
			else
				std::cout << NO_ITEM_IN_ROOM << std::endl;
		}	
	}
	else if (playerWordsVector.size() > 2 && playerWordsVector[0] == "OPEN" && (playerWordsVector[2] == "EXIT" || playerWordsVector[2] == "DOOR"))
	{
		// area under development. We prevent the player from going through this door.
		if (player->location == aisle2)
		{
			if (playerWordsVector[1] == "EAST")
			{
				std::cout << DOOR_LOCKED << std::endl;
			}
		}
		else
		{
			OpenExit(playerWordsVector[1], player);
		}
	}
	//unknown command	
	else
	{
		std::cout << DONT_UNDERSTAND << std::endl << std::endl;
		return ReturnState::STAY;
	}

							
	return ReturnState::STAY;
	

}

ReturnState World::TriggerConsequences()
{
	//CELL1
	
	if (player->location == cell)
	{
		//Breadcrumbs in the window -> spawn pigeon in cell
		if (pigeon->parentEntity == nullptr)
		{
			listIter iterBreadcrumbs = FindEntityByName(CELL_BREADCRUMBS, window->contains);
			if (iterBreadcrumbs != window->contains.end())
			{
				pigeon->parentEntity = cell;
				cell->contains.push_back(pigeon);
				std::cout << CELL_PIGEON_COMES_IN << std::endl << std::endl;
				return ReturnState::STAY;
			}
		}

		//Pigeon in door opening -> guard enters the cell
		if (pigeon->parentEntity == doorOpening)
		{
			listIter iterPigeon = FindEntityByName(CELL_PIGEON, doorOpening->contains);
			if (iterPigeon != doorOpening->contains.end())
			{
			
				if (FindEntityByName(CELL_BAR, player->contains) != player->contains.end())
				{
					cellDoorExit->isOpen = true;
					cellDoorExit->isLocked = false;
					guardAisle1->location = cell;
					std::cout << CELL_HIT_GUARD << std::endl << std::endl;
					guardAisle1->hp = 0;
					guardAisle1->description = CELL_LOOK_DEAD_GUARD;
					doorOpening->description = CELL_LOOK_DOOR_OPENING_GUARD_DEAD;
					TransferItem(pigeon, cell);
					std::cout << CELL_PIGEON_BACK_TO_WINDOW << std::endl << std::endl;
				}
				else
				{
					std::cout << CELL_GUARD_ON_ENTER2 << std::endl;
					TransferItem(pigeon, cell);
					std::cout << CELL_PIGEON_BACK_TO_WINDOW << std::endl << std::endl;

				}
			}
			return ReturnState::STAY;
		}

		if (windowExit->isOpen)
		{
			listIter iter = FindEntityByName(TOOLROOM_ROPE, window->contains);
			if (iter != window->contains.end()) {
				std::cout << CELL_EXIT_SUCCESS << std::endl;
			}

			return ReturnState::FREEDOM;
		}
	}
}

