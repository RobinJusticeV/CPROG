#ifndef SESSION_H
#define SESSION_H

#include <vector>
#include <SDL2/SDL.h>
#include "Component.h"

namespace cwing {

    class Session {
    public:
        Session();
		~Session();
		static Session& getInstance();
        void add(Component* c);
        void remove(Component* c);
        void run();
    private:
        std::vector<Component*> comps;
        // std::vector<Component*> comps;
		
    };
    extern Session ses;
}

#endif
