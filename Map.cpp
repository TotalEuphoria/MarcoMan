#include "Map.h"

const char* FILEPATH = "/home/marco/projects/MarcoMan/sprites/brownBlock.bmp";

Map::Map() : block( FILEPATH , 32 , 32 )
{
	block.add( 0 , 2176 , 420 );
	block.add( 0 , 2176 , 450 );
	
	block.add( 100 , 300 , 300 );
	block.add( 200 , 300 , 100 );
}

Map::~Map()
{
}


