#ifndef ITEM_H
#define ITEM_H

class Item {
public:
  /* data */
  char* name;
  int Str;
  int Dx;
  int Intt;
  int Wis;
  int Speed;
  int Imm;

  Item (char* name,int str,int dx,int intt,int wis,int speed,int imm);
  virtual ~Item ();
};

#endif
