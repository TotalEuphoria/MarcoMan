#include "Timer.h"

Timer timer;

Timer::Timer() 
{
    previousTime = ( SDL_GetTicks() / 1000.f );
    acumulator = frameTime = currentTime = acumulator = 0;
    timeStep = 0.01;
}

Timer::~Timer() { }

float Timer::getTimeStep() { return timeStep; }

void Timer::update()
{
	currentTime = ( SDL_GetTicks() / 1000.f );
    frameTime = currentTime - previousTime;
    previousTime = currentTime;

    if ( frameTime > 0.25 ) { frameTime = 0.25; }
    else { } 

    acumulator += frameTime;
}
