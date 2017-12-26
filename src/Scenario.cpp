#include "Scenario.h"

Scenario scenario;

const int SCENARIO_WIDTH = 7168;
const int SCENARIO_HEIGHT = 240;
const SDL_Color BLUE_SKY = { 92 , 148 , 252 , 0 };

Scenario::Scenario()
{
	generateScenarioMatrix();
}
Scenario::~Scenario() { }

void Scenario::move( float distance )
{
	position.x += distance;
	rect.x = floor( position.x );
}

void Scenario::generateScenarioMatrix()
{
	int id = 0;
	int width = ( SCENARIO_WIDTH / 100 ) + 1;
	int heigth = ( SCENARIO_HEIGHT / 100 ) + 1;

	for( int x = 0 , incrementX = 0 ; x < width; x++ , incrementX += 100 )
	{
		for( int y = 0 , incrementY = 0; y < heigth; y++ , incrementY += 100 )
		{
			map[incrementX][incrementY] = id++;
		}
	}
}


