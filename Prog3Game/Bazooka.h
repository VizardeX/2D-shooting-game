#ifndef BAZOOKA_H
#define BAZOOKA_H
#include "Gun.h"
#include <string>

class Bazooka : public Gun{

public:
    Bazooka();
    Bazooka(std::string name);
    ~Bazooka();

    virtual void useSpecial(Hero& h1 , Object*** map){
            int x = h1.getPosX();
            int y = h1.getPosY();

    if(x==y){
            for(int i = 0;i<15;i++){
                if(map[i][i]->getType() == 'T'||map[y+i][x+i]->getType() == 'G'){
            map[y+i][x+i] = new Object('.');
                }
            }
        }
    if (x + y == 14) {
        for (int i = 0; i < 15; i++) {
            if (map[i][14 - i]->getType() == 'T' || map[i][14 - i]->getType() == 'G') {
                map[i][14 - i] = new Object('.');
            }
        }
    }


    }


};





#endif
