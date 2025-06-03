#include "Player.h"
#include "System.h"
#include "constants.h"
#include "Basketball.h"
#include "Score.h"
#include "Session.h"
#include <cstdlib>

namespace cwing {

   
    //fabriksfunktion
    Player *Player::getInstance(int x, int y, int w, int h, const std::string& imagePath)
    {
        return new Player(x,y,w,h, imagePath);
    }
    
    Player::Player(int x, int y, int w, int h, const std::string& imagePath) :
        MovingObj(x, y, w, h, imagePath)
    {
        std::cout << "*** Player::Player(int x, int y, int w, int h, const std::string& imagePath) :\n";
        compType = "Player";        
    }

    Player::~Player(){
        std::cout << "*** Player::~Player() \n";
    }

    void Player::keyDown(const SDL_Event &event)
    {
        //Kanske    borde byta till switch

        //Gå med "w,a,s,d"
        if(event.key.keysym.sym == SDLK_d){
            move(8,0);
        }
        else if(event.key.keysym.sym == SDLK_a){
            move(-8,0);
        }
        else if (event.key.keysym.sym == SDLK_w)
        {
            move(0, -8);
        }
        else if (event.key.keysym.sym == SDLK_s)
        {
            move(0, 8);
        }
          
        else if (event.key.keysym.sym == SDLK_SPACE)
        {
            shoot();
        }
        
    }


    void Player::shoot() {

        int projWidth = 20;
        int projHeight = 30;
        int projX = getRect().x + (getRect().w / 2) - (projWidth / 2);
        int projY = getRect().y - projHeight;

        
        Basketball* basketball = Basketball::getInstance(projX, projY, projWidth, projHeight, "images/basket.png", this);
        // Session::getInstance().add(basketball);
        cwing::ses.add(basketball);

        Player::recoil();
    
    }   

    void Player::recoil() { 
        int minX = -20; 
        int maxX = 20; 
        int numX = minX + rand() % (maxX - minX + 1); 
        int minY = -7; int maxY = 8; int numY = minY + rand() % (maxY - minY + 1); 
        Player::move(numX, numY); 
    }

    void Player::collisionDetected(const Component& other) { 

    // Om kollisionen är med en Enemy, reseta till poäng
    if (other.compType == "Enemy") { 
        std::cout << "Collision detected with Enemy!" << Score::getInstance()->getScore() <<std::endl;
        Score::getInstance()->reset();
        
        //Player::startPosition(200, 300); // funkar ej, får felmeddelande, testa conversion med constcast?

        const_cast<Player*>(this)->startPosition(200, 300);
        
    }
    // else if (other.compType == "Enemy") { 
    //     std::cout << "Collision detected with Enemy!" << Score::getInstance()->getScore() << std::endl;
    //     Score::getInstance()->addPoints(-10); 
    // }

    
}

void Player::startPosition(int startX, int startY)
{
    setLocation(startX,startY);
}

}
