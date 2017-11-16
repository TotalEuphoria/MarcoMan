#include "Collision.h"

Collision::Collision() { }

Collision::~Collision() { }

float Collision::platform( MovingEntity& entity , Block block )
{
	float leftA = 0, leftB = 0, rightA = 0, rightB = 0, topA = 0, topB = 0 , bottomA = 0 , bottomB = 0;
	bool detected = true;
	
	std::vector<StaticEntity>::iterator i;
	
	leftA = entity.position.x;
	topA = entity.position.y;
	rightA = entity.position.x + entity.windowRect.w;
	bottomA = entity.position.y + entity.windowRect.h;
	
	for( auto i : block.entities )
	{
		leftB = i.position.x;
        topB = i.position.y;
        rightB = i.position.x + block.w;
        bottomB = i.position.y + block.h;
		
		if ( ( rightA - 8 >= leftB && leftA < rightB ) && 
			 ( topA < bottomB  && topA > bottomB + 10 )
			)
		{
			entity.state = JUMP_DES;
			return entity.position.x; 
		}
		
		if( ( rightA - 8 >= leftB && leftA < rightB ) && 
			( bottomA > topB  && bottomA < topB + 10 ) 
			)
		{
			return topB;
		}
		else {  }
	}
	return 0;
}
