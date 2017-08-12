#include "player.h"
//#include "interface.h"
#include <stdio.h>
#include <vector>

Player::Player(char* name,int str,int dx,int intt,int wis,int speed,int imm):
 Unit(name,str,dx,intt,wis,speed,imm)
{
  //this->Interf=intf;
}

Player::~Player()
{

}

void Player::makeMove(std::vector<Unit*> unitList,std::vector<Item*> itemList)
{
  this->wait();
  for(std::vector<Unit*>::iterator it=unitList.begin();it!=unitList.end();++it)
  {
    printf("Unit: %s\n", (*it)->Name);
    printf("Unit's inventory:\n");
    for(std::vector<Item*>::iterator jt=(*it)->Inventory.begin();jt!=(*it)->Inventory.end();++jt)
    {
      printf("\t%s\n", (*jt)->Name);
    }
  }
}

void Player::onDestroy()
{

}
