#ifndef LITERALS_H
#define LITERALS_H

#include <string>

//Text descriptions

// CELL SCENARIO
std::string CELL_TITLE = "Cell";
std::string CELL_INIT_DESC = "There's an old dirty mattress, a bowl and a breadcrumbs on the floor,\na window to the west and an door to the east with a small opening.";
std::string CELL_MATTRESS = "Mattress";
std::string CELL_LOOK_MATTRESS = "And old dirty mattres. I'm not going to lay on that.";
std::string CELL_BOWL = "Bowl";
std::string CELL_DOOR = "Door";
std::string CELL_LOOK_BOWL = "A wood bowl. It smells like rancid nuts.";
std::string CELL_PIGEON = "Pigeon";
std::string CELL_LOOK_PIGEON = "It's a young rock pigeon. It was easy to catch.";
std::string CELL_BAR = "Bar";
std::string CELL_LOOK_IRON_BAR = "A slightly rusty iron bar.";
std::string CELL_BREADCRUMBS = "breadcrumbs";
std::string CELL_LOOK_BREADCRUMBS = "Dry breadcrumbs. Only an animal would eat this.";
std::string CELL_LOOK_WINDOW_NO_BARS = "A window hole.";
std::string CELL_WINDOW = "Window";
std::string CELL_LOOK_WINDOW = "A barred window. The bars are old and rusty.You can hear birds singing outside near the window. You see treetops.";
std::string CELL_LOOK_DOOR_OPENING = "Door opening to give meals to prisoners.\nA guard is sitting in a desk in the middle of an aisle. He wanders around and sits back again";
std::string CELL_LOOK_DOOR = "A door made of iron. It has a small opening";
std::string CELL_LOOK_GUARD = "A cell guard. Was he the one who pushed me into the cell? Grgrgr.";
std::string CELL_LOOK_DEAD_GUARD = "A dead guard lays on the floor.";
std::string CELL_SEARCH_GUARD_DEAD = "He has a cell key in his pocket";
std::string CELL_SEARCH_GUARD_ALIVE = "That's not a good idea.";
std::string CELL_KEY = "Cell key";
std::string CELL_LOOK_KEY = "A cell key.";
std::string CELL_GUARD_SWORD = "Long sword";


//CELL EXIT 
std::string CELL_EXIT_HIT_MACE = "You hit the window.\nThe window frame and the bars fall down altogether to the woods outside.";
std::string CELL_EXIT_HIT_BAREHANDED = "You hit the window but nothing happens.";
std::string CELL_EXIT_COMBINE_ROPE_SWORD = "You tie the rope to the sword.";
std::string CELL_EXIT_USE_ROPE = "Carefully you anchor the sword to the door and climb down through the window.";
std::string CELL_EXIT_SUCCESS = "You enter the woods.\nAt last you are free. Good job!";

// AISLE 1 SCENARIO
std::string AISLE1_TITLE = "Cells Aisle";
std::string AISLE1_INIT_DESC = "Light come through small holes along the walls. To the east stands a door. To the west, your cell.";
std::string AISLE1_LOOK_DOOR = "The door is made of iron.";
std::string AISLE1_DOOR = "Door";
std::string AISLE1_DESK = "Desk";
std::string AISLE1_LOOK_DESK = "A wood desk. There's something carved on it: DUMB WHO READS IT";

// AISLE 2 SCENARIO
std::string AISLE2_TITLE = "Armoy Aisle";
std::string AISLE2_INIT_DESC = "There's a door to the north, another to the south and the cells aisle to the west.\nTo the east the intendence aisle leeds to the upstairs floor";
std::string AISLE2_LOOK_NORTH_DOOR = "An iron door.";
std::string AISLE2_LOOK_SOUTH_DOOR = "An iron door.";
std::string AISLE2_DOOR = "Door";
std::string AISLE2_EXIT = "Exit";

// AISLE 3 SCENARIO
std::string AISLE3_TITLE = "Intendence Aisle";
std::string AISLE3_INIT_DESC = "To the north you can see stairs going up the upper floor.\nTo the south there's a half opened door. To the west, the armory aisle.";
std::string AISLE3_LOOK_UPSTAIRS = "Stairs leading to the upper floor.";
std::string AISLE3_LOOK_SOUTH_DOOR = "An iron door.";
std::string AISLE3_DOOR = "Door";
std::string AISLE3_EXIT = "Exit";

// ARMORY SCENARIO
std::string ARMORY_TITLE = "Armory";
std::string ARMORY_INIT_DESC = "There is a shield hanging high on the wall, they use it as an ornament.\nClose to the wall stands a metallic closet.";
std::string ARMORY_CLOSET = "Closet";
std::string ARMORY_LOOK_CLOSET = "It's a metallic closet. It's locked.";
std::string ARMORY_SHIELD = "Shield";
std::string ARMORY_LOOK_SHIELD = "A metallic shield with geometric decorations.";
std::string ARMORY_CANT_TAKE_SHIELD = "I can't reach it.";

