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
	std::vector<StaticEntity> entities;

	Block( const std::string filePath , int , int );
	~Block();
	void add( float , float , float );
	void render();
};

#endif // BLOCK_H_INCLUDED
