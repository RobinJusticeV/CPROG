#include "Constants.h"
#include <SDL2/SDL_image.h>
#include "StillObj.h"
#include "System.h"
#include <string>



namespace cwing {

    StillObj::StillObj(int x, int y, int w, int h, const std::string& imagePath)
        : Component(x, y, w, h), texture(nullptr) 
    {
        SDL_Surface* surf = IMG_Load((constants::gResPath + imagePath).c_str());
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        SDL_FreeSurface(surf);
    }

    StillObj::~StillObj() {
        SDL_DestroyTexture(texture);
    }

    void StillObj::draw() const {
        SDL_RenderCopy(sys.get_ren(), texture, nullptr, &getRect());
    }

}
