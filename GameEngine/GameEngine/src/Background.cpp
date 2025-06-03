#include "Background.h"
#include "System.h"
#include "Constants.h"
//spelklass

namespace cwing{
    Background *Background::getInstance(int x, int y, int w, int h, const std::string& imagePath)
    {
        return new Background(x,y,w,h, imagePath);
    }

    Background::Background(int x, int y, int w, int h, const std::string& imagePath) 
    : StillObj(x, y, w, h, imagePath)

    {
    }

}