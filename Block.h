#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include "StaticEntity.h"
#include "Texture.h"
#include <iostream>
#include <vector>

class Block : public Texture
{
public:
	int w , h;
	
	Block( const char* filePath , int , int );
	~Block();
	void add( float , float , float );
	void render();
	std::vector<StaticEntity> entities;
};

#endif // BLOCK_H_INCLUDED
