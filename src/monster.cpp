#include "monster.h"
#include <vector>

Monster::Monster(char* name,int str,int dx,int intt,int wis,int speed,int imm):
 Unit(name,str,dx,intt,wis,speed,imm){};

bool Monster::makeMove(std::vector<Unit*> unitList,std::vector<Item*> itemList)
{
  
}
