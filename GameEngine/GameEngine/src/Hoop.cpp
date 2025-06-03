#include "StillObj.h"
#include <string>
#include "Hoop.h"


using namespace cwing;

Hoop *Hoop::getInstance(int x, int y, int w, int h, const std::string& imagePath)
{
    return new Hoop(x,y,w,h, imagePath);
}

Hoop::Hoop(int x, int y, int w, int h, const std::string& imagePath) : StillObj(x, y, w, h, imagePath)
{
    compType = "Hoop";
}
    



