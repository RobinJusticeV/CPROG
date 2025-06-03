#include "Component.h"
#include <iostream>

namespace cwing 
{

	//tom eftersom den endast konstruerar variabler och rect
	Component::Component(int x, int y, int w, int h) :rect{ x,y,w,h }
	{
	}


	Component::~Component()
	{
	}
	
	void Component::setLocation(int x, int y){
		rect.x = x;
		rect.y = y;
	}

    bool Component::checkCollision(const Component& other) {
        // std::cout << "   bool Component::checkCollision(const Component& other) const  \n";

        SDL_Rect a = getRect();
        SDL_Rect b = other.getRect();

        int leftA = a.x;
        int rightA = a.x + a.w;
        int topA = a.y;
        int bottomA = a.y + a.h;

        int leftB = b.x;
        int rightB = b.x + b.w;
        int topB = b.y;
        int bottomB = b.y + b.h;

        if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB) {
            return false;
        }
        collisionDetected(other);

        return true;
    }

    void Component::collisionDetected(const Component &other)
    {

    }


}