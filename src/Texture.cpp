#include "Texture.h"

Texture::Texture( const std::string filePath )
{
    SDL_Surface* surface = IMG_Load( filePath.c_str() );
    if ( surface )
    {
        texture = SDL_CreateTextureFromSurface( game.getRenderer() , surface );
        SDL_FreeSurface( surface );
    }
    else { printf("%s",SDL_GetError()); }
}
Texture::Texture( SDL_Texture* texture ) { this->texture = texture; }
Texture::Texture( ) { texture = NULL; }

Texture::~Texture( ) { }

SDL_Texture* Texture::getTexture() { return texture; }
