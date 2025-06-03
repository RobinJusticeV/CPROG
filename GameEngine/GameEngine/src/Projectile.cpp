#include "Projectile.h"
#include "System.h"
#include "constants.h"
#include "Session.h"

namespace cwing {

    Projectile::Projectile(int x, int y, int w, int h, const std::string& imagePath) :
        MovingObj(x, y, w, h, imagePath)
    {
    }

    void Projectile::update(){
        move(0, -3.5); 
        
    }

}
