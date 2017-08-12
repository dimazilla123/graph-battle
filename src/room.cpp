#include "room.h"
#include "unit.h"
#include "item.h"
void Room::addUnit(Unit* unit)
{
  this->Unit_List.push_back(unit);
}
void Room::addItem(Item* item)
{
  this->Item_List.push_back(item);
}

void Room::removeUnit(int n)
{
  this->Unit_List.erase(this->Unit_List.begin()+n);
}
void Room::removeItem(int n)
{
  this->Item_List.erase(this->Item_List.begin()+n);
}

void Room::update()
{
  for(std::vector<Unit*>::iterator it=this->Unit_List.begin();it!=this->Unit_List.end();++it)
  {
    (*it)->prapareToMove();
    int status=(*it)->update(this->Unit_List,this->Item_List);
    if(status==DESTROYED)
    {
      this->Unit_List.erase(it);
      --it;
    }
  }
}
