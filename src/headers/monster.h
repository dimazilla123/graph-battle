#ifndef MONSTER_H
#define MONSTER_H

#include "unit.h"
#include "item.h"
#include <vector>

class Monster : public Unit
{
public:
  Monster(char* name,int str,int dx,int intt,int wis,int speed,int imm);
  void makeMove(std::vector<Unit*> unitList,std::vector<Item*> itemList);
  void onDestroy();
};

#endif
