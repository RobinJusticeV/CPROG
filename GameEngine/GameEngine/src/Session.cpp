#include "Session.h"
#include <SDL2/SDL.h>
#include "System.h"
#include "Score.h"
#include <SDL2/SDL_ttf.h> 
#include "Constants.h"

#include <iostream>

#define FPS 60

namespace cwing 
{
    Session::Session() {
        std::cout << "*** Session::Session()\n";
        Score::getInstance()->reset(); // Restarta score-räknaren
    }

    Session& Session::getInstance() {
        static Session instance;
        return instance; 
    }

    void Session::add(Component* c) {
        comps.push_back(c);
    }

    void Session::remove(Component* c) { 
        comps.push_back(c); 
    }

    bool initFonts() {
        if (TTF_Init() == -1) {
            std::cout << "TTF_Init: " << TTF_GetError();
            return false;
        }
        return true;
    }

    void closeFonts() {
        TTF_Quit();
    }

    void drawText(SDL_Renderer* renderer, const char* text, int x, int y) {

        std::string fontPath = constants::gResPath + "fonts/arial.ttf";

        TTF_Font* font = TTF_OpenFont(fontPath.c_str(), 14);
        if (!font) {
            std::cout << "TTF_OpenFont: " << TTF_GetError();
            return;
        }

        SDL_Color color = {255, 0, 0}; 
        SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_Rect dstrect = {x, y, surface->w, surface->h};
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
        TTF_CloseFont(font);
    }

    void Session::run() {
        const int tickInterval = 1000 / FPS;
        bool quit = false;

        if (!initFonts()) return;

        while (!quit) {
            Uint32 nextTick = SDL_GetTicks() + tickInterval;

            // Eventhantering
            SDL_Event eve;
            while (SDL_PollEvent(&eve)) {
                switch (eve.type) {
                    case SDL_QUIT: quit = true; break;
                    case SDL_MOUSEBUTTONDOWN:
                        for (Component* c : comps)
                            c->mouseDown(eve);
                        break;
                    case SDL_MOUSEBUTTONUP:
                        for (Component* c : comps)
                            c->mouseUp(eve);
                        break;
                    case SDL_KEYDOWN:
                        for (Component* c : comps)
                            c->keyDown(eve);
                        break;
                    case SDL_KEYUP:
                        for (Component* c : comps)
                            c->keyUp(eve);
                        break;
                }
            }

            SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
            SDL_RenderClear(sys.get_ren());

           
            for (auto i = 0; i < comps.size(); i++) {
                for (auto j = 0; j < comps.size(); j++) {
                    if (i != j) {
                        if (comps[i]->checkCollision(*(comps[j]))) {
                            
                            comps[i]->collisionDetected(*(comps[j]));
                        }
                    }
                }
            }

            // Uppdatera och rita comps
            for (Component* c : comps) {
                c->draw();
                c->update();
            }

            // for (int i = 0; i < comps.size(); i++) {

            //     if (!(comps[i]->isAlive())){
            //         // delete comps[i];
            //         //comps.erase(comps[i]);
            //     }
            // }

            for (int i = 0; i < comps.size(); i++) { 
                if (!(comps[i]->isAlive())) { 
                    delete comps[i]; 
                    comps.erase(comps.begin() + i);
                    --i; 
                }
            }

            // Visa poäng på skärmen
            std::string scoreText = "Score: " + std::to_string(Score::getInstance()->getScore());
            drawText(sys.get_ren(), scoreText.c_str(), 50, 50);

            SDL_RenderPresent(sys.get_ren());

            int delay = nextTick - SDL_GetTicks();
            if (delay > 0)
                SDL_Delay(delay);
        }

        closeFonts();
    }

    Session::~Session() {
        for (Component* c : comps) {
            delete c;
        }
    }

    Session ses; // Statiskt globalt objekt (definierad utanför funktioner.)
}
