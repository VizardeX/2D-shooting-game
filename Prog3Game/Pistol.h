#ifndef PISTOL_H
#define PISTOL_H
#include "Gun.h"
#include <string>
#include "Game.h"

class Pistol : public Gun{

public:
    Pistol();
    Pistol(std::string name);
    ~Pistol();

     virtual void useSpecial(Hero& h1 , Object*** map){
         std::cout<<"it is in pistol"<<std::endl;
            h1.getGun()->setBullets(h1.getGun()->getBullets() - 4);
            int x = h1.getPosX();
            int y = h1.getPosY();

            //s
           for(int i = 1;i <= h1.getGun()->getRange()&& y+i <15 ;i++){

            if(map[y+i][x]->getType() == 'T') {
            TankMonster* tankMonster = static_cast<TankMonster*>(&*map[y + i][x]);
            if(tankMonster->getshield() > h1.getGun()->getDmg()){// if shield more than damage
                    tankMonster->setshield(tankMonster->getshield()-h1.getGun()->getDmg() );
                    break;
            }else{
                tankMonster->setHp(tankMonster->getHp()-(h1.getGun()->getDmg()-tankMonster->getshield()) );
            tankMonster->setshield(0);
            break;
            }
            }
            if(map[y+i][x]->getType() == 'G') {
                GhostMonster* ghostMonster = static_cast<GhostMonster*>(&*map[y + i][x]);
                ghostMonster->setHp(ghostMonster->getHp()-h1.getGun()->getDmg());
                break;
            }

            }

             //w
           for(int i = 1;i <= h1.getGun()->getRange()&& y-i >=0 ;i++){

            if(map[y-i][x]->getType() == 'T') {
            TankMonster* tankMonster = static_cast<TankMonster*>(&*map[y - i][x]);
            if(tankMonster->getshield() > h1.getGun()->getDmg()){// if shield more than damage
                    tankMonster->setshield(tankMonster->getshield()-h1.getGun()->getDmg() );
                    break;
            }else{
                tankMonster->setHp(tankMonster->getHp()-(h1.getGun()->getDmg()-tankMonster->getshield()) );
            tankMonster->setshield(0);
            break;
            }
            }
            if(map[y-i][x]->getType() == 'G') {
                GhostMonster* ghostMonster = static_cast<GhostMonster*>(&*map[y - i][x]);
                ghostMonster->setHp(ghostMonster->getHp()-h1.getGun()->getDmg());
                break;
            }

            }

             //a
           for(int i = 1;i <= h1.getGun()->getRange()&& x-i >=0 ;i++){

            if(map[y][x-i]->getType() == 'T') {
            TankMonster* tankMonster = static_cast<TankMonster*>(&*map[y][x-i]);
            if(tankMonster->getshield() > h1.getGun()->getDmg()){// if shield more than damage
                    tankMonster->setshield(tankMonster->getshield()-h1.getGun()->getDmg() );
                    break;
            }else{
                tankMonster->setHp(tankMonster->getHp()-(h1.getGun()->getDmg()-tankMonster->getshield()) );
            tankMonster->setshield(0);
            break;
            }
            }
            if(map[y][x-i]->getType() == 'G') {
                GhostMonster* ghostMonster = static_cast<GhostMonster*>(&*map[y][x-i]);
                ghostMonster->setHp(ghostMonster->getHp()-h1.getGun()->getDmg());
                break;
            }

            }

            //d
           for(int i = 1;i <= h1.getGun()->getRange()&& x+i <15 ;i++){

            if(map[y][x+i]->getType() == 'T') {
            TankMonster* tankMonster = static_cast<TankMonster*>(&*map[y][x+i]);
            if(tankMonster->getshield() > h1.getGun()->getDmg()){// if shield more than damage
                    tankMonster->setshield(tankMonster->getshield()-h1.getGun()->getDmg() );
                    break;
            }else{
                tankMonster->setHp(tankMonster->getHp()-(h1.getGun()->getDmg()-tankMonster->getshield()) );
            tankMonster->setshield(0);
            break;
            }
            }
            if(map[y][x+i]->getType() == 'G') {
                GhostMonster* ghostMonster = static_cast<GhostMonster*>(&*map[y][x+i]);
                ghostMonster->setHp(ghostMonster->getHp()-h1.getGun()->getDmg());
                break;
            }

            }


    }


};




#endif
