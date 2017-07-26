#include "unit.h"
#include <stdlib.h>

Unit::~Unit()
{

}

Unit::Unit(char* name,int str,int dx,int intt,int wis,int speed,int imm)
{
  this->Name=name;
  this->Str=str;
  this->Dx=dx;
  this->Intt=intt;
  this->Wis=wis;
  this->Speed=speed;
  this->Imm=imm;
  this->updateChars();
  this->Hp=this->MaxHp;
  this->Mana=this->MaxMana;
}

void Unit::updateChars()
{
  this->MaxHp=this->Str*3;
  this->Dmg=this->Str;
  this->AC=20-this->Dx;
  this->RegRate=this->Imm/5;
  this->MaxMana=this->Wis;
  this->RegManaRate=this->Intt/5;

  for(std::vector<Item*>::iterator i=this->Inventory.begin();i!=this->Inventory.end();++i)
  {
    this->Str+=(*i)->Str;
    this->Dx+=(*i)->Dx;
    this->Intt+=(*i)->Intt;
    this->Wis+=(*i)->Wis;
    this->Speed+=(*i)->Speed;
    this->Imm+=(*i)->Imm;
  }
}

void Unit::prapareToMove()
{
  this->updateChars();
  this->MovePoints+=this->Speed;
}

void Unit::regenerate()
{
  //regeneration
  this->Hp+=this->RegRate;
  this->Mana+=this->RegManaRate;

  if(this->Hp>this->MaxHp) this->Hp=this->MaxHp;
  if(this->Mana>this->MaxMana) this->Mana=this->MaxMana;

}

int Unit::attack(Unit* target)
{
  this->MovePoints-=12;
  int targetAc=target->AC - this->AC;
  if((rand()%20)>=targetAc)
  {
    target->dealDamage(this->Dmg);
    return SUCCSES_SHOT;
  }
  else
  {
    return FAIL_SHOT;
  }
  return SUCCSES_SHOT;
}

void Unit::dealDamage(int dmg)
{
  this->Hp-=dmg;
}

int Unit::update(std::vector<Unit*> unitList,std::vector<Item*> itemList)
{
  while(this->makeMove(unitList,itemList))
  {
    if(this->Hp<=0)
    {
      this->OnDestroy();
      return DESTROYED;
    }
    this->regenerate();
  }
  return ALIVE;
}
int Unit::addItemToInventory(Item* item)
{
  this->Inventory.push_back(item);
  return INV_PUSHED;
}

void Unit::removeItemFromInventory(int n)
{
  this->Inventory.erase(this->Inventory.begin()+n);
}
