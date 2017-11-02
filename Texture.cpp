#include "Texture.h"

Texture::Texture( const char* filePath )
{
    SDL_Surface* surface = IMG_Load( filePath );
    if ( surface )
    {
        texture = SDL_CreateTextureFromSurface( game.getRenderer() , surface );
        SDL_FreeSurface( surface );
    }
    else { }
}
Texture::Texture( SDL_Texture* texture ) { this->texture = texture; }
Texture::Texture( ) { texture = NULL; }

Texture::~Texture( ) { }

SDL_Texture* Texture::getTexture() { return texture; }
