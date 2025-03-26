#ifndef GHOSTMONSTER_H_INCLUDED
#define GHOSTMONSTER_H_INCLUDED

class GhostMonster : public Monster{
private:
bool isVisble;
public:
    GhostMonster();
    GhostMonster(std::string name,int hp,int x, int y,bool isVisble);
    ~GhostMonster();
    bool getisVisble();
    void setisVisble(bool isVisble);

};


#endif // GHOSTMONSTER_H_INCLUDED
