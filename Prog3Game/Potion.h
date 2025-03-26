#ifndef POTION_H
#define POTION_H

class Potion : public Item {
private:
    int healamount;
public:
    Potion();
    Potion(int x,int y,int healamount) ;
    ~Potion();
    int getHealAmount()const;
    void setHealAmount(int bullets);

};


#endif // POTION_H_INCLUDED
