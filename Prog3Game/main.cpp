#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Object.h"
#include "Character.h"
#include "Gun.h"
#include "Pistol.h"
#include "Bazooka.h"
#include "Rifle.h"
#include "Hero.h"
#include "MedicHero.h"
#include "DemolitionHero.h"
#include "Monster.h"
#include "GhostMonster.h"
#include "TankMonster.h"
#include "Item.h"
#include "Ammo.h"
#include "Potion.h"
#include "Game.h"


using namespace std;

Object::Object(){}
Object::Object(char type){
    this->type = type;

}
char Object::getType()const{
    return this->type;
}

void Object::setType(char type){
    this->type = type;
}

Object::~Object(){}

int Character::getHp()const{
    return this->hp;
}

void Character::setHp(int hp){
    this->hp = hp;
}

int Character::getPosX()const{
    return this->position.first;
}

int Character::getPosY()const{
    return this->position.second;
}


void Character::setPos(int x,int y){
    this->position = {x,y};
}



Character::Character(){}

Character::Character(int hp, int x, int y,char type):Object(type){
    this->hp = hp;
    this->position = {x,y};
}

Character::~Character(){}

Gun* Hero::getGun()const{
    return this->gun;
}

void Hero::setGun(Gun* gun){
    this->gun = gun;
}

Hero::Hero(){}

Hero::Hero(int hp,int x,int y, Gun* gun,char type) : Character(hp, x, y,type){
    this->gun = gun;
}

Hero::~Hero(){
    delete gun;
}

MedicHero::MedicHero(){}

MedicHero::MedicHero(int hp,int x,int y, Gun* gun,int healamount):Hero( hp, x, y, gun,'M'){
this->healamount=healamount;
}

MedicHero::~MedicHero(){}

int MedicHero::gethealamount(){
return this->healamount;
}

void  MedicHero::sethealamount(int healamount){
 this->healamount = healamount;
}

DemolitionHero::DemolitionHero(){}

DemolitionHero::DemolitionHero(int hp,int x,int y, Gun* gun,Gun* gun2):Hero( hp, x, y, gun,'D'){
this->gun2 = gun2;
}

DemolitionHero::~DemolitionHero(){
delete gun2;
}

Gun* DemolitionHero::getGun2()const{
    return this->gun2;
}

void DemolitionHero::setGun2(Gun* gun){
    this->gun2= gun;
}

Monster::Monster(){}

Monster::Monster(string name,int hp,int x,int y,char type) : Character(hp, x, y,type){
    this->name = name;
}

Monster::~Monster(){
}

string Monster::getName(){
    return name;
}

void Monster::setName(string name){
    this->name = name;
}

GhostMonster::GhostMonster(){}

GhostMonster::GhostMonster(string name,int hp,int x,int y,bool isVisble) : Monster( name, hp, x, y, 'G'){
    this->isVisble = isVisble;
}

GhostMonster::~GhostMonster(){
}

bool GhostMonster::getisVisble(){
 return this->isVisble;
}

void GhostMonster::setisVisble(bool isVisble){
    this->isVisble = isVisble;
}

TankMonster::TankMonster(){}

TankMonster::TankMonster(string name,int hp,int x,int y,int  shield) : Monster( name, hp, x, y, 'T'){
    this->shield = shield;
}

TankMonster::~TankMonster(){
}

int TankMonster::getshield(){
 return this->shield;
}

void TankMonster::setshield(int shield){
    this->shield = shield;
}

string Gun::getName()const{
    return name;
}

void Gun::setName(string name){
    this->name = name;
}

int Gun::getBullets()const{
    return bullets;
}

void Gun::setBullets(int bullets){
    this->bullets = bullets;
}

int Gun::getDmg()const{
    return dmg;
}

void Gun::setDmg(int dmg){
    this->dmg = dmg;
}

int Gun::getRange()const{
    return range;
}

void Gun::setRange(int range){
    this->range = range;
}

Gun::Gun(){}

Gun::Gun(string name, int bullets, int dmg, int range,char type):Object(type){
    this->name = name;
    this->bullets = bullets;
    this->dmg = dmg;
    this->range = range;
}

