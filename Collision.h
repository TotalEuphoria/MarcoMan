#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

#include <iostream>
#include <vector>

#include "Player.h"
#include "StaticEntity.h"
#include "Block.h"

class Collision
{
public:
	Collision();
	~Collision();
	static float platform( MovingEntity& , Block ); 
private:
	struct State;
};

#endif // COLLISION_H_INCLUDED
