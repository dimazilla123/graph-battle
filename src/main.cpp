#include "room.h"
#include "monster.h"
#include "item.h"
#include "player.h"


int main(int argc, char const *argv[]) {
  Room room;

  Item* item1=new Item("Sword",2,0,0,0,0,0);
  Item* item2=new Item("Hammer",8,0,0,0,0,0);

  Monster* unit = new Monster("Unit",5,5,5,5,5,5);

  Player* player = new Player("Player",5,5,5,5,5,5);

  unit->addItemToInventory(item1);
  player->addItemToInventory(item2);

  room.addUnit(unit);
  room.addUnit(player);

  room.update();
  return 0;
}
