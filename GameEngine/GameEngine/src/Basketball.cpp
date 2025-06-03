//spelklass
#include "Basketball.h"
#include "Score.h"
#include "Session.h"


using namespace cwing;

Basketball* Basketball::getInstance(int x, int y, int w, int h, const std::string& imagePath, Player* p) {
    return new Basketball (x, y, w, h, imagePath, p);
}


    Basketball::Basketball(int x, int y, int w, int h, const std::string& imagePath, Player* p) :
        Projectile(x, y, w, h, imagePath), myPlayer(p) {
            compType = "Basketball";
            std::cout << "*** Basketball::Basketball(int x, int y, int w, int h, const std::string& imagePath, Player* p) : \n";

    }

    // Basketball::~Basketball(){
    //     std::cout << "*** Basketball::~Basketball() \n";
    // }

void Basketball::collisionDetected(const Component& other) {
    // Om kollisionen är med en Hoop, lägg till poäng
    if (other.compType == "Hoop") { 


        if(!givenPoint){

            std::cout << "Collision detected with Hoop!" << Score::getInstance()->getScore() <<std::endl;
            Score::getInstance()->addPoints(2);
            givenPoint = true;
            is_alive = false;
        }
    // Om kollisionen är med en Enemy, tabort poäng
    } else if (other.compType == "Enemy") { 

        if (!takenPoint){

        
            std::cout << "Collision detected with Enemy!" << Score::getInstance()->getScore() << std::endl;
            Score::getInstance()->addPoints(-2); 
            takenPoint = true;

            is_alive = false;
        }
    }

    
}
