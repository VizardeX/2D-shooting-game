#ifndef AMMO_H
#define AMMO_H
#include "Item.h"


class Ammo : public Item {
private:
    int BulletAmount;
public:
    Ammo();
    Ammo(int x,int y,int BulletAmount) ;
    ~Ammo();
    int getBulletAmount()const;
    void setBulletAmount(int bullets);

};

#endif // AMMO_H_INCLUDED
