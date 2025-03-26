#ifndef GAME_H
#define GAME_H
#include "Object.h"
#include "Hero.h"
#include "TankMonster.h"
#include "GhostMonster.h"
class Game {

private:
    Object*** grid;
    int rows ;
    int columns ;
    Hero* hero;
    static int round;
public:
    Hero* getHero();
    Game();
    Game(int rows,int columns) ;
    ~Game();
    int getRows();
    void setRows(int columns);
    int getColumns();
    void setColumns(int columns);
    void move(Hero& h1 , char direction);
    void GenerateMap();
    void showMap();
    int getRound();
    void addRound();
    void useGunSpecial();
    int checkGameOver();
    void updateMap();
    void startGame();

     void FireGun(char direction){//remove comments when the big number issue is fixed
    if(hero->getGun()->getBullets()<=0){
            std::cout << "not enough bullets" << std::endl;
            return;
}
            hero->getGun()->setBullets(hero->getGun()->getBullets() - 1);
            int x = hero->getPosX();
            int y = hero->getPosY();
        switch (direction) {

        case 's': //down
           for(int i = 1;i <= hero->getGun()->getRange()&& y+i <15 ;i++){
            std::cout << "bullet at " << y+i<<std::endl;

            if(grid[y+i][x]->getType() == 'T') {
            std::cout << "tank at " << y+i<<std::endl;
            TankMonster* tankMonster = static_cast<TankMonster*>(grid[y + i][x]);
            if(tankMonster->getshield() > hero->getGun()->getDmg()){// if shield more than damage
                    tankMonster->setshield(tankMonster->getshield()-hero->getGun()->getDmg() );
                std::cout << "tank health " << tankMonster->getHp()<<std::endl;
                std::cout << "tank shield " << tankMonster->getshield()<<std::endl;
                break;
            }else{
                std::cout << "tank health at first " << tankMonster->getHp()<<std::endl;
                std::cout << "tank shield at first " << tankMonster->getshield()<<std::endl;
                std::cout <<(hero->getGun()->getDmg()-tankMonster->getshield())<<std::endl;
                tankMonster->setHp(tankMonster->getHp()-(hero->getGun()->getDmg()-tankMonster->getshield()) );
            tankMonster->setshield(0);
                std::cout << "tank health " << tankMonster->getHp()<<std::endl;
                std::cout << "tank shield " << tankMonster->getshield()<<std::endl;
                break;
            }
            }
            if(grid[y+i][x]->getType() == 'G') {
                GhostMonster* ghostMonster = static_cast<GhostMonster*>(grid[y + i][x]);
                std::cout << "ghostMonster health at first " << ghostMonster->getHp()<<std::endl;
                ghostMonster->setHp(ghostMonster->getHp()-hero->getGun()->getDmg());
                std::cout << "ghostMonster health after " << ghostMonster->getHp()<<std::endl;
                break;
            }

            }


            break;

        case 'a': //left
           for(int i = 1;i <= hero->getGun()->getRange()&& x-i >=0 ;i++){
            std::cout << "bullet at " << x-i<<std::endl;

            if(grid[y][x-i]->getType() == 'T') {
            std::cout << "tank at " << x-i<<std::endl;
            TankMonster* tankMonster = static_cast<TankMonster*>(grid[y][x - i]);
            if(tankMonster->getshield() > hero->getGun()->getDmg()){// if shield more than damage
                    tankMonster->setshield(tankMonster->getshield()-hero->getGun()->getDmg() );
                std::cout << "tank health " << tankMonster->getHp()<<std::endl;
                std::cout << "tank shield " << tankMonster->getshield()<<std::endl;
                break;
            }else{
                std::cout << "tank health at first " << tankMonster->getHp()<<std::endl;
                std::cout << "tank shield at first " << tankMonster->getshield()<<std::endl;
                std::cout <<(hero->getGun()->getDmg()-tankMonster->getshield())<<std::endl;
                tankMonster->setHp(tankMonster->getHp()-(hero->getGun()->getDmg()-tankMonster->getshield()) );
            tankMonster->setshield(0);
                std::cout << "tank health " << tankMonster->getHp()<<std::endl;
                std::cout << "tank shield " << tankMonster->getshield()<<std::endl;
                break;
            }
            }
            if(grid[y][x-i]->getType() == 'G') {
                GhostMonster* ghostMonster = static_cast<GhostMonster*>(grid[y][x - i]);
                std::cout << "ghostMonster health at first " << ghostMonster->getHp()<<std::endl;
                ghostMonster->setHp(ghostMonster->getHp()-hero->getGun()->getDmg());
                std::cout << "ghostMonster health after " << ghostMonster->getHp()<<std::endl;
                break;
            }

            }
            break;

        case 'w': //up
           for(int i = 1;i <= hero->getGun()->getRange()&& y-i >=0 ;i++){
            std::cout << "bullet at " << y-i<<std::endl;

            if(grid[y-i][x]->getType() == 'T') {
            std::cout << "tank at " << y+i<<std::endl;
            TankMonster* tankMonster = static_cast<TankMonster*>(grid[y - i][x]);
            if(tankMonster->getshield() > hero->getGun()->getDmg()){// if shield more than damage
                    tankMonster->setshield(tankMonster->getshield()-hero->getGun()->getDmg() );
                std::cout << "tank health " << tankMonster->getHp()<<std::endl;
                std::cout << "tank shield " << tankMonster->getshield()<<std::endl;
                break;
            }else{
                std::cout << "tank health at first " << tankMonster->getHp()<<std::endl;
                std::cout << "tank shield at first " << tankMonster->getshield()<<std::endl;
                std::cout <<(hero->getGun()->getDmg()-tankMonster->getshield())<<std::endl;
                tankMonster->setHp(tankMonster->getHp()-(hero->getGun()->getDmg()-tankMonster->getshield()) );
            tankMonster->setshield(0);
                std::cout << "tank health " << tankMonster->getHp()<<std::endl;
                std::cout << "tank shield " << tankMonster->getshield()<<std::endl;
                break;
            }
            }
            if(grid[y-i][x]->getType() == 'G') {
                GhostMonster* ghostMonster = static_cast<GhostMonster*>(grid[y - i][x]);
                std::cout << "ghostMonster health at first " << ghostMonster->getHp()<<std::endl;
                ghostMonster->setHp(ghostMonster->getHp()-hero->getGun()->getDmg());
                std::cout << "ghostMonster health after " << ghostMonster->getHp()<<std::endl;
                break;
            }

            }            break;

        case 'd': //right
           for(int i = 1;i <= hero->getGun()->getRange()&& x+i <15 ;i++){
            std::cout << "bullet at " << x+i<<std::endl;

            if(grid[y][x+i]->getType() == 'T') {
            std::cout << "tank at " << y+i<<std::endl;
            TankMonster* tankMonster = static_cast<TankMonster*>(grid[y][x + i]);
            if(tankMonster->getshield() > hero->getGun()->getDmg()){// if shield more than damage
                    tankMonster->setshield(tankMonster->getshield()-hero->getGun()->getDmg() );
                std::cout << "tank health " << tankMonster->getHp()<<std::endl;
                std::cout << "tank shield " << tankMonster->getshield()<<std::endl;
                break;
            }else{
                std::cout << "tank health at first " << tankMonster->getHp()<<std::endl;
                std::cout << "tank shield at first " << tankMonster->getshield()<<std::endl;
                std::cout <<(hero->getGun()->getDmg()-tankMonster->getshield())<<std::endl;
                tankMonster->setHp(tankMonster->getHp()-(hero->getGun()->getDmg()-tankMonster->getshield()) );
            tankMonster->setshield(0);
                std::cout << "tank health " << tankMonster->getHp()<<std::endl;
                std::cout << "tank shield " << tankMonster->getshield()<<std::endl;
                break;
            }
            }
            if(grid[y][x+i]->getType() == 'G') {
                GhostMonster* ghostMonster = static_cast<GhostMonster*>(grid[y][x + i]);
                std::cout << "ghostMonster health at first " << ghostMonster->getHp()<<std::endl;
                ghostMonster->setHp(ghostMonster->getHp()-hero->getGun()->getDmg());
                std::cout << "ghostMonster health after " << ghostMonster->getHp()<<std::endl;
                break;
            }

            }            break;

        default:
            std::cout << "Invalid direction." << std::endl;
            break;
        }


    }

};



#endif
