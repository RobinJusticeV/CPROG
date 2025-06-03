//spelklass 
#ifndef BASKETBALL_H
#define BASKETBALL_H

#include "Projectile.h"
#include "Player.h"
#include <iostream>

using namespace cwing;

class Basketball : public Projectile {
public:
    static Basketball* getInstance(int x, int y, int w, int h, const std::string& imagePath, Player* p);
    void collisionDetected(const Component& other) override;

    ~Basketball(){
        std::cout << "*** Basketball::~Basketball() \n";
    }
    void update(){
        Projectile::update();
        if (getRect().y < 0){
            //std::cout << "Remove!!!**111!! \n";
            is_alive = false;
        }
    }
protected:
    Basketball(int x, int y, int w, int h, const std::string& imagePath, Player* p);

private:
    
    Player* myPlayer;

    //flaggor för kollision för basketbollen
    bool givenPoint;
    bool takenPoint;
};

#endif
