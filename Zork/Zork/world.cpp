#include "world.h"
#include <iostream>
#include "room.h"
#include "exit.h"
#include "item.h"
#include "player.h"
#include "enemy.h"
#include <list>

void World::Init()
{
	//Create game entities
	//--------------------------------------ROOMS-----------------------------------------
	cell = new Room(ROOM, "cell", "cold dirty cell.", cel_inv);
	world.push_back(cell);
	corridor = new Room(ROOM, "corridor", "prison corridor. To the north the main hall is visible. To the east, a door.", cor_inv);
	world.push_back(corridor);
	wardrobe = new Room(ROOM, "wardrobe", "guards wardrobe. There is a closet here.", war_inv);
	world.push_back(wardrobe);
	main_hall = new Room(ROOM, "main hall", "main hall entrance. A door leads to the street.", {});
	world.push_back(main_hall);
	//---------------------------------------EXITS----------------------------------------------
	//cell <-> corridor
	door_clc = new Exit(NORTH, cell, corridor, false, EXIT, "cell door", "metallic cell door with a hole.", clc_inv);
	world.push_back(door_clc);
	door_ccl = new Exit(SOUTH, cell, corridor, false, EXIT, "cell door", "metallic cell door with a hole.", clc_inv);
	world.push_back(door_ccl);
	//corridor <-> wardrobe
	door_cw = new Exit(EAST, corridor, wardrobe, false, EXIT, "wardrobe door", "wooden door.", {});
	world.push_back(door_cw);
	door_wc = new Exit(EAST, wardrobe, corridor, true, EXIT, "wardrobe door", "wooden door.", {});
	world.push_back(door_wc);
	//corridor <-> main_hall
	door_ch = new Exit(NORTH, corridor, main_hall, true, EXIT, "main hall door", "big main hall door.", {});
	world.push_back(door_ch);
	door_hc = new Exit(SOUTH, main_hall, corridor, true, EXIT, "main hall door", "big main hall door.", {});
	world.push_back(door_hc);
	//main_hall -> stret
	door_hs = new Exit(NORTH, main_hall, nullptr, false, EXIT, "street exit", "door leading to the street.", {});
	world.push_back(door_hs);
	 //---------------------------------------ITEMS CELL-----------------------------------------
	window = new Item(cell, MEDIUM, true, ITEM, "window", "barred window leading to the forest with a loose bar. You can hear doves singing nearby.", win_inv);
	world.push_back(window);
	breadcrumbs = new Item(cell, SMALL, false, ITEM, "bread crumbs", "bread crumbs. Someone enjoy his last meal here.", {});
	world.push_back(breadcrumbs);
	door_hole = new Item(cell, MEDIUM, true, ITEM, "door hole", "through this hole prisoners are given food.", doh_inv);
	world.push_back(door_hole);
	pigeon = new Item(nullptr, SMALL, false, ITEM, "pigeon", "young pigeon.", {});
	world.push_back(pigeon);
	bar = new Item(cell, SMALL, false, ITEM, "bar", "metallic bar.", {});
	world.push_back(bar);
	//---------------------------------------ITEMS CORRIDOR-------------------------------------
	table = new Item(corridor, MEDIUM, false, ITEM, "table", "wood table", {});
	world.push_back(table);
	closet_key = new Item(corridor, SMALL, false, ITEM, "closet key", "key with a tag attached: closet.", {});
	world.push_back(closet_key);
	//---------------------------------------ITEMS WARDROBE-------------------------------------
	closet = new Item(wardrobe, LARGE, false, ITEM, "clothes closet", "clothes closet used by the guards.", clo_inv);
	world.push_back(closet);
	guard_outfit = new Item(wardrobe, SMALL, false, ITEM, "guard outfit", "guard outfit clean and ready to wear", {});
	world.push_back(guard_outfit);
	//--------------------------------------PLAYER & ENEMIES------------------------------
	player = new Player(cell, PLAYER, "Daniel", "It's me", pla_inv);
	world.push_back(player);
	enemy = new Enemy(corridor, ENEMY, "guard", "a cell guard wearing it's outfit", {});
	world.push_back(enemy);

	//Fill inventories



}

void World::Start()
{
	//Initial message
	printf("*****Wellcome to Dan Zork*****\n");
}

ReturnState World::Update()
{
	ReturnState ret = ReturnState::CONTINUE;
	//Receive Input and make player execute actions
	memset(raw_input, '\0', sizeof(raw_input)/sizeof(char));
	memset(command, '\0', sizeof(command) / sizeof(char));
	printf(">");
	int i = 0;
	char c = ' ';

	while ('\n' != (c = getchar()))
	{
		raw_input[i] = c;
		i++;
	}

	ParseInput(raw_input, command);
	ToUpper(command, raw_input);

	//Quit game
	if (!strcmp(raw_input, "Q"))
		return QUIT;


	return ret;
}

void World::CleanUp()
{
	for (std::list<Entity*>::iterator it = world.begin(); it != world.end(); it++)
	{
		RELEASE(*it);
	}
}