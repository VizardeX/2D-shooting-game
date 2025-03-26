#ifndef MEDIC_H_INCLUDED
#define MEDIC_H_INCLUDED

#include "Hero.h"

class MedicHero : public Hero{
private:
     int healamount;
     int special = 1;
public:
    MedicHero();
    MedicHero(int hp,int x,int y, Gun* gun,int healamount);
    ~MedicHero();
    int gethealamount();
    void sethealamount(int healamount);

    virtual void useSpecial(){
    if(special >0){
        this->setHp(this->getHp()+this->gethealamount());
        special--;
    } else{
    std::cout<<"Cant use special anymore"<<std::endl;
    }
    };

};


#endif // MEDIC_H_INCLUDED
