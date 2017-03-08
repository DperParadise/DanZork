#ifndef COMMANDS_H
#define COMMANDS_H

#include <memory>
#include <iostream>
#include <cstdlib>
#include "item.h"
#include "weapon.h"
#include "entity.h"
#include "exit.h"
#include "player.h"
#include "npc.h"
#include "room.h"
#include <map>
#include <vector>
#include <string>


typedef std::shared_ptr<Entity> ptrEntity;
typedef std::shared_ptr<Exit> ptrExit;
typedef std::shared_ptr<Item> ptrItem;
typedef std::shared_ptr<Weapon> ptrWeapon;
typedef std::shared_ptr<Creature> ptrCreature;
typedef std::shared_ptr<Player> ptrPlayer;
typedef std::shared_ptr<Npc> ptrNpc;
typedef std::shared_ptr<Room> ptrRoom;


typedef std::list<ptrEntity>::iterator listIter;


void TransferItem(ptrItem ptrSrc, ptrEntity ptrDst);
void Take(ptrPlayer player, ptrItem item);
void Drop(ptrPlayer player, ptrItem item);
void PutInto(ptrItem playerItem, ptrItem item);
std::map<std::string, std::string> GetItemsToCombine(const std::vector<std::string>& words);
void OpenExit(std::string direction, ptrPlayer ptrPlayer);
void OpenItem(ptrItem ptrItem);
void CloseExit(ptrExit ptrExit);
void LockDoor(ptrExit);
void CloseItem(ptrItem ptrItem);
listIter FindEntity(ptrEntity entity, std::list<ptrEntity> &list);
listIter FindEntityByName(std::string entityName, std::list<ptrEntity> &list);
void StartCombat(ptrPlayer player, ptrNpc npc);
int  GetDamage();
GoDirection Go(ptrPlayer player, Direction dir);
void Search(ptrPlayer player, ptrNpc npc);
void Look(ptrEntity entity, std::list<ptrEntity> &listCreatures);
void Hit(ptrEntity target);


#endif //COMMANDS_H
