#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>
#include <vector>


void ParseInput(const std::string &inputString, std::vector<std::string> &inputWordsVector);

enum class Type { NPC, PLAYER, EXIT, ROOM, ITEM };

enum class Direction { NORTH, EAST, SOUTH, WEST };



#endif //end GLOBALS_H
