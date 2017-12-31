#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

#include "Player.h"
#include "StaticEntity.h"
#include "Block.h"
#include <vector>
#include <SDL2/SDL.h>
#include <cmath>

class Collision
{
public:
	Collision();
	~Collision();
	static void platform( MovingEntity& , Block ); 
	static SDL_Rect transformRect( StaticEntity& );
	static SDL_Rect transformPlatformRect( StaticEntity& );
	static bool bottomToTop( SDL_Rect , SDL_Rect );

private:
	struct State;
};

#endif // COLLISION_H_INCLUDED
