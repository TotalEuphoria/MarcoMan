#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL2/SDL.h>
#include <boost/filesystem.hpp>
#include <iostream>

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern const std::string WINDOW_TITLE;
extern const std::string CWD;

class Game
{
public:
	bool quit;
	
    Game();
    ~Game();
    
	bool getQuit();
	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();
    void event( SDL_Event* event );
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};
extern Game game;

#endif // GAME_H_INCLUDED
