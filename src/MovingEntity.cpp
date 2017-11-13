#include "MovingEntity.h"

const int DEAD = -1;
const int NONE = 0;
const int MOVE = 1;
const int SHOOT = 2;
const int HIT = 3;
const int STAND = 4;
const int JUMP_ASC = 5;
const int JUMP_DES = 6;
MovingEntity::MovingEntity( float x , float y , int w , int h  ) : StaticEntity( x , y , w , h )
{
    
}

MovingEntity::~MovingEntity() { }

void MovingEntity::adjustAngle( Point b )
{
    direction = position - b;
    direction.normalize();
}

void MovingEntity::update()
{
	move();
	render();
}
