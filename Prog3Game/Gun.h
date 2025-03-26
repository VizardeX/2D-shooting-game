#ifndef GUN_H
#define GUN_H
#include "Object.h"
#include <string>
class Hero;

class Gun : public Object{
private:
    std::string name;
    int bullets;
    int dmg;
    int range;

public:
    std::string getName()const;
    void setName(std::string name);
    int getBullets()const;
    void setBullets(int bullets);
    int getDmg()const;
    void setDmg(int dmg);
    int getRange()const;
    void setRange(int range);
    Gun();
    Gun(std::string name, int bullets, int dmg, int range,char type);
    ~Gun();

    friend std::ostream& operator<<(std::ostream& os, const Gun& gun) {
    os << "Name: " << gun.getName() << std::endl;
    os << "Bullets: " << gun.getBullets() << std::endl;
    os << "Damage: " << gun.getDmg() << std::endl;
    os << "Range: " << gun.getRange() << std::endl;
    return os;
}

virtual void useSpecial(Hero& h1 , Object*** map){};


};



#endif
