#include "Scenario.h"

Scenario scenario;

const int SCENARIO_WIDTH = 7168;
const int SCENARIO_HEIGHT = 448;
const SDL_Color BLUE_SKY = { 92 , 148 , 252 , 0 };

Scenario::Scenario()
{
	rect.y = ( SCENARIO_HEIGHT - GAME_LOGICAL_HEIGHT );
	rect.w = GAME_LOGICAL_WIDTH;
	rect.h = GAME_LOGICAL_HEIGHT;
}
Scenario::~Scenario() { }
void Scenario::render( )
{
    //SDL_SetRenderDrawColor( game.getRenderer() , BLUE_SKY.r , BLUE_SKY.g , BLUE_SKY.b , BLUE_SKY.a );
    //SDL_RenderFillRect( game.getRenderer() , &rect );
}