Gun::~Gun(){}

Pistol::Pistol(){}

Pistol::Pistol(string name) : Gun(name, 16, 30, 2,'p'){};

Pistol::~Pistol(){}

Bazooka::Bazooka(){}

Bazooka::Bazooka(string name) : Gun(name, 4, 150, 8,'B'){};

Bazooka::~Bazooka(){}

Rifle::Rifle(){}

Rifle::Rifle(string name) : Gun(name, 30, 20, 4,'R'){};

Rifle::~Rifle(){}

Item::Item(){};

Item::Item(int x,int y,char type):Object(type){
    this->position = {x,y};
} ;

Item::~Item(){};


pair<int,int> Item::getPos(){
    return this->position;
}

void Item::setPos(int x,int y){
    this->position = {x,y};
}

Ammo::Ammo(){};

Ammo::Ammo(int x,int y,int BulletAmount):Item( x, y, 'A'){
    this->BulletAmount = BulletAmount;
} ;

Ammo::~Ammo(){};

int Ammo::getBulletAmount() const{
    return this->BulletAmount;
}

void Ammo::setBulletAmount(int BulletAmount){
    this->BulletAmount = BulletAmount;
}

Potion::Potion(){};

Potion::Potion(int x,int y,int healamount):Item( x, y, 'P'){
    this->healamount = healamount;
} ;

Potion::~Potion(){};

int Potion::getHealAmount()const{
    return this->healamount;
}

void Potion::setHealAmount(int healamount){
    this->healamount = healamount;
}

Game::Game(){}


Game::~Game(){
for(int i =0;i<rows;i++){
   delete[] grid[i];
    }
    delete[] grid;
    delete hero;
}

int Game::getRows(){
return this->rows;
}
void Game::setRows(int rows){
this->rows = rows;
}

int Game::getColumns(){
return this->columns;
}

void Game::setColumns(int columns){
this->columns = columns;
}

Game::Game(int rows,int columns){
this->rows = rows;
this->columns = columns;
hero = NULL;
    grid = new Object**[rows]; // Allocate an array of pointers to pointers

    for (int i = 0; i < rows; i++) {
        grid[i] = new Object*[columns]; // Allocate an array of pointers for each row
        for (int j = 0; j < columns; j++) {
            grid[i][j] = new Object(); // Allocate an Object for each element
        }
    }

}


void Game::GenerateMap(){
srand(time(0));
int x = rand()%(14+1);
int y = rand()%(14+1);

for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
        grid[i][j] = new Object('.');
    }
}

    int pcount=0;
    while(pcount<5){
    if((x!=0 || y!=0) && grid[x][y]->getType()== '.'){
    //Potion* p = new Potion(x,y,rand()%(50-10+1)+10);
    grid[x][y] =  new Potion(x,y,rand()%(50-10+1)+10);
    pcount++;
    }
    x = rand()%(14+1);
    y = rand()%(14+1);
    }

    int acount=0;
    while(acount<10){
    if((x!=0 || y!=0) &&  grid[x][y]->getType()== '.' ){
    //Ammo* A = new Ammo(x,y,rand()%(20-5+1)+5) ;
    grid[x][y] =  new Ammo(x,y,rand()%(20-5+1)+5) ;
    acount++;
    }
    x = rand()%(14+1);
    y = rand()%(14+1);
    }

    int gcount=0;
    while(gcount<5){
    if((x!=0 || y!=0) &&  grid[x][y]->getType()== '.' ){
     //   GhostMonster* G = new GhostMonster("Ghost "+gcount+1,(rand()%(15-6+1)+6)*10,x,y,true);
    grid[x][y] = new GhostMonster("Ghost "+gcount+1,(rand()%(15-6+1)+6)*10,x,y,true);
    gcount++;
    }
    x = rand()%(14+1);
    y = rand()%(14+1);
    }

    int tcount=0;
    while(tcount<5){
    if((x!=0 || y!=0) &&  grid[x][y]->getType()== '.' ){
          //  TankMonster* T = new TankMonster("Tank "+tcount+1,(rand()%(15-6+1)+6)*10 ,x,y,0);
    grid[x][y] =  new TankMonster("Tank "+tcount+1,(rand()%(15-6+1)+6)*10 ,x,y,0);
    tcount++;
    }
    x = rand()%(14+1);
    y = rand()%(14+1);
    }

    }





