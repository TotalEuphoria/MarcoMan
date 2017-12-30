#include "Player.h"

Player::Player() : MovingEntity( 32 , 32 , 24 , 24 ) , Texture( CWD+"/sprites/megamanSpritesheet.png" )
{
	speed  = 200;
	acceleration = { 200 , 0 };
	deceleration = { 400 , 0 };
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
		    case SDLK_a: currentAcceleration.x -= acceleration.x; break;
		    case SDLK_d: currentAcceleration.x += acceleration.x; break;
		    case SDLK_SPACE:
			    if( state == STAND || state == MOVE )
			    {
				    state = JUMP_ASC;
				    velocity.y -= 200;
			    }
			    break;
		    case SDLK_x:
			    position.x = 0;
			    position.y = 0;
			    scenario.rect.x = 0;
			    scenario.position.x = 0;
			    state = JUMP_DES;
			    break;
	    }
    }
    else if( event->type == SDL_KEYUP && event->key.repeat == 0 )
    {
	    switch( event->key.keysym.sym )
	    {
		    case SDLK_a: currentAcceleration.x += acceleration.x; break;
		    case SDLK_d: currentAcceleration.x -= acceleration.x; break;
		    case SDLK_SPACE:
			    if( state == JUMP_ASC )
			    {
				    state = JUMP_DES;
				    velocity.y += 50;
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
			if( windowRect.x >=  ( ( GAME_LOGICAL_WIDTH / 2 ) + 25 )  &&
				scenario.rect.x <= ( SCENARIO_WIDTH - WINDOW_WIDTH )
				)
			{
				scenario.move( xValue );
			}
			if( position.x >= SCENARIO_WIDTH - 25 ) {  }
			else{ position.x += xValue; }
		}
		else
		{
			if( windowRect.x <=  ( ( GAME_LOGICAL_WIDTH / 2 ) - 25 ) && scenario.rect.x > 0 )
			{
				scenario.move( xValue );
			}
			if( position.x <= 24 ) {  }
			else { position.x += xValue; }
		}
	}
	else { }
}

void Player::move()
{
	float timeStep = timer.getTimeStep();
	float value = 0;
	
	if( state == JUMP_DES || state == JUMP_ASC ) { velocity = velocity + GRAVITY; }
	else { velocity.y = 0; }
	
	position.y += velocity.y * timeStep;

	printf("%f \n" , position.y);
	
	if ( currentAcceleration.x != 0 )
	{
		if( velocity.x >= speed ) { velocity.x = speed; }
		else if( velocity.x <= -(speed)) { velocity.x = -(speed); }
		else { velocity.x += currentAcceleration.x * timeStep ; }
	}
	else
	{
		if ( velocity.x < 0 ) { velocity.x += deceleration.x * timeStep; }
		else if ( velocity.x > 0 ) { velocity.x -= deceleration.x * timeStep; } 
		else { velocity.x = 0; }
	}

	if( velocity.x != 0 && state == STAND ) { state = MOVE; }

	xBounding( ( velocity.x * timeStep ) );
}

void Player::render()
{
	adjustRectPosition();
	SDL_RenderCopy( game.getRenderer() , getTexture() , &textureRect , &windowRect );
}
