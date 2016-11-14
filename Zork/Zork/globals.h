#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>
#include <vector>
#include <map>

void ParseInput(const std::string &inputString, std::vector<std::string> &inputWordsVector);

enum class Type { NPC, PLAYER, EXIT, ROOM, ITEM };

enum class Direction { NORTH, EAST, SOUTH, WEST };

enum class Scenario {
	CELL,
	AISLE1,
	AISLE2,
	AISLE3,
	ARMONY,
	GUARDROOM,
	TOOLROOM,
	UPSTAIRS,
	GUARDS_BEDROOM,
	MEETINGS_ROOM,
	MAIN_HALL,
	MAIN_HALL_EXIT,
	CELL_EXIT,
	START,
	QUIT,
	ERROR
};

enum class ReturnState {
	OK,
	ERROR
};


//Text descriptions

// CELL SCENARIO
#define CELL_TITLE "Cell"
#define CELL_DESC "There's an old dirty mattress on the floor, a window to the west and an door to the east"
#define CELL_BOWL "wood bowl"
#define CELL_LOOK_BOWL "It's a wood bowl, it smells like rancid nuts."
#define CELL_PIGEON "young rock pigeon"
#define CELL_LOOK_PIGEON "It's a young rock pigeon. It was easy to catch."
#define CELL_IRON_BAR "iron bar"
#define CELL_LOOK_IRON_BAR "It's a slightly rusty iron bar."
#define CELL_BREADCRUMBS "dry breadcrumbs"
#define CELL_LOOK_BREADCRUMBS "Dry breadcrumbs. Only an animal would eat this."
#define CELL_LOOK_WINDOW_NO_BARS "A window hole"
#define CELL_LOOK_WINDOW "Barred window. The bars are old and rusty, one of them seems to be a bit loose"
#define CELL_LOOK_DOOR_OPENING "Door opening to give meals to prisoners. A guard is sitting in a desk in the middle of an aisle. He wanders around and sits back again"
#define CELL_LOOK_DOOR "The door is made of iron. It has a small squared opening"
#define CELL_LOOK_DEAD_GUARD "A dead guard lays on the floor. I guess if he was the one who push me into the cell."
#define CELL_SEARCH_GUARD_DEAD "He has a cell key in his pocket"
#define CELL_SEARCH_GUARD_ALIVE "That's not a good idea."

// AISLE 1 SCENARIO
#define AISLE1_TITLE "First Aisle"
#define AISLE1_DESC "Light come through small holes along the walls. To the east stands an iron door"
#define AISLE1_LOOK_DOOR "The door is made of iron."
#define AISLE1_CHAIR "wood chair"
#define AISLE1_LOOK_CHAIR "A pine wood chair."
#define AISLE1_DESK "wood desk"
#define AISLE1_LOOK_DESK "A wood desk. There's something carved on it: DUMB WHO READS IT"

// AISLE 2 SCENARIO
#define AISLE2_TITLE "Second Aisle"
#define AISLE2_DESC "There's a door to the north, another to the south. To the east another aisle leeds to the upstairs floor"
#define AISLE2_LOOK_NORTH_DOOR "An iron wall"
#define AISLE2_LOOK_SOUTH_DOOR "An iron wall"

// ARMORY SCENARIO
#define ARMORY_TITLE "Armory"
#define ARMORY_DESC "There are some shields hanging on the wall and a weapon stand with swords. Close to the wall stands a metallic closet"
#define ARMORY_LOOK_CLOSET "It's a metallic closet. It's locked."

// GUARDROOM SCENARIO
#define GUARDROOM_TITLE "Guardroom"
#define GUARDROOM_DESC "There is a table in the middle of the room"
#define GUARDROOM_CHAIR "wood chair"
#define GUARDROOM_LOOK_CHAIR "A pine wood chair."
#define GUARDROOM_LOOK_CLOSED_CLOSET "It's a small metallic closet."
#define GUARDROOM_LOOK_OPEN_CLOSET "It has two tags: Armory and Cleaning staff. A key hangs below each tag."

// TOOLROOM SCENARIO
#define TOOLROOM_TITLE "Toolroom"
#define TOOLROOM_DESC "You can see a work bench and a tools closet next to the wall."
#define TOOLROOM_CLOSET "It's a locked tools closet."
#define TOOLROOM_GUARD_ALIVE "A guard is leaning on the table. He has an iron mace."
#define TOOLROOM_GUARD_DEAD "A guard dead's corpse."
#define TOOLROOM_SEARCH_GUARD "Nothing useful on him."
#define TOOLROOM_PLAYER_DEAD "You didn't have much luck this time. Rest in peace."

