#include "Block.h"

Block::Block( const std::string filePath , int w = 32 , int h = 32 ) : Texture( filePath )
{
	this->w = w;
	this->h = h;
}

Block::~Block()
{
}

void Block::add( float x1 , float x2 , float y )
{
	int i = 0;
	for( i = x1; i < x2; i += 24  )
	{
		entities.push_back( StaticEntity( i , y , w , h ) );
	}
}
void Block::render()
{
	
	for( auto i : entities)
	{
		i.adjustRectPosition();
		SDL_RenderCopy( game.getRenderer() , getTexture() , NULL , &i.windowRect );
	}
}
