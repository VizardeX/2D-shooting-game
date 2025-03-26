#ifndef OBJECT_H
#define OBJECT_H

class Object{

private:
    char type;

public:
    char getType()const;
    void setType(char type);
    Object();
    Object(char type);
    ~Object();
    friend std::ostream& operator<<(std::ostream& os, const Object& obj) {
    os <<"Object is "<< obj.type<<std::endl;
    return os;
}


};


#endif
