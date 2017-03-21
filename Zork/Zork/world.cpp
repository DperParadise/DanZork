#include "world.h"
#include <iostream>
#include "room.h"
#include "exit.h"
#include "item.h"
#include "player.h"
#include "enemy.h"
#include <list>
#include "Observer.h"

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
	street = new Room(ROOM, "street", "Sorroundings of the prison. A guard stands next to the door staring at you.", st_inv);
	world.push_back(street);
	//---------------------------------------EXITS----------------------------------------------
	//cell <-> corridor
	door_clc = new Exit(NORTH, cell, corridor, false, true, EXIT, "cell door", "metallic cell door to the north.", clc_inv);
	world.push_back(door_clc);
	door_ccl = new Exit(SOUTH, corridor, cell, false, true, EXIT, "cell door", "metallic cell door to the south.", clc_inv);
	world.push_back(door_ccl);
	//corridor <-> wardrobe
	door_cw = new Exit(EAST, corridor, wardrobe, false, false, EXIT, "wardrobe door", "wooden door to the east.", common_inv);
	world.push_back(door_cw);
	door_wc = new Exit(WEST, wardrobe, corridor, false, false, EXIT, "wardrobe door", "wooden door to the west.", common_inv);
	world.push_back(door_wc);
	//corridor<->main hall
	door_ch = new Exit(NORTH, corridor, main_hall, false, false, EXIT, "main hall door", "metallic door to the north.", common_inv);
	world.push_back(door_ch);
	door_hc = new Exit(SOUTH, main_hall, corridor, false, false, EXIT, "main hall door", "metallic door to the south.", common_inv);
	world.push_back(door_hc);
	//main_hall -> stret
	door_hs = new Exit(NORTH, main_hall, street, false, false, EXIT, "street door", "door leading to the street to the north.", common_inv);
	world.push_back(door_hs);
	 //---------------------------------------ITEMS CELL-----------------------------------------
	window = new Item(cell, nullptr, MEDIUM, true, true, false, ITEM, "window", "barred window leading to the forest. You can hear doves singing nearby.", win_inv);
	world.push_back(window);
	breadcrumbs = new Item(cell, nullptr, SMALL, false, false, false, ITEM, "bread crumbs", "bread crumbs. Someone enjoyed his last meal here.", common_inv);
	world.push_back(breadcrumbs);
	door_hole = new Item(cell, nullptr, MEDIUM, true, true, false, ITEM, "door hole", "through this hole prisoners are given food.\nThere is a corridor in front of the cell. A guard can bee seen.", doh_inv);
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
	closet = new Item(wardrobe, nullptr, LARGE, false, true, true, ITEM, "closet", "clothes closet used by the guards.", clo_inv);
	world.push_back(closet);
	guard_outfit = new Item(wardrobe, closet, SMALL, false, false, false, ITEM, "guard outfit", "guard outfit clean and ready to wear", common_inv);
	world.push_back(guard_outfit);
	//--------------------------------------PLAYER & ENEMIES------------------------------
	player = new Player(cell, PLAYER, "Daniel", "It's me", pla_inv);
	world.push_back(player);
	enemy = new Enemy(corridor, ENEMY, "guard", "a cell guard wearing it's outfit soaked in blood", common_inv);
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
	cor_inv.push_back(door_ch);

	//WARDROBE
	clo_inv.push_back(guard_outfit);
	war_inv.push_back(guard_outfit);
	war_inv.push_back(closet);
	war_inv.push_back(door_wc);

	//MAIN HALL
	mh_inv.push_back(door_hs);
	mh_inv.push_back(door_hc);

	//Register observers
	window_obs = new Observer(window, "bread crumbs");
	window->RegisterObs(window_obs);

	door_hole_obs = new Observer(door_hole, "pigeon");
	door_hole->RegisterObs(door_hole_obs);

	player_obs = new Observer(player, "guard outfit");
	player->RegisterObs(player_obs);

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
	
	//Commands--------------------------------------------
	if (!strcmp(command, "close"))
	{
		player->Close(sub1);
		std::cout << player->GetMessage() << std::endl;
	}
	if (!strcmp(command, "open"))
	{
		player->Open(sub1);
		std::cout << player->GetMessage() << std::endl;
	}
	if (!strcmp(command, "drop"))
	{
		player->Drop(sub1);
		std::cout << player->GetMessage() << std::endl;
	}
	if (!strcmp(command, "go"))
	{
		player->Go(sub1);
		std::cout << player->GetMessage() << std::endl;

		if (player->location == street)
		{
			bool end_success = player->NotifyObs();
			if (end_success)
			{
				printf("You: Ehmm Hello?\nGuard: Hello. You are the new guard. Aren't you?\nYou: ehh Yes, yes. My shift is over already\nGuard: Ok, see you tomorrow!\nYou: hehe Sure...\nFREEDOM AT LAST!!\n");
				return QUIT;
			}
			else
			{
				printf("Hey!!, who are you? The guard notices your prisoner outfit. In a fast movement he shoots you. You were so close...but the game is over for you.\n");
				return QUIT;
			}
		}
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

		if (player->location == cell)
		{
			bool bread_wnd = window->NotifyObs();
			if (bread_wnd && pigeon->loc == nullptr)
			{
				pigeon->loc = cell;
				cel_inv.push_back(pigeon);
				printf("A young pigeon notices the bread crumbs in the window and gently takes a small portion and fearless jumps into the cell to eat it.\nIt seems to be tamed.\n");
			}

			bool pigeon_dhole = door_hole->NotifyObs();
			if (pigeon_dhole)
			{
				pigeon->loc = nullptr;
				pigeon->parent = nullptr;
				//remove pigeon from door hole
				for (Inventory::iterator it = doh_inv.begin(); it != doh_inv.end(); it++)
				{
					if (*it == pigeon)
					{
						doh_inv.erase(it);
						break;
					}
				}
				//remove pigeon from cell
				for (Inventory::iterator it = cell->contains.begin(); it != cell->contains.end(); it++)
				{
					if (*it == pigeon)
					{
						cell->contains.erase(it);
						break;
					}
				}
				
				bool bar_fnd = false;
				for (Inventory::iterator it = player->contains.begin(); it != player->contains.end() && !bar_fnd; it++)
				{
					if (*it == bar)
					{
						bar_fnd = true;
					}
				}

				if (bar_fnd)
				{
					printf("You hear the guard running towards you swearing and threatening you.\nAs soon as you see him comming into the cell you hit him on the head with the bar and knock him out. Stains of blood cover the guard body\n");
					door_clc->isLocked = false;
					door_clc->isOpen = true;
					door_ccl->isLocked = false;
					door_ccl->isOpen = true;
					enemy->location = cell;
					cel_inv.push_back(enemy);
					door_hole->description = "through this hole prisoners are given food.\nThere is a corridor in front of the cell.";
					
				}
				else
				{
					printf("You hear the guard running towards you swearing and threatening you.\nHe enters the cell: You wanna play games my friend?I'll teach you a game.\n He knocks you out...You open your eyes. Headache, blood in your head. You pickup the breadcrumbs from the window\n");			
					breadcrumbs->parent = player;
					player->contains.push_back(breadcrumbs);
					for (Inventory::iterator it = win_inv.begin(); it != win_inv.end(); it++)
					{
						if (*it == breadcrumbs)
						{
							win_inv.erase(it);
							break;
						}
					}
				}
			}
		}


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

	RELEASE(window_obs);
	RELEASE(door_hole_obs);
	RELEASE(player_obs);
}

const std::list<Entity*>& World::GetWorldInv() const
{
	return world;
}