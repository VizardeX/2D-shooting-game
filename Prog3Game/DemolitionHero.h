#ifndef DEMOLITIONHERO_H_INCLUDED
#define DEMOLITIONHERO_H_INCLUDED

class DemolitionHero : public Hero{
private:
    Gun* gun2;
public:
    DemolitionHero();
    DemolitionHero(int hp,int x,int y, Gun* gun,Gun* gun2);
    ~DemolitionHero();
    Gun* getGun2()const;
    void setGun2(Gun* gun);

    friend std::ostream& operator<<(std::ostream& os, const DemolitionHero& hero) {
    os << "Hero Information -" << std::endl;
    os << "HP: " << hero.getHp() << std::endl;
    os << "Position: (" << hero.getPosX() << ", " << hero.getPosY() << ")" << std::endl;
    os << "Gun Information -" << std::endl;
    os << *hero.getGun()<< std::endl;
    os << "2nd Gun Information -" << std::endl;
    os << *hero.getGun2()<< std::endl;
     return os;
}

    virtual void useSpecial(){
        Gun* temp = this->getGun();
        this->setGun(getGun2());
        this->setGun2(temp);
    }
};



#endif // DEMOLITIONHERO_H_INCLUDED