// GUARDROOM SCENARIO
std::string GUARDROOM_TITLE = "Guardroom";
std::string GUARDROOM_INIT_DESC = "There is a table in the middle of the room and a closet.";
std::string GUARDROOM_LOOK_CLOSED_CLOSET = "It's a small metallic closet. It's locked.";
std::string GUARDROOM_CLOSED_CLOSET = "A small metallic closet.";
std::string GUARDROOM_LOOK_OPEN_CLOSET = "It has two tags: Armory and Cleaning staff. A key hangs below each tag.";
std::string GUARDROOM_KEY = "Cleaning staff key";


// TOOLROOM SCENARIO
std::string TOOLROOM_TITLE = "Toolroom";
std::string TOOLROOM_INIT_DESC = "You can see a work table and a closet next to the wall.A guard is leaning on the table.\nLooking at an two handed iron mace. He has noticed you!";
std::string TOOLROOM_LOOK_CLOSET_LOCKED = "It's a locked tools closet.";
std::string TOOLROOM_CLOSET = "Closet";
std::string TOOLROOM_ROPE = "Rope";
std::string TOOLROOM_LOOK_ROPE = "A braided hemp rope.";
std::string TOOLROOM_TWOHANDED_MACE = "Two-handed mace";
std::string TOOLROOM_LOOK_TWOHANDED_MACE = "A heavy two-handed iron mace with a long handle.";
std::string TOOLROOM_GUARD_ALIVE = "A guard with an iron mace.";
std::string TOOLROOM_GUARD_DEAD = "A guard dead's corpse.";
std::string TOOLROOM_SEARCH_GUARD = "Nothing useful on him.";
std::string TOOLROOM_PLAYER_DEAD = "You didn't have much luck this time. Rest in peace.";

// UPSTAIRS SCENARIO
std::string UPSTAIRS_TITLE = "Upstairs floor";
std::string UPSTAIRS_INIT_DESC = "If you face west you can hear a snore coming from the door.\nTo the east you see a large wooden door that leads to the entrance of the prison.\nTo the north, another door.";
std::string UPSTAIRS_DESC_GUARD_DEAD = "If you face west you see the bedroom entrance, To the east you see a large wooden door \nthat leads to the entrance of the prison. To the north, another door.";
std::string UPSTAIRS_LOOK_NORTH_DOOR = "A metallic door.";
std::string UPSTAIRS_LOOK_WEST_DOOR = "A metallic door. Someone seems to be sleeping on this room.";
std::string UPSTAIRS_LOOK_EAST = "Theres another room leading to a large wooden door. It's like a hall room.";

// GUARDS BEDROOM SCENARIO
std::string GUARDS_BEDROOM_TITLE = "Guards bedroom";
std::string GUARDS_BEDROOM_INIT_DESC = "Two rows of beds in front of you and a wardrobe. A young guard is sleeping in one of them.\nHe is wearing a leather cuirass.";
std::string GUARDS_BEDROOM_GUARD_ALIVE = "A young guard is sleeping on one of them.";
std::string GUARDS_BEDROOM_LOOK_GUARD_ALIVE = "A young guard, he doesn't look older than twenty years old. He is wearing a leather cuirass.";
std::string GUARDS_BEDROOM_LOOK_GUARD_DEAD = "A guards corpse.";
std::string GUARDS_BEDROOM_SEARCH_GUARD_ALIVE = "You try to search his pockets and he wakes up. That was not a good idea.\nThe guard screams and a guard officer enters the room. You are dead.";
std::string GUARDS_BEDROOM_SEARCH_GUARD_DEAD = "He has a bag of coins in his pocket.";
std::string GUARDS_BEDROOM_CLOSED_WARDROBE = "Wardrobe";
std::string GUARDS_BEDROOM_LOOK_CLOSED_WARDROBE = "A wooden wardrobe with decorative figures carved on it. It's closed.";
std::string GUARDS_BEDROOM_LOOK_OPEN_WARDROBE = "It has guard clothes.";
std::string GUARDS_BEDROOM_LOOK_CLOTHES = "A guard outfit.";
std::string GUARDS_BEDROOM_LOOK_BAG_OF_COINS = "A leather bag of coins.";
std::string GUARDS_BEDROOM_LOOK_COINS = " A nice amount of coins.";
std::string GUARDS_BEDROOM_CUIRASS = "Leather cuirass.";
std::string GUARDS_BEDROOM_LOOK_CUIRASS = "A leather cuirass with some bronze rivets. It looks nice.";
std::string GUARDS_BEDROOM_HELMET = "Helmet";
std::string GUARDS_BEDROOM_LOOK_HELMET = "A metallic helmet.";

