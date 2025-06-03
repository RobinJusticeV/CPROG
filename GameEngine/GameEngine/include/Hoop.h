#ifndef HOOP_H
#define HOOP_H

#include "StillObj.h"
#include <string>

//spelklass
using namespace cwing;

    class Hoop : public cwing::StillObj{

    public:
        static Hoop* getInstance(int x, int y, int w, int h, const std::string& imagePath);

    protected:
        Hoop(int x, int y, int w, int h, const std::string& imagePath);
    
        
    private:

    };



#endif

