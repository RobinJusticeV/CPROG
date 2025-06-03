#ifndef PLAYER_H
#define PLAYER_H

#include "MovingObj.h"
#include <string>

namespace cwing {

    class Player : public MovingObj {
    public:
        // Player(int x, int y, int w, int h, const std::string& imagePath);
        static Player* getInstance(int x, int y, int w, int h, const std::string& imagePath);
        void keyDown(const SDL_Event&) override;
        void shoot();
        void recoil();
        void collisionDetected(const Component& other) override;
        //void startPosition();
        void startPosition(int startX, int startY);
        
        //ändra plats
        ~Player();
        protected:
            Player(int x, int y, int w, int h, const std::string& imagePath);
        
    private:
        // int startX;
        // int startY;
    };

}

#endif