// MEETINGS ROOM SCENARIO
std::string MEETINGS_ROOM_TITLE = "Meetings room";
std::string MEETINGS_ROOM_INIT_DESC = "You see a large table sorrounded by chairs.\nSitting in one of them an officer is staring at you: Who the hell are you? He stands up and fights you.";
std::string MEETINGS_ROOM_LOOK_OFFICER_ALIVE = "The guard officer in charge of the prison. He is a tall man with strong arms.";
std::string MEETINGS_ROOM_LOOK_OFFICER_DEAD = "The prison officer corpse.";
std::string MEETINGS_ROOM_SEARCH_OFFICER_DEAD = "The officer keeps a key on his pocket. It has a tag attached which says: Main Hall.";
std::string MEETINGS_ROOM_PLAYER_DEAD = "You fought well but this opponent is a hard one. Rest in peace.";
std::string MEETINGS_ROOM_LOOK_LARGE_TABLE = "A large oak table.";
std::string MEETINGS_ROOM_OFFICER_SWORD = "Large officer sword";
std::string MEETINGS_ROOM_LOOK_OFFICER_SWORD = "A large sword with some carved patterns on the blade and an ivory handle.";

// MAIN HALL SCENARIO
std::string MAIN_HALL_TITLE = "Main Hall";
std::string MAIN_HALL_INIT_DESC = "A large wooden door is the only thing between you and your freedom.";
std::string MAIN_HALL_STREET_EXIT = "The door leads to the street.";

// MAIN HALL EXIT
std::string MAIN_HALL_EXIT_NO_CLOTHES_NO_MONEY = "You open the door an a guard standing next to the entrance notices you:\nHey! Who are you? Don't move! You try to attack him\nbut the fight with the officer has diminished your strength. The guard dispatches you easily. Rest in peace.";
std::string MAIN_HALL_EXIT_NO_CLOTHES_WITH_MONEY = "You open the door an a guard standing next to the entrance notices you: Hey! Who are you? Don't move!\nYou take out your bag of coins and offer it to the guard.";
std::string MAIN_HALL_BRIBE_SUCCESS = "The guard accepts the bag\nGuard: Get out of here!\nYou wall to the street. At last free. Well done!";
std::string MAIN_HALL_BRIBE_FAILURE = "The guard refuses your money and hits you with his sword. You were so close to freedom but now it's time to sleep. Rest in peace.";
std::string MAIN_HALL_EXIT_GUARD_CLOTHES = "You open the door an a guard standing next to the entrance notices you: \nGuard:Hey! How are you? You are the new one, aren't you?\nYou: Ehhmm yes, it's my break time.\nGuard: OK boy, take it easy, see you.";
std::string MAIN_HALL_EXIT_SUCCESS = "You walk away taking a deep breath. At last you are free. Well done!";
std::string MAIN_HALL_KEY = "Main Hall Key";

// GENERAL
std::string BAD_IDEA = "That's not a good idea.";
std::string CANT_DO = "I can't do that.";
std::string DOOR_LOCKED = "The door is locked.";
std::string GAME_INTRO = "Two guards scort you to your cell.\nA piece of cloth covers your eyes.\nA guard removes the piece of cloth from your eyes. \nGuard: Enjoy the view boy!! hahahaha. He pushes you into the cell";
std::string DONT_UNDERSTAND = "I don't understand you. Try again.";
std::string NOT_DOING_THAT = "I'm not gonna do that.";
std::string EXIT_DESC = "It's a room exit.";
std::string DOOR = "Door";
std::string DOOR_DESC = "It's a door leading to another room.";
std::string EXIT_STAIRS_DESC = "Stairs leading to another floor.";
std::string CHAIR = "Chair";
std::string LOOK_CHAIR = "A pine wood chair.";
std::string GUARD = "Cell guard";
std::string OFFICER = "Prison officer";
std::string PLAYER = "Player";
std::string LOOK_PLAYER = "It's me!.";
std::string HIT_MESSAGE = "Your hit damage: ";

// COMMANDS LIST
std::string COMMANDS_LIST = "I: Shows your inventory\nQ: Quit the game\nTAKE something: you pick up something\nDROP something\nPUT something INTO something\nHIT someone\nLOOk something/someone\nSEARCH someone\nOPEN something\nCLOSE something\nTIE something TO something\nDETACH something FROM something\nGO north,n\nGO south,s\nGO east,e\nGO west,w\n";
std::string PLAYER_NO_ITEMS = "You don't have any items.";
std::string TAKE_ITEM = "You have taken an item.";
std::string NO_ITEM_IN_INV = "You don't have the item.";
std::string NO_ITEM_IN_ROOM = "No such an item in the room.";
std::string DROP_ITEM = "You have dropped an item.";
std::string MAX_INV = "You can't carry more than five objects";
std::string ENEMY_NOT_HERE = "There's no one to fight here";
#endif //LITERALS_H