void Game::showMap(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
                cout<<" "<< grid[i][j]->getType()<< " " ;
        }
        cout<<endl;
    }

}



int Game::round = 0;
void Game::move(Hero& h1 , char direction){
              //  TankMonster* tankMonster = static_cast<TankMonster*>(&*map[y + i][x]);

    switch(direction){
    case 'D':
    case 'd':
        if(h1.getPosX() == this->rows - 1){
            cout<<"Cannot move right"<<endl;
        }
        else{
            if(grid[h1.getPosY()][h1.getPosX() + 1]->getType() == 'A'){
                    h1 = h1 + static_cast<Ammo&>(*(grid[h1.getPosY()][h1.getPosX() + 1]));
                    h1.setPos(h1.getPosX() + 1, h1.getPosY());
                    grid[h1.getPosY()][h1.getPosX()] = &h1;
                    grid[h1.getPosY()][h1.getPosX() - 1] = new Object('.');
                    cout<<"Extra Ammo!"<<endl;
            }
            else if(grid[h1.getPosY()][h1.getPosX() + 1]->getType() == 'P'){
                    h1 = h1 + static_cast<Potion&>(*(grid[h1.getPosY()][h1.getPosX() + 1]));
                    h1.setPos(h1.getPosX() + 1, h1.getPosY());
                    grid[h1.getPosY()][h1.getPosX()] = &h1;
                    grid[h1.getPosY()][h1.getPosX() - 1] = new Object('.');
                    cout<<"+HP!"<<endl;
            }

            else if(grid[h1.getPosY()][h1.getPosX() + 1]->getType() == 'G' || grid[h1.getPosY()][h1.getPosX() + 1]->getType() == 'T'){
                    h1 = h1 - static_cast<Monster&>(*(grid[h1.getPosY()][h1.getPosX() + 1]));
                    cout<<"Watch out! A Monster!"<<endl;
            }
            else{
                    h1.setPos(h1.getPosX() + 1, h1.getPosY());
                    grid[h1.getPosY()][h1.getPosX()] = &h1;
                    grid[h1.getPosY()][h1.getPosX() - 1] = new Object('.');
            }
        }
        break;

    case 'A':
    case 'a':
        if(h1.getPosX() == 0){
            cout<<"Cannot move left"<<endl;
        }
        else{
            if(grid[h1.getPosY()][h1.getPosX() - 1]->getType() == 'A'){
                    h1 = h1 + static_cast<Ammo&>(*(grid[h1.getPosY()][h1.getPosX() - 1]));
                    h1.setPos(h1.getPosX() - 1, h1.getPosY());
                    grid[h1.getPosY()][h1.getPosX()] = &h1;
                    grid[h1.getPosY()][h1.getPosX() + 1] = new Object('.');
                    cout<<"Extra Ammo!"<<endl;
            }
            else if(grid[h1.getPosY()][h1.getPosX() - 1]->getType() == 'P'){
                    h1 = h1 + static_cast<Potion&>(*(grid[h1.getPosY()][h1.getPosX() - 1]));
                    h1.setPos(h1.getPosX() - 1, h1.getPosY());
                    grid[h1.getPosY()][h1.getPosX()] = &h1;
                    grid[h1.getPosY()][h1.getPosX() + 1] = new Object('.');
                    cout<<"+HP!"<<endl;
            }
            else if(grid[h1.getPosY()][h1.getPosX() - 1]->getType() == 'G' || grid[h1.getPosY()][h1.getPosX() - 1]->getType() == 'T'){
                    h1 = h1 - static_cast<Monster&>(*(grid[h1.getPosY()][h1.getPosX() - 1]));
                    cout<<"Watch out! A Monster!"<<endl;
            }
            else{
                    h1.setPos(h1.getPosX() - 1, h1.getPosY());
                    grid[h1.getPosY()][h1.getPosX()] = &h1;
                    grid[h1.getPosY()][h1.getPosX() + 1] = new Object('.');
            }
        }
        break;

    case 'W':
    case 'w':
        if(h1.getPosY() == 0){
            cout<<"Cannot move up"<<endl;
        }
        else{
            if(grid[h1.getPosY() - 1][h1.getPosX()]->getType() == 'A'){
                    h1 = h1 + static_cast<Ammo&>(*(grid[h1.getPosY() - 1][h1.getPosX()]));
                    h1.setPos(h1.getPosX(), h1.getPosY() - 1);
                    grid[h1.getPosY()][h1.getPosX()] = &h1;
                    grid[h1.getPosY() + 1][h1.getPosX()] = new Object('.');
                    cout<<"Extra Ammo!"<<endl;
            }
            else if(grid[h1.getPosY() - 1][h1.getPosX()]->getType() == 'P'){
                    h1 = h1 + static_cast<Potion&>(*(grid[h1.getPosY() - 1][h1.getPosX()]));
                    h1.setPos(h1.getPosX(), h1.getPosY() - 1);
                    grid[h1.getPosY()][h1.getPosX()] = &h1;
                    grid[h1.getPosY() + 1][h1.getPosX()] = new Object('.');
                    cout<<"+HP!"<<endl;
            }
            else if(grid[h1.getPosY() - 1][h1.getPosX()]->getType() == 'G' || grid[h1.getPosY() - 1][h1.getPosX()]->getType() == 'T'){
                    h1 = h1 - static_cast<Monster&>(*(grid[h1.getPosY() - 1][h1.getPosX()]));
                    cout<<"Watch out! A Monster!"<<endl;
            }
            else{
                    h1.setPos(h1.getPosX(), h1.getPosY() - 1);
                    grid[h1.getPosY()][h1.getPosX()] = &h1;
                    grid[h1.getPosY() + 1][h1.getPosX()] = new Object('.');
            }
        }
        break;

    case 'S':
    case 's':
        if(h1.getPosY() == this-> columns - 1){
            cout<<"Cannot move down"<<endl;
        }
        else{
            if(grid[h1.getPosY() + 1][h1.getPosX()]->getType() == 'A'){
                    h1 = h1 + static_cast<Ammo&>(*(grid[h1.getPosY() + 1][h1.getPosX()]));
                    h1.setPos(h1.getPosX(), h1.getPosY() + 1);
                    grid[h1.getPosY()][h1.getPosX()] = &h1;
                    grid[h1.getPosY() - 1][h1.getPosX()] = new Object('.');
                    cout<<"Extra Ammo!"<<endl;
            }
            else if(grid[h1.getPosY() + 1][h1.getPosX()]->getType() == 'P'){
                    h1 = h1 + static_cast<Potion&>(*(grid[h1.getPosY() + 1][h1.getPosX()]));
                    h1.setPos(h1.getPosX(), h1.getPosY() + 1);
                    grid[h1.getPosY()][h1.getPosX()] = &h1;
                    grid[h1.getPosY() - 1][h1.getPosX()] = new Object('.');
                    cout<<"+HP!"<<endl;
            }
            else if(grid[h1.getPosY() + 1][h1.getPosX()]->getType() == 'G' || grid[h1.getPosY() + 1][h1.getPosX()]->getType() == 'T'){
                    h1 = h1 - static_cast<Monster&>(*(grid[h1.getPosY() + 1][h1.getPosX()]));
                    cout<<"Watch out! A Monster!"<<endl;
            }
            else{
                    h1.setPos(h1.getPosX(), h1.getPosY() + 1);
                    grid[h1.getPosY()][h1.getPosX()] = &h1;
                    grid[h1.getPosY() - 1][h1.getPosX()] = new Object('.');
            }
        }
        break;

    default:
        cout<<"Invalid direction"<<endl;

}

}




