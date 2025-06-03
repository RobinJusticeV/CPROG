/* Följande filer måste finnas i 'src/':
 * Button.cpp, Component.cpp, Label.cpp, f12_main.cpp, Session.cpp, System.cpp
 * Följande filer måste finnas i 'include/':
 * Button.h, Component.h, Constants.h, Label.h, Session.h, System.h
 */

// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>

#include "System.h"
#include "Session.h"
#include "Background.h"
#include "Player.h"
#include "Projectile.h"
#include "Hoop.h"
#include "Enemy.h"
#include "Score.h"
#include "Timer.h"
#include <string>
#include <iostream>

/*  PATH TO YOUR RESOURCE FOLDER 'resources'
*   'gResPath' is a global constant defined in "Constants.h", 
*   representing the relative path to your resource folders as a string,
*   i.e. ' const std::string gResPath = "../../resources/" '
*   Use it through its namespace, 'constants::gResPath'.
*
*   If you need to copy your 'resources' folder into directory
*   '/build/debug/', in that case change gResPath="./resources/"
*
*   Change to your own path if you choose a different approach!
*   Absolut Path(Second choice)
*   gResPath = "/Users/kjellna/dev/cpp/sdl2_second/resources/";
*/

using namespace std;
using namespace cwing;

//spelklass, ta ut den senare
// cwing::Session ses;

int main(int argc, char** argv) {
	std::cout << "*** main()\n";
	

	// cwing::Session& ses = cwing::Session::getInstance();
	

	// Få in background
	Background* background = Background::getInstance(0, 0, 650, 400, "images/basketball_court.png");


	// Få in hoop
	Hoop* hoopMini = Hoop::getInstance(150, 45, 25, 25, "images/hoop.png");
	Hoop* hoopMedium = Hoop::getInstance(300, 45, 30, 30, "images/hoop.png");
	Hoop* hoopBig = Hoop::getInstance(460, 45, 44, 44, "images/hoop.png");

	

	//få in spelaren och moståndaren
	Player* player = Player::getInstance(200, 300, 45, 50, "images/player.png");

	Enemy* enemy = Enemy::getInstance(200, 150, 80, 80, "images/zoe.png");

	ses.add(background);
	ses.add(player);
	ses.add(hoopMini);
	ses.add(hoopMedium);
	ses.add(hoopBig);
	ses.add(enemy);


	ses.run();

	//ta bort objekten från heapen
	// delete background;
	// delete hoopMini;
	// delete hoopMedium;
	// delete hoopBig;
	// delete player;
	// delete enemy;
	
	
	return 0;
}
