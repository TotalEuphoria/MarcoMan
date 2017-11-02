#include "Game.h"

Game game;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 448;

const char* WINDOW_TITLE = "Marco Mayne!";

Game::Game()
{
    quit = false;
	window = SDL_CreateWindow( 	WINDOW_TITLE ,
								SDL_WINDOWPOS_CENTERED ,
								SDL_WINDOWPOS_CENTERED ,
								WINDOW_WIDTH ,
								WINDOW_HEIGHT ,
								SDL_WINDOW_OPENGL );
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

