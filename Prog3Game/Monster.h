#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include "Character.h"

class Monster : public Character{
private:
std::string name;
public:
    Monster();
    Monster(std::string name,int hp,int x, int y,char type);
    ~Monster();
    std::string getName();
    void setName(std::string name);

};

#endif // MONSTER_H_INCLUDED
