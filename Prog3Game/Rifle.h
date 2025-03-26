#ifndef RIFLE_H_INCLUDED
#define RIFLE_H_INCLUDED
#include "Gun.h"
#include <string>

class Rifle : public Gun{

public:
    Rifle();
    Rifle(std::string name);
    ~Rifle();

    virtual void useSpecial(Hero& h1 , Object*** map){
            h1.getGun()->setBullets(h1.getGun()->getBullets() - 3);
            int x = h1.getPosX();
            int y = h1.getPosY();


             //w
           for(int i = 1;i <= h1.getGun()->getRange()&& y-i >=0 ;i++){

            if(map[y-i][x]->getType() == 'T') {
            TankMonster* tankMonster = static_cast<TankMonster*>(&*map[y - i][x]);
            if(tankMonster->getshield() > h1.getGun()->getDmg()){// if shield more than damage
                    tankMonster->setshield(tankMonster->getshield()-h1.getGun()->getDmg() );
            }else{
                tankMonster->setHp(tankMonster->getHp()-(h1.getGun()->getDmg()-tankMonster->getshield()) );
            tankMonster->setshield(0);
            }
            }
            if(map[y-i][x]->getType() == 'G') {
                GhostMonster* ghostMonster = static_cast<GhostMonster*>(&*map[y - i][x]);
                ghostMonster->setHp(ghostMonster->getHp()-h1.getGun()->getDmg());
            }

            }

             //a
           for(int i = 1;i <= h1.getGun()->getRange()&& x-i >=0 ;i++){

            if(map[y][x-i]->getType() == 'T') {

            TankMonster* tankMonster = static_cast<TankMonster*>(&*map[y][x-i]);
            if(tankMonster->getshield() > h1.getGun()->getDmg()){// if shield more than damage
                    tankMonster->setshield(tankMonster->getshield()-h1.getGun()->getDmg() );
            }else{
                tankMonster->setHp(tankMonster->getHp()-(h1.getGun()->getDmg()-tankMonster->getshield()) );
            tankMonster->setshield(0);
            }
            }
            if(map[y][x-i]->getType() == 'G') {
                GhostMonster* ghostMonster = static_cast<GhostMonster*>(&*map[y][x-i]);
                ghostMonster->setHp(ghostMonster->getHp()-h1.getGun()->getDmg());
            }

            }

            //d
           for(int i = 1;i <= h1.getGun()->getRange()&& x+i <15 ;i++){

            if(map[y][x+i]->getType() == 'T') {

            TankMonster* tankMonster = static_cast<TankMonster*>(&*map[y][x+i]);
            if(tankMonster->getshield() > h1.getGun()->getDmg()){// if shield more than damage
                    tankMonster->setshield(tankMonster->getshield()-h1.getGun()->getDmg() );
            }else{
                tankMonster->setHp(tankMonster->getHp()-(h1.getGun()->getDmg()-tankMonster->getshield()) );
            tankMonster->setshield(0);
            }
            }
            if(map[y][x+i]->getType() == 'G') {
                GhostMonster* ghostMonster = static_cast<GhostMonster*>(&*map[y][x+i]);
                ghostMonster->setHp(ghostMonster->getHp()-h1.getGun()->getDmg());
            }

            }


    }

};





#endif
