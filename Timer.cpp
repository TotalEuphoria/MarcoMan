#include "Timer.h"

Timer timer;

Timer::Timer() 
{
    previousTime = ( SDL_GetTicks() / 1000.f );
    acumulator = frameTime = currentTime = acumulator = timeStep = false;
}

Timer::~Timer() { }

float Timer::getTimeStep() { return timeStep; }

void Timer::getTicks()
{
    currentTime = ( SDL_GetTicks() / 1000.f );
    frameTime = currentTime - previousTime;
    previousTime = currentTime;
    timeStep = 0;
    if ( frameTime > 0.25 ) { frameTime = 0.25; }
    else { } 
    acumulator += frameTime;
    
    while ( acumulator >= 0.01 )
    {
        acumulator -= 0.01;
        timeStep += 0.01;
    }
 }

