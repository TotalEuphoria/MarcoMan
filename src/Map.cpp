#include "Map.h"

const std::string FILEPATH = CWD+"/sprites/brownBlock.bmp";

Map::Map() : block( FILEPATH , 24 , 24 )
{
	block.add( 0 , 2176 , 420 );
	block.add( 0 , 2176 , 450 );
	
	block.add( 100 , 300 , 300 );
	block.add( 200 , 300 , 100 );
}

Map::~Map()
{
}