// UPSTAIRS SCENARIO
#define UPSTAIRS_TITLE "Upstairs floor"
#define UPSTAIRS_DESC  "If you face west you can hear a snore coming from the door. To the east you see a large wooden door \nthat leads to the entrance of the prison. To the north, another door."
#define UPSTAIRS_LOOK_NORTH_DOOR "A metallic door."
#define UPSTAIRS_LOOK_WEST_DOOR "A metallic door. Someone seems to be sleeping on this room."
#define UPSTAIRS_LOOK_EAST "Theres another room leading to a large wooden door. It's like a hall room."

// GUARDS BEDROOM SCENARIO
#define GUARDS_BEDROOM_TITLE "Guards bedroom"
#define GUARDS_BEDROOM_DESC "Two rows of beds in front of you and a wardrobe."
#define GUARDS_BEDROOM_GUARD_ALIVE "A young guard is sleeping on one of them."
#define GUARDS_BEDROOM_LOOK_GUARD_ALIVE "A young guard, he doesn't look older than twenty years old. He is wearing a leather cuirass and a helmet."
#define GUARDS_BEDROOM_LOOK_GUARD_DEAD "A guards corpse."
#define GUARDS_BEDROOM_SEARCH_GUARD_ALIVE "You try to search his pockets and he wakes up. That was not a good idea. The guard screams and a guard officer enters the room. You are dead."
#define GUARDS_BEDROOM_SEARCH_GUARD_DEAD "He has a bag of coins in his pocket."
#define GUARDS_BEDROOM_LOOK_CLOSED_CLOSET "A wooden wardrobe with decorative figures carved on it. It's closed."
#define GUARDS_BEDROOM_LOOK_OPEN_CLOSET "It has guard clothes".
#define GUARDS_BEDROOM_TAKE_CLOTHES "You put on the guard clothes."

// MEETINGS ROOM SCENARIO
#define MEETINGS_ROOM_TITLE "Meetings room"
#define MEETINGS_ROOM_DESC "You see a large table sorrounded by chairs. Sitting in one of them an officer is staring at you: Who the hell are you? He stands up and fights you."
#define MEETINGS_ROOM_LOOK_OFFICER_ALIVE "The guard officer in charge of the prison. He is a tall man with strong arms."
#define MEETINGS_ROOM_LOOK_OFFICER_DEAD "The prison officers corpse."
#define MEETINGS_ROOM_SEARCH_OFFICER_DEAD "The officer keeps a key on his pocket. It has a tag attached which says: Main Hall."
#define MEETINGS_ROOM_PLAYER_DEAD "You fought well but this opponent is a hard one. Rest in peace."

// MAIN HALL SCENARIO
#define MAIN_HALL_TITLE "Main Hall"
#define MAIN_HALL_DESC "A large wooden door is the only thing between you and your freedom."

// MAIN HALL EXIT
#define MAIN_HALL_EXIT_NO_CLOTHES_NO_MONEY "You open the door an a guard standing next to the entrance notices you: Hey! Who are you? Don't move! You try to attack him but the fight with the officer has diminished your strength. The guard dispatches you easily. Rest in peace."
#define MAIN_HALL_EXIT_NO_CLOTHES_WITH_MONEY "You open the door an a guard standing next to the entrance notices you: Hey! Who are you? Don't move! You take out your bag of coins and offer it to the guard."
#define MAIN_HALL_BRIBE_SUCCESS "The guard accepts the bag\nGuard: Get out of here!\nYou wall to the street. At last free. Well done!"
#define MAIN_HALL_BRIBE_FAILURE "The guard refuses your money and hits you with his sword. You were so close to freedom but now it's time to sleep. Rest in peace."
#define MAIN_HALL_EXIT_GUARD_CLOTHES "You open the door an a guard standing next to the entrance notices you: \nGuard:Hey! How are you? You are the new one, aren't you?\nYou: Ehhmm yes, it's my break time.\nGuard: OK boy, take it easy, see you.\n You walk away taking a deep breath. At last you are free. Well done!"

//CELL EXIT 


// GENERAL
#define BAD_IDEA "That's not a good idea"
#define DOOR_LOCKED "The door is locked."
#define GAME_INTRO "Two guards scort you to your cell. A piece of cloth covers your eyes. A guard removes the piece of cloth from your eyes. \nGuard: Enjoy the view boy!! hahahaha. He pushes you into the cell"

#endif //end GLOBALS_H
