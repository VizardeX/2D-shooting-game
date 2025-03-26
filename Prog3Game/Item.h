#ifndef ITEM_H
#define ITEM_H
class Item : public Object{
private:
    std::pair <int,int> position;
public:
    Item();
    Item(int x,int y,char type) ;
    ~Item();
    std::pair <int,int> getPos();
    void setPos(int x,int y);

};


#endif // ITEM_H_INCLUDED
