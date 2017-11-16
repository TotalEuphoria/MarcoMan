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
		float topB = Collision::platform( block , map.block );
		if( topB )
		{
			if( block.state == JUMP_DES )
			{
				block.state = STAND;
				if( ( topB - 24 ) != floor( block.position.y ) )
				{
					block.position.y = ( topB - 24 );
				}
				else { }
			}
		}
		else
		{
			if( block.state == STAND ) { block.state = JUMP_DES; }
		}
		
		while( SDL_PollEvent( &event ) )
        {
            game.event( &event );
            block.event( &event );
        }
        SDL_SetRenderDrawColor( game.getRenderer() , 0xFF , 0xFF , 0xFF , 0xFF );
        SDL_RenderClear( game.getRenderer() );
        scenario.render();
		map.block.render();
		block.update();
        SDL_RenderPresent( game.getRenderer() );
        timer.getTicks();
    }
    return 0;
}
