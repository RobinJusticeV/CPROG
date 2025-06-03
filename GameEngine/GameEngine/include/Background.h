#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "StillObj.h"
#include <string>

namespace cwing{


    class Background : public StillObj {
        public:
        static Background* getInstance(int x, int y, int w, int h, const std::string& imagePath);

        protected:
        Background(int x, int y, int w, int h, const std::string& imagePath);
    };
}



#endif