#ifndef STATICENTITY_H_INCLUDED
#define STATICENTITY_H_INCLUDED

#include "Texture.h"
#include "Point.h"
#include "Scenario.h"

class StaticEntity
{
public:
	SDL_Rect textureRect;
	SDL_Rect windowRect;
	Point position = { 0 , 0 };
	int mapLocator = 0;
    StaticEntity( float , float , int , int );
	StaticEntity( int , int );
    StaticEntity(  );
    virtual ~StaticEntity ();
	
	void adjustRectPosition();
    void adjustRectSprite();
};

#endif // STATICENTITY_H_INCLUDED
