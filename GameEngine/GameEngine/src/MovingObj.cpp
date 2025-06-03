#include "Constants.h"
#include <SDL2/SDL_image.h>
#include "MovingObj.h"
#include "System.h"
#include <string>   


namespace cwing {

    MovingObj::MovingObj(int x, int y, int w, int h, const std::string& imagePath) :
        Component(x, y, w, h), texture(nullptr)
    {
        SDL_Surface* surf = IMG_Load((constants::gResPath + imagePath).c_str());
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        SDL_FreeSurface(surf);
    }

    MovingObj::~MovingObj() 
    {
    }  

    void MovingObj::draw() const 
    {
        SDL_RenderCopy(sys.get_ren(), texture, nullptr, &getRect());
    }

    void MovingObj::move(int speedX, int speedY)
    {
        const SDL_Rect &rect = getRect();
        setLocation(rect.x + speedX, rect.y + speedY);
    }

}
