#ifndef UNIT_H
#define UNIT_H

#include <vector>
#include "item.h"

#ifndef SUCCSES_SHOT
#define SUCCSES_SHOT 0
#endif
#ifndef FAIL_SHOT
#define FAIL_SHOT 1
#endif
#ifndef DESTROYED
#define DESTROYED 1
#endif
#ifndef ALIVE
#define ALIVE 0
#endif
#ifndef INV_PUSHED
#define INV_PUSHED 0
#endif

class Unit {
public:
  /* data */
  int attack(Unit* target);
  void dealDamage(int dmg);
  void wait();
  virtual void onDestroy()=0;

  std::vector<Item*> Inventory;

  char* Name;
  int Str;
  int Dx;
  int Intt;
  int Wis;
  int Speed;
  int Imm;

  int MaxHp;
  int Hp;
  int Dmg;
  int AC;
  int RegRate;
  int MovePoints;
  int MaxMana;
  int Mana;
  int RegManaRate;


  Unit(char* name,int str,int dx,int intt,int wis,int speed,int imm);
  //virtual ~Unit ();
  void updateChars();
  void prapareToMove();
  void regenerate();
  int addItemToInventory(Item* item);
  void removeItemFromInventory(int n);
  int update(std::vector<Unit*> unitList,std::vector<Item*> itemList);
  virtual void makeMove(std::vector<Unit*> unitList,std::vector<Item*> itemList)=0;
};

#endif
