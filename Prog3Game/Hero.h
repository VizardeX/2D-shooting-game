#ifndef HERO_H
#define HERO_H
#include "Character.h"
#include "Gun.h"
#include "Ammo.h"
#include "Potion.h"
#include "Monster.h"
#include "Monster.h"

class Hero : public Character{

private:
    Gun* gun;

public:
    Gun* getGun()const;
    void setGun(Gun* gun);
    Hero();
    Hero(int hp, int x, int y, Gun* gun,char type);
    ~Hero();

    friend std::ostream& operator<<(std::ostream& os, const Hero& hero) {
    os << "Hero Information -" << std::endl;
    os << "HP: " << hero.getHp() << std::endl;
    os << "Position: (" << hero.getPosX() << ", " << hero.getPosY() << ")" << std::endl;
    os << "Gun Information -" << std::endl;
    os << *hero.getGun()<< std::endl;
     return os;
    }
friend Hero operator+(const Hero& hero, const Ammo& ammo);
friend Hero operator+(const Hero& hero, const Potion& potion);
friend Hero operator-(const Hero& hero, Monster& monster);
virtual void useSpecial(){};
//for deep copies since without it it gives errors
    Hero(const Hero& other) : Character(other) {
        if (other.gun) {
            gun = new Gun(*other.gun);
        }
    }

        Hero& operator=(const Hero& other) {
        if (this != &other) {
            delete gun;
            if (other.gun) {
                gun = new Gun(*other.gun);
            }
            this->setHp(other.getHp()) ;
        }
        return *this;
    }




};



#endif // HERO_H
