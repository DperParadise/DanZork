#ifndef WORLD_H
#define WORLD_H

#include "entity.h"

class Player;
class Room;
class Item;
class Enemy;
class Exit;
class Entity;
class World
{
public:
	
	//Create game objects
	void Init();

	//Start initial message
	void Start();

	ReturnState Update();
	
	void CleanUp();

private:

	typedef std::list<Entity*> Inventory;

	std::list<Entity*> world;
	char input[50];
	char command[50];

	
	//--------------------------------------ROOMS-----------------------------------------
	Room *cell;
	Inventory cel_inv;
	Room *corridor;
	Inventory cor_inv;
	Room *wardrobe;
	Inventory war_inv;
	Room *main_hall;
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
	

};


#endif //WORLD_H


