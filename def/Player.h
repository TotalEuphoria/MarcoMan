#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "MovingEntity.h"
#include "Texture.h"
#include "Physics.h"
#include "Timer.h"
#include <iostream>

class Player : public MovingEntity , Texture
{
public:
	Player();
	~Player();
	void move();
	void render();
	void event( SDL_Event* );
	void bound();
	void xBounding( float );
	void jump( float );

	int previousY = 0;
	
};

#endif // PLAYER_H_INCLUDED