void Game::useGunSpecial(){
    int x = this->hero->getPosX();
    int y = this->hero->getPosY();
    if(hero->getGun()->getType() == 'p'){
        if(hero->getGun()->getBullets() < 4){
            cout<<"Cannot use gun special. Needs at least 4 bullets"<<endl;
        }
        else{
            hero->getGun()->useSpecial(*hero, grid);
        }
    }

    else if(hero->getGun()->getType() == 'B'){
        if(x == y || (x + y == rows - 1)){
            hero->getGun()->useSpecial(*hero, grid);

        }
        else{
        cout<<"Cannot use gun special. Needs to be at either of the diagonals"<<endl;
        }
    }

    else if(hero->getGun()->getType() == 'R'){
        if(hero->getGun()->getBullets() < 3){
            cout<<"Cannot use gun special. Needs at least 3 bullets"<<endl;
        }
        else{
            hero->getGun()->useSpecial(*hero, grid);
        }
    }
}


int Game::checkGameOver(){
    bool isWin = true;
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){
            if(grid[i][j]->getType() == 'G' || grid[i][j]->getType() == 'T'){
                isWin = false;
                break;
            }
            if(!isWin){
                break;
            }
        }
    }
    if(this->hero->getHp() <= 0){
        return 0;
    }
    if(isWin){
        return 1;
    }
    else{
        return -1;
    }
}


