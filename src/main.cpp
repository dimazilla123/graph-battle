#include "room.h"
#include "unit.h"


int main(int argc, char const *argv[]) {
  Room room;
  Unit* unit = new Unit("Unit",5,5,5,5,5,5);
  room.addUnit(unit);
  room.update();
  return 0;
}
