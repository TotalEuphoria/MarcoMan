#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <SDL2/SDL.h>


class Timer
{    
public:
    Timer();
    ~Timer();
    float getTimeStep();
	void getTicks();
private:
	float timeStep , acumulator , currentTime , previousTime , frameTime;
};

extern Timer timer;

#endif // TIMER_H_INCLUDED
