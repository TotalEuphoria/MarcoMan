#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <SDL2/SDL.h>

class Timer
{    
public:
	float acumulator;
	
	Timer();
    ~Timer();
    float getTimeStep();
    void update();
    
private:
	float timeStep , currentTime , previousTime , frameTime;
};

extern Timer timer;

#endif // TIMER_H_INCLUDED
