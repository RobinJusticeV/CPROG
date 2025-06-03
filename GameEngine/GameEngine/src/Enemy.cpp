#include "Enemy.h"

namespace cwing {

    
    //fabriksfunktion
    Enemy *Enemy::getInstance(int x, int y, int w, int h, const std::string& imagePath)
    {
        return new Enemy(x,y,w,h, imagePath);
    }

    Enemy::Enemy(int x, int y, int w, int h, const std::string& imagePath) :
        MovingObj(x, y, w, h, imagePath), movingRight(true)
    {
        compType = "Enemy";
    }

    void Enemy::update()
    {
        if (movingRight) {
            move(3, 0);
            if (getRect().x + getRect().w >= 600) { 
                movingRight = false;
            }
        } else {
            move(-3, 0);
            if (getRect().x <= 0) {
                movingRight = true;
            }
        }
    }
}
