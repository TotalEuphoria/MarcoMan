#include "Collision.h"
	
Collision::Collision() { }

Collision::~Collision() { }

void Collision::platform( MovingEntity& entity , Block block )
{
	SDL_Rect rectA = transformPlatformRect( entity );
	SDL_Rect rectB = { 0 , 0 , 0 , 0 };
	std::vector<StaticEntity>::iterator i;
	bool detected = false;

	if( entity.state != STAND  )
	{
		for( auto i : block.entities )
		{
/*			if( entity.mapLocator == i.mapLocator )
			{*/
			rectB = transformPlatformRect( i );
			if( bottomToTop( rectA , rectB ) )
			{
				if( entity.state != JUMP_ASC )
				{
					entity.position.y = i.position.y - i.windowRect.h;
					entity.state = STAND;
					detected = true;
				}
			}
		}		    
//		}
		if( !detected && entity.state != JUMP_ASC ) { entity.state = JUMP_DES; }
	}
}

SDL_Rect Collision::transformRect( StaticEntity& entity )
{
	float quarterX = ( ( ( entity.position.x + entity.windowRect.w ) - entity.position.x ) / 4 );
	float quarterY = ( ( ( entity.position.y + entity.windowRect.h ) - entity.position.y ) / 4 );
	int x = floor( entity.position.x + quarterX );
	int y = floor( entity.position.y + quarterY );
	int w = floor( x + ( quarterX * 2 ) );
	int h = floor( y + ( quarterY * 2 ) );
	
	return  SDL_Rect { x , y  , w , h };	
}

SDL_Rect Collision::transformPlatformRect( StaticEntity& entity )
{
	int x = floor( entity.position.x );
	int y = floor( entity.position.y );
	int w = floor( x + entity.windowRect.w );
	int h = floor( y + entity.windowRect.h );

	return  SDL_Rect { x , y  , w , h };
}

bool Collision::bottomToTop( SDL_Rect a , SDL_Rect b )
{

	if
		(
			(  a.h >= b.y && a.h <= ( b.y + 2 ) ) &&
			(
				( a.x >= b.x && a.x <= b.w) ||
				( a.w >= b.x && a.w <= b.w )  
				)
			)
	{
		return true;
	}
	else {
		return false; }
}


