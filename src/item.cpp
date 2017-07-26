#include "item.h"

Item::Item(char* name,int str,int dx,int intt,int wis,int speed,int imm)
{
  this->name=name;
  this->Str=str;
  this->Dx=dx;
  this->Intt=intt;
  this->Wis=wis;
  this->Speed=speed;
  this->Imm=imm;
}

Item::~Item()
{
  
}
