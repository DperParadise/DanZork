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
	corridor = new Room(ROOM, "corridor", "prison corridor. To the north the main hall is visible. To the east, a door.", cor_inv);
	wardrobe = new Room(ROOM, "wardrobe", "guards wardrobe. There is a closet here.", war_inv);
	main_hall = new Room(ROOM, "main hall", "main hall entrance. A door leads to the street.", {});
	//---------------------------------------EXITS----------------------------------------------
	//cell <-> corridor
	door_clc = new Exit(NORTH, cell, corridor, false, EXIT, "cell door", "metallic cell door with a hole.", clc_inv);
	door_ccl = new Exit(SOUTH, cell, corridor, false, EXIT, "cell door", "metallic cell door with a hole.", clc_inv);
	//corridor <-> wardrobe
	door_cw = new Exit(EAST, corridor, wardrobe, false, EXIT, "wardrobe door", "wooden door.", {});
	door_wc = new Exit(EAST, wardrobe, corridor, true, EXIT, "wardrobe door", "wooden door.", {}); 
	//corridor <-> main_hall
	door_ch = new Exit(NORTH, corridor, main_hall, true, EXIT, "main hall door", "big main hall door.", {});
	door_hc = new Exit(SOUTH, main_hall, corridor, true, EXIT, "main hall door", "big main hall door.", {});
	//main_hall -> stret
	door_hs = new Exit(NORTH, main_hall, nullptr, false, EXIT, "street exit", "door leading to the street.", {});
	 //---------------------------------------ITEMS CELL-----------------------------------------
	window = new Item(cell, MEDIUM, true, ITEM, "window", "barred window leading to the forest with a loose bar. You can hear doves singing nearby.", win_inv);
	breadcrumbs = new Item(cell, SMALL, false, ITEM, "bread crumbs", "bread crumbs. Someone enjoy his last meal here.", {});
	door_hole = new Item(cell, MEDIUM, true, ITEM, "door hole", "through this hole prisoners are given food.", doh_inv);
	pigeon = new Item(cell, SMALL, false, ITEM, "pigeon", "young pigeon.", {});
	bar = new Item(cell, SMALL, false, ITEM, "bar", "metallic bar.", {});
	//---------------------------------------ITEMS CORRIDOR-------------------------------------
	table = new Item(corridor, MEDIUM, false, ITEM, "table", "wood table", {});
	closet_key = new Item(corridor, SMALL, false, ITEM, "closet key", "key with a tag attached: closet.", {});
	//---------------------------------------ITEMS WARDROBE-------------------------------------
	closet = new Item(wardrobe, LARGE, false, ITEM, "clothes closet", "clothes closet used by the guards.", clo_inv);
	guard_outfit = new Item(wardrobe, SMALL, false, ITEM, "guard outfit", "guard outfit clean and ready to wear", {});
	//--------------------------------------PLAYER & ENEMIES------------------------------
	player = new Player(cell, PLAYER, "Daniel", "It's me", pla_inv);
	enemy = new Enemy(corridor, ENEMY, "guard", "a cell guard wearing it's outfit", {});

	//Set relationshipts between entities




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
	/*RELEASE(enemy);
	RELEASE(player);
	RELEASE(guard_outfit);
	RELEASE(closet);
	RELEASE(closet_key);
	RELEASE(table);
	RELEASE(bar);
	RELEASE(pigeon);
	RELEASE(door_hole);
	RELEASE(breadcrumbs);
	RELEASE(window);
	RELEASE(door_hs);
	RELEASE(door_hc);
	RELEASE(door_ch);
	RELEASE(door_wc);
	RELEASE(door_cw);
	RELEASE(door_ccl);
	RELEASE(door_clc);
	RELEASE(main_hall);
	RELEASE(wardrobe);
	RELEASE(corridor);
	RELEASE(cell);*/
}