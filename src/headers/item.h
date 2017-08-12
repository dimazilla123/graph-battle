#ifndef ITEM_H
#define ITEM_H

class Item {
public:
  /* data */
  char* Name;
  int Str;
  int Dx;
  int Intt;
  int Wis;
  int Speed;
  int Imm;

  int BitMask=0;

  Item (char* name,int str,int dx,int intt,int wis,int speed,int imm);
  virtual ~Item ();
};

#endif
