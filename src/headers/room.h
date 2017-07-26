#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "unit.h"
#include "item.h"

class Room {
private:
  /* data */
  std::vector<Unit*> Unit_List;
  std::vector<Item*> Item_List;
public:
  Room ();
  virtual ~Room ();

  void addUnit(Unit *unit);
  void removeUnit(int n);
  void addItem(Item* item);
  void removeItem(int n);
  void update();
};

#endif
