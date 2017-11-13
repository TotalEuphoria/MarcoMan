#include "Player.h"



Player::Player() : MovingEntity( 32 , 32 , 24 , 24 ) , Texture( CWD+"/sprites/megamanSpritesheet.png" )
{
	speed = 200;
	state = JUMP_DES;
	textureRect.x = 8;
	textureRect.y = 13;
	textureRect.w = 21;
	textureRect.h = 23;
}

Player::~Player()
{
}

void Player::event( SDL_Event* event )
{
    if( event->type == SDL_KEYDOWN && event->key.repeat == 0 )
    {
        switch( event->key.keysym.sym )
        {
            case SDLK_a: velocity.x -= speed; break;
            case SDLK_d: velocity.x += speed; break;
			case SDLK_SPACE: 
				if( state == STAND )
				{
					velocity.y -=  300;
					state = JUMP_ASC;
				}
				break;
        }
    }
    else if( event->type == SDL_KEYUP && event->key.repeat == 0 )
    {
        switch( event->key.keysym.sym )
        {
			case SDLK_a: velocity.x += speed; break;
            case SDLK_d: velocity.x -= speed; break;
			case SDLK_SPACE:
				if( state == JUMP_ASC )
				{
					velocity.y += 200;
					state = JUMP_DES; 
				}
				break;
        }
    }
    else { }
}
void Player::xBounding( float xValue )
{
	if( velocity.x )
	{
		if( velocity.x > 0 )
		{
			if( windowRect.x >=  ( ( WINDOW_WIDTH / 2 ) + 100 )  && scenario.rect.x <= ( SCENARIO_WIDTH - WINDOW_WIDTH ) )
			{
				scenario.rect.x += xValue;
			}
			if( position.x >= SCENARIO_WIDTH - 32 ) {  }
			else{ position.x += xValue; }
		}
		else
		{
			if( windowRect.x <=  ( ( WINDOW_WIDTH / 2 ) - 100 ) && scenario.rect.x > 0 )
			{
				scenario.rect.x += xValue;
			}
			if( position.x <= 32 ) {  }
			else { position.x += xValue; }
		}
	}
	else { }
}
void Player::move()
{
	
	float timeStep = timer.getTimeStep();
	float value = 0;
	if( state  == STAND  ) { velocity.y =  0; }
	else { velocity = velocity + GRAVITY;  }
	
	if( velocity.y > 0 ) { state = JUMP_DES; }
	
	
	value  = velocity.y * timeStep;
	
	position.y += value;
	xBounding( ( velocity.x * timeStep ) );
	
	
}
void Player::render()
{
	adjustRectPosition();
	SDL_RenderCopy( game.getRenderer() , getTexture() , &textureRect , &windowRect );
}

