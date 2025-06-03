#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL2/SDL.h>
#include <string>

namespace cwing 
{
	class Component
	{
	public:
		virtual ~Component();
		virtual void mouseDown(const SDL_Event&) {}
		virtual void mouseUp(const SDL_Event&) {}
		virtual void keyDown(const SDL_Event&) {}
		virtual void keyUp(const SDL_Event&) {}
		//varje klass måste implementera draw funktionen
		virtual void draw() const = 0;
		const SDL_Rect& getRect() const { return rect; }
		virtual void update() {};

		//virtuell eller ej?
		// bool checkCollision(SDL_Rect a, SDL_Rect b);
		virtual bool checkCollision(const Component& other);
		virtual void collisionDetected(const Component& other);

		bool isAlive(){
			return is_alive;
		}

		std::string compType;

	protected:
	// så att det inte går att göra objekt av den, bara subklasser
		Component(int x, int y, int w, int h);
		void setLocation(int x, int y);
		bool is_alive = true;
		
	private:
		SDL_Rect rect;
		Component(const Component&) = delete;
		const Component& operator=(const Component&) = delete;
		
	};
}
#endif
