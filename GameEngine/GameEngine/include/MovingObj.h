#ifndef MOVINGOBJ_H
#define MOVINGOBJ_H

#include "Component.h"
#include <SDL2/SDL.h>
#include <string>

namespace cwing {

    class MovingObj : public Component {
public:
    ~MovingObj();

    void draw() const override;
    void move(int speedX, int speedY);
protected:
    MovingObj(int x, int y, int w, int h, const std::string& imagePath);
private:
    SDL_Texture* texture;
};

} 

#endif 