void Game::updateMap(){
    //deletes dead monsters
    for(int i = 0; i < columns; i++){
        for(int j= 0; j < rows; j++){
            if(grid[i][j]->getType() == 'G'){
                GhostMonster* m = static_cast<GhostMonster*>(grid[i][j]);
                if(m->getHp() <= 0){
                    grid[i][j] = new Object('.');
                }
            }
            else if( grid[i][j]->getType() == 'T'){
                TankMonster* m = static_cast<TankMonster*>(grid[i][j]);
                if(m->getHp() <= 0){
                    grid[i][j] = new Object('.');
                }
            }
        }
    }

    //makes ghosts invisible
    if(round%3 == 0){
        for(int i = 0; i < columns; i++){
        for(int j= 0; j < rows; j++){
            if(grid[i][j]->getType() == 'G'){
                GhostMonster* gm = static_cast<GhostMonster*>(grid[i][j]);
                gm->setisVisble(!(gm->getisVisble()));
            }
        }
    }
    }

    //spawns 2 new monsters
    if(round%20 == 0){
    srand(time(0));
    int x = rand()%(14+1);
    int y = rand()%(14+1);

       //spawn a ghost
    bool gSpawn = false;
    while(!gSpawn){
       if(grid[x][y]->getType()== '.' ){
          //GhostMonster* ghost = new GhostMonster("Ghost ",(rand()%(15-6+1)+6)*10,x,y,true);
          grid[x][y] = new GhostMonster("Ghost ",(rand()%(15-6+1)+6)*10,x,y,true);
          gSpawn = true;
       }
       else{
          x = rand()%(14+1);
          y = rand()%(14+1);
       }
    }

       //spawn a tank
    bool tSpawn = false;
    while(!tSpawn){
       if(grid[x][y]->getType()== '.' ){
          //TankMonster* tank = new TankMonster("Tank ",(rand()%(15-6+1)+6)*10,x,y,true);
          grid[x][y] = new TankMonster("Tank ",(rand()%(15-6+1)+6)*10,x,y,true);
          tSpawn = true;
       }
       else{
          x = rand()%(14+1);
          y = rand()%(14+1);
       }
    }

    }

    // re-prints all all the elements of the map
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){
                if(grid[i][j]->getType() == 'G'){
                    GhostMonster* g = static_cast<GhostMonster*>(grid[i][j]);
                    if(!g->getisVisble()){
                        cout<<" . ";
                    }
                    else{
                        cout<<" "<<grid[i][j]->getType()<<" ";
                    }
                }
                else{
                    cout<<" "<<grid[i][j]->getType()<<" ";
                }
        }
        cout<<endl;
    }


}




