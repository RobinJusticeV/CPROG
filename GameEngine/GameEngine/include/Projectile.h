#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "MovingObj.h"
#include <string>

namespace cwing{

    class Projectile : public MovingObj {

    public: 
        void update() override;
    protected:
        Projectile(int x, int y, int w, int h, const std::string& imagePath);

    };
    



}

#endif