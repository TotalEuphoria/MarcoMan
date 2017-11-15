#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include "Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Texture
{
public:
    Texture( const std::string );
    Texture( SDL_Texture* );
    Texture();
    virtual ~Texture ();
	
	SDL_Texture* getTexture();
	
private:
	SDL_Texture* texture;
};


#endif // TEXTURE_H_INCLUDED
