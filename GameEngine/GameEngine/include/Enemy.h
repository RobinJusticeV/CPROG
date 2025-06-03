#ifndef ENEMY_H
#define ENEMY_H

#include "MovingObj.h"
#include <string>

namespace cwing {

    class Enemy : public MovingObj {
    public:
        static Enemy* getInstance(int x, int y, int w, int h, const std::string& imagePath);
        void update() override;
    protected:
    Enemy(int x, int y, int w, int h, const std::string& imagePath);
    private:
        bool movingRight; //script för att röra sig
    };

}

#endif
