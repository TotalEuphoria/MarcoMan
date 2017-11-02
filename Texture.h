#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.h"
class Texture
{
public:
    Texture( const char*  );
    Texture( SDL_Texture* );
    Texture();
    virtual ~Texture ();
	
	SDL_Texture* getTexture();
	
private:
	SDL_Texture* texture;
};


#endif // TEXTURE_H_INCLUDED
