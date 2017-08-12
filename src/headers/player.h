#include "unit.h"
#include <vector>
//#include "interface.h"

class Player : public Unit {
private:
  //Interface Interf;

public:
  Player (char* name,int str,int dx,int intt,int wis,int speed,int imm);//,Interface intr);
  virtual ~Player ();
  void onDestroy();
  void makeMove(std::vector<Unit*> unitList,std::vector<Item*> itemList);
};
