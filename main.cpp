#include "Game.h"
#include "Timer.h"
#include "Scenario.h"
#include "Map.h"
#include "Player.h"
#include "Collision.h"

#include <SDL2/SDL.h>

int main()
{
	SDL_Event event;
	Map map;
	Player block;
	while( !game.quit )
	{
		timer.update();
		
		while ( timer.acumulator >= timer.getTimeStep() )
		{
			block.move();
			Collision::platform( block , map.block );
			timer.acumulator -= timer.getTimeStep();
		}
		
		while( SDL_PollEvent( &event ) )
		{
			game.event( &event );
			block.event( &event );
		}
		
		SDL_SetRenderDrawColor( game.getRenderer() , 0xFF , 0xFF , 0xFF , 0xFF );
		SDL_RenderClear( game.getRenderer() );
		map.block.render();
		block.render();
		SDL_RenderPresent( game.getRenderer() );
	}
	return 0;
}
