#ifndef SCENARIO_H_INCLUDED
#define SCENARIO_H_INCLUDED

#include "Game.h"
#include "Point.h"

#include <SDL2/SDL_image.h>

extern const int SCENARIO_WIDTH;
extern const int SCENARIO_HEIGHT;

extern const SDL_Color BLUE_SKY;

class Scenario
{
public:
	SDL_Rect rect = { 0 , 0 , 0 , 0 };
	
	Scenario();
	~Scenario();
	
	void render();

};
extern Scenario scenario;

#endif // SCENARIO_H_INCLUDED
