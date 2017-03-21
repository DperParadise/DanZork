#ifndef WORLD_H
#define WORLD_H

#include "entity.h"

class Player;
class Room;
class Item;
class Enemy;
class Exit;
class Entity;
class Observer;
class World
{
private:
	typedef std::list<Entity*> Inventory;

public:
	
	//Create game objects
	void Init();

	//Start initial message
	void Start();

	ReturnState Update();
	
	void CleanUp();
	const Inventory& GetWorldInv() const;

private:

	Inventory world;
	char raw_input[50];
	char input[50];
	char command[50];
	char sub1[50];
	char sub2[50];
	size_t length = 49;
	const char my_word[7] = " with ";
	size_t mw_length = 6;
	size_t mw_idx = 0;
	size_t sub_idx = 0;
	int found_idx = -1;
	size_t match_chars = 0;

	
	//--------------------------------------ROOMS-----------------------------------------
	Room *cell;
	Inventory cel_inv;
	Room *corridor;
	Inventory cor_inv;
	Room *wardrobe;
	Inventory war_inv;
	Room *main_hall;
	Inventory mh_inv;
	Room *street;
	Inventory st_inv;
	//---------------------------------------EXITS----------------------------------------------
	Exit *door_clc; //cell -> corridor
	Inventory clc_inv;
	Exit *door_ccl; //corridor -> cell
	Exit *door_cw;  //corridor -> wardrobe
	Exit *door_wc;  //wardrobe -> corridor
	Exit *door_ch;  //corridor -> main hall
	Exit *door_hc;  //main hall ->corridor
	Exit *door_hs;  //main hall -> street
	//---------------------------------------ITEMS CELL-----------------------------------------
	Item *window;
	Inventory win_inv;
	Item *breadcrumbs;
	Item *door_hole;
	Inventory doh_inv;
	Item *pigeon;
	Item *bar;
	//---------------------------------------ITEMS CORRIDOR-------------------------------------
	Item *table;
	Item *closet_key;
	//---------------------------------------ITEMS WARDROBE-------------------------------------
	Item *closet;
	Inventory clo_inv;
	Item *guard_outfit;
	//--------------------------------------PLAYER & ENEMIES------------------------------
	Player *player;
	Inventory pla_inv;
	Enemy *enemy;
	
	//----------------- not used inventory ------------------------//
	Inventory common_inv;

	//----------------- Observers ---------------------------------//
	Observer *window_obs;
	Observer *door_hole_obs;
	Observer *player_obs;
};


#endif //WORLD_H


