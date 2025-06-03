#ifndef STILLOBJ_H
#define STILLOBJ_H

#include "Component.h"
#include <SDL2/SDL.h>
#include <string>

namespace cwing {

    class StillObj : public Component {
    public:
        StillObj(int x, int y, int w, int h, const std::string& imagePath);
        ~StillObj();

        void draw() const override;

    private:
        SDL_Texture* texture;
    };

}

#endif
