#ifndef SCENARIO_H_INCLUDED
#define SCENARIO_H_INCLUDED

#include "Game.h"
#include "Point.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>

extern const int SCENARIO_WIDTH;
extern const int SCENARIO_HEIGHT;
extern const SDL_Color BLUE_SKY;

class Scenario
{
public:
	Point position;
	SDL_Rect rect = { 0 , 0 , GAME_LOGICAL_WIDTH , GAME_LOGICAL_HEIGHT };
	std::map<int,std::map<int,int>> map;
	
	Scenario();
	~Scenario();

	void move( float distance );
	void generateScenarioMatrix();
};
extern Scenario scenario;

#endif // SCENARIO_H_INCLUDED
