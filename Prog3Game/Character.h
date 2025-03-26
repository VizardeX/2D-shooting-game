#ifndef CHARACTER_H
#define CHARACTER_H
#include "Object.h"
#include <utility>

class Character : public Object{

private:
    int hp;
    std::pair <int,int> position;

public:
    int getHp()const;
    void setHp(int hp);
    int getPosX()const;
    int getPosY()const;
    void setPos(int x,int y);
    Character();
    Character(int hp,int x,int y,char type) ;
    ~Character();

};




#endif