void Game::startGame(){
    int hType;
    int gType;
    int g2Type;
    while(hType!=1 && hType!=2){
    cout<<  "Please Choose 1 for Medic Hero or 2 for Demolisher"<< endl;
    cin>> hType;
    }
    while(gType!=1 && gType!=2 && gType!=3){
    cout<<  "Please Choose your 1st gun 1 for a Pistol, 2 for a Bazooka or 3 for a Rifle"<< endl;
    cin>> gType;
    }
    if(hType == 2){
        while(g2Type!=1 && g2Type!=2 && g2Type!=3){
        cout<<  "Please Choose your 2nd gun 1 for a Pistol, 2 for a Bazooka or 3 for a Rifle"<< endl;
        cin>> g2Type;
        }
    }
    GenerateMap();
     Gun* gun;
       if(gType == 1){
        gun = new Pistol("Pistol");
       }
       if(gType == 2){
       gun = new Bazooka("Bazooka");
       }
       if(gType == 3){
       gun = new Rifle("Rifle");
       }

    if(hType == 1){
     hero = new MedicHero(100, 0, 0, gun, 100);
    }

    if(hType == 2){
    Gun* gun2;
       if(g2Type == 1){
       gun2 = new Pistol("Pistol");
       }
       if(g2Type == 2){
       gun2 = new Bazooka("Bazooka");
       }
       if(g2Type == 3){
       gun2 = new Rifle("Rifle");
       }
    hero = new DemolitionHero(100, 0, 0, gun, gun2);
       }
       grid[0][0] = hero;
        system("cls");
       showMap();
    }
    //NNNNNNNNNNNNNEEEEEEEEEEEEEEEEEEEEEEEEWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
  Hero operator+(const Hero& hero, const Ammo& ammo){
    Hero newHero = hero;
    Gun* newGun = new Gun(*(hero.getGun()));
    newGun->setBullets(newGun->getBullets() + ammo.getBulletAmount());
    newHero.setGun(newGun);
    return newHero;
}

Hero operator+(const Hero& hero, const Potion& potion){
    Hero newHero = hero;
    newHero.setHp(newHero.getHp()+potion.getHealAmount());
    return newHero;
}

Hero operator-(const Hero& hero, Monster& monster){
    Hero newHero = hero;
        newHero.setHp(newHero.getHp() - 10);
        monster.setHp(monster.getHp() - 20);
        return newHero;
    }

Hero* Game::getHero(){
return this->hero;
}

int Game::getRound(){
    return round;
}

void Game::addRound(){
    round++;
}

int main()
{
   Game game(15, 15);
   game.startGame();
   cout<<endl;
   char act;
   int isDone = -1;
   while(isDone == -1){
        cout<<"Controls:"<<endl;
        cout<<"W: Move up, S: Move down, D: Move right, A: Move left"<<endl;
        cout<<"X: Attack"<<endl;
        cout<<"E: use the Hero's special skill"<<endl;
        cout<<"Q: use the Gun's special skill"<<endl;
        cout<<"Round: "<<game.getRound()<<endl;
        cout<<*(game.getHero())<<endl;
        cout<<"choose your action"<<endl;
        cin>>act;

        if(act == 'A' || act == 'a' || act == 'D' || act == 'd' || act == 'W' || act == 'w' || act == 'S' || act == 's'){
            system("cls");
            game.move(*(game.getHero()), act);
        }
        else if(act == 'X' | act == 'x'){
            cout<<"Choose the direction of the attack (w, a, s, d)"<<endl;
            cin>>act;
            system("cls");
            game.FireGun(act);
        }
        else if(act == 'e' || act == 'E'){
                system("cls");
            game.getHero()->useSpecial();
        }
        else if(act == 'q' || act == 'Q'){
            system("cls");
            game.useGunSpecial();
        } else{
        system("cls");
        cout<<"invalid action"<<endl;
        }
        game.addRound();
        cout<<endl;
        game.updateMap();
        isDone = game.checkGameOver();
   }
   if(isDone == 0){
    cout<<"YOU DIED"<<endl;
   }

   else{
    cout<<"YOU ARE VICTORIOUS"<<endl;
   }

    return 0;
}
