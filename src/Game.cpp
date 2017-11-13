#include "Game.h"

Game game;

const int WINDOW_WIDTH = 256;
const int WINDOW_HEIGHT = 240;

const std::string WINDOW_TITLE = "Marco Mayne!";

const std::string CWD = boost::filesystem::current_path().generic_string();

Game::Game()
{
    quit = false;
	window = SDL_CreateWindow( 	WINDOW_TITLE.c_str() ,
								SDL_WINDOWPOS_CENTERED ,
								SDL_WINDOWPOS_CENTERED ,
								1024 ,
								960 ,
								SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE );
    if( window )
    {
        renderer = SDL_CreateRenderer( window , -1 , SDL_RENDERER_ACCELERATED ); 
        SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "linear" );  // make the scaled rendering look smoother.
        SDL_RenderSetLogicalSize( renderer, WINDOW_WIDTH , WINDOW_HEIGHT );
    }
    else {  }
}
Game::~Game() { SDL_Quit(); }

SDL_Window* Game::getWindow() { return window; }
SDL_Renderer* Game::getRenderer() { return renderer; }

void Game::event( SDL_Event* event )
{
    if ( event->type == SDL_QUIT ) { quit = true; }
    else { }
}
