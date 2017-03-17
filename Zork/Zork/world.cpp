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
	main_hall = new Room(ROOM, "main hall", "main hall entrance. A door leads to the street.", mh_inv);
	world.push_back(main_hall);
	//---------------------------------------EXITS----------------------------------------------
	//cell <-> corridor
	door_clc = new Exit(NORTH, cell, corridor, true, EXIT, "cell door", "metallic cell door to the north.", clc_inv);
	world.push_back(door_clc);
	door_ccl = new Exit(SOUTH, corridor, cell, true, EXIT, "cell door", "metallic cell door to the south.", clc_inv);
	world.push_back(door_ccl);
	//corridor <-> wardrobe
	door_cw = new Exit(EAST, corridor, wardrobe, false, EXIT, "wardrobe door", "wooden door to the east.", common_inv);
	world.push_back(door_cw);
	door_wc = new Exit(WEST, wardrobe, corridor, true, EXIT, "wardrobe door", "wooden door to the west.", common_inv);
	world.push_back(door_wc);
	//main_hall -> stret
	door_hs = new Exit(NORTH, main_hall, nullptr, false, EXIT, "street exit", "door leading to the street to the north.", common_inv);
	world.push_back(door_hs);
	 //---------------------------------------ITEMS CELL-----------------------------------------
	window = new Item(cell, nullptr, MEDIUM, true, true, false, ITEM, "window", "barred window leading to the forest. You can hear doves singing nearby.", win_inv);
	world.push_back(window);
	breadcrumbs = new Item(cell, nullptr, SMALL, false, false, false, ITEM, "bread crumbs", "bread crumbs. Someone enjoyed his last meal here.", common_inv);
	world.push_back(breadcrumbs);
	door_hole = new Item(cell, nullptr, MEDIUM, true, true, false, ITEM, "door hole", "through this hole prisoners are given food.", doh_inv);
	world.push_back(door_hole);
	pigeon = new Item(nullptr, nullptr, SMALL, false, false, false, ITEM, "pigeon", "young pigeon.", common_inv);
	world.push_back(pigeon);
	bar = new Item(cell, nullptr, SMALL, false, false, false, ITEM, "bar", "rusty metallic bar fallen from the window. The guards haven't noticed it.", common_inv);
	world.push_back(bar);
	//---------------------------------------ITEMS CORRIDOR-------------------------------------
	table = new Item(corridor, nullptr, MEDIUM, false, false, false, ITEM, "table", "wood table", common_inv);
	world.push_back(table);
	closet_key = new Item(corridor, nullptr, SMALL, false, false, false, ITEM, "closet key", "key with a tag attached: closet.", common_inv);
	world.push_back(closet_key);
	//---------------------------------------ITEMS WARDROBE-------------------------------------
	closet = new Item(wardrobe, nullptr, LARGE, false, true, true, ITEM, "clothes closet", "clothes closet used by the guards. It's closed", clo_inv);
	world.push_back(closet);
	guard_outfit = new Item(wardrobe, closet, SMALL, false, false, false, ITEM, "guard outfit", "guard outfit clean and ready to wear", common_inv);
	world.push_back(guard_outfit);
	//--------------------------------------PLAYER & ENEMIES------------------------------
	player = new Player(cell, PLAYER, "Daniel", "It's me", pla_inv);
	world.push_back(player);
	enemy = new Enemy(corridor, ENEMY, "guard", "a cell guard wearing it's outfit", common_inv);
	world.push_back(enemy);

	//Fill inventories
	//CELL
	cel_inv.push_back(bar);
	cel_inv.push_back(window);
	cel_inv.push_back(breadcrumbs);
	cel_inv.push_back(door_hole);
	cel_inv.push_back(door_clc);

	//CORRIDOR
	cor_inv.push_back(table);
	cor_inv.push_back(closet_key);
	cor_inv.push_back(door_ccl);
	cor_inv.push_back(door_cw);

	//WARDROBE
	clo_inv.push_back(guard_outfit);
	war_inv.push_back(guard_outfit);
	war_inv.push_back(closet);
	war_inv.push_back(door_wc);

	//MAIN HALL
	mh_inv.push_back(door_hs);

	
}

void World::Start()
{
	//Initial message
	printf("*****Wellcome to Dan Zork*****\n");
	printf("Current location: %s\n===========================\n%s\n", player->location->name, player->location->description);
}

ReturnState World::Update()
{
	//Receive Input and make player execute actions
	ReturnState ret = ReturnState::CONTINUE;
	
	memset(raw_input, '\0', length + 1);
	memset(input, '\0', length + 1);
	memset(command, '\0', length + 1);
	memset(sub1, '\0', length + 1);
	memset(sub2, '\0', length + 1);
	
	printf(">");
	int i = 0;
	char c = ' ';

	while ('\n' != (c = getchar()))
	{
		raw_input[i] = c;
		i++;
	}
	//trim and lower case input
	TrimInput(raw_input, input);

	//search for first command
	char *beg = input;
	int num_char = 0;
	while (*beg != '\0' && *beg != ' ')
	{
		beg++;
		num_char++;
	}	
	memcpy(command, input, num_char);
	beg++;
	num_char++;
	memcpy(sub1, beg, length - num_char);
	
	//Check if the command is "use with"
	if (!strcmp("use", command))
	{
		while (sub1[sub_idx] != '\0' && match_chars < mw_length)
		{
			if (sub1[sub_idx] == my_word[mw_idx])
			{
				if (found_idx == -1)
					found_idx = sub_idx;

				sub_idx++;
				mw_idx++;
				match_chars++;
			}
			else
			{
				found_idx = -1;
				mw_idx = 0;
				match_chars = 0;
				sub_idx++;
			}
		}

		if (found_idx != -1 && match_chars < mw_length)
			found_idx = -1;

		if (found_idx != -1)
		{
			strcat(command, "with");
			beg = sub1 + found_idx + mw_length;
			memcpy(sub2, beg, length - (found_idx + 1 + mw_length));
			sub1[found_idx] = '\0';			
		}

		//reset variables
		found_idx = -1;
		match_chars = 0;
		mw_idx = 0;
		sub_idx = 0;
	}

	//Debug
	//std::cout << "command : " << command << ", " << "sub1 : " << sub1 << ", sub2 : " << sub2 << std::endl;
	
	//test--------------------------------------------
	
	if (!strcmp(command, "go"))
	{
		player->Go(sub1);
		std::cout << player->GetMessage() << std::endl;
	}

	if (!strcmp(command, "lookat"))
	{
		player->LookAt(sub1, this);
		std::cout << player->GetMessage() << std::endl;
	}
	if (!strcmp(command, "pickup")) 
	{
		player->Pickup(sub1);
		std::cout << player->GetMessage() << std::endl;
	}
	if (!strcmp(command, "usewith"))
	{
		player->UseWith(sub1, sub2);
		std::cout << player->GetMessage() << std::endl;
	}
	if (!strcmp(command, "i"))
	{
		player->ShowInv();
		std::cout << player->GetMessage() << std::endl;
	}
	//------------------------------------------------

	//Quit game
	if (!strcmp(command, "q"))
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

const std::list<Entity*>& World::GetWorldInv() const
{
	return world;
}