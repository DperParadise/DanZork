#ifndef COMMANDS_H
#define COMMANDS_H

#include <memory>
#include <iostream>
#include "item.h"
#include "item.h"
#include "weapon.h"
#include "entity.h"
#include "exit.h"
#include "player.h"
#include "npc.h"
#include "room.h"

typedef std::shared_ptr<Entity> ptrEntity;
typedef std::shared_ptr<Exit> ptrExit;
typedef std::shared_ptr<Item> ptrItem;
typedef std::shared_ptr<Weapon> ptrWeapon;
typedef std::shared_ptr<Player> ptrPlayer;
typedef std::shared_ptr<Npc> ptrNpc;
typedef std::shared_ptr<Room> ptrRoom;


typedef std::list<ptrEntity>::iterator listIter;


void TransferItem(ptrItem ptrSrc, ptrEntity ptrDst);
void TieTo(ptrWeapon ptrWeapon, ptrItem ptrItem);
void Detach(ptrWeapon ptrWeapon, ptrItem ptrItem);
void Take(ptrPlayer player, ptrItem item);
void PutInto(ptrItem playerItem, ptrItem item);
void OpenExit(ptrExit ptrExit);
void OpenItem(ptrItem ptrItem);
void CloseExit(ptrExit ptrExit);
void CloseItem(ptrItem ptrItem);
listIter FindEntity(ptrEntity entity, std::list<ptrEntity> &list);
void StartCombat(ptrPlayer player, ptrNpc npc);
bool Go(ptrPlayer player, Direction dir);
void Search(ptrNpc npc, ptrPlayer player);
void Look(ptrEntity);


#endif //COMMANDS_H
