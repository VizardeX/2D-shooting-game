#ifndef TANKMONSTER_H_INCLUDED
#define TANKMONSTER_H_INCLUDED

class TankMonster : public Monster{
private:
int  shield;
public:
    TankMonster();
    TankMonster(std::string name,int hp,int x, int y,int  shield);
    ~TankMonster();
    int getshield();
    void setshield(int shield);


};



#endif // TANKMONSTER_H_INCLUDED
