#ifndef MOVINGENTITY_H_INCLUDED
#define MOVINGENTITY_H_INCLUDED

#include "Vector.h"
#include "StaticEntity.h"
#include "Point.h"
#include "Scenario.h"

extern const int DEAD;
extern const int NONE;
extern const int MOVE;
extern const int SHOOT;
extern const int HIT;
extern const int STAND;
extern const int JUMP_ASC;
extern const int JUMP_DES;

class MovingEntity : public StaticEntity
{
public:
    Vector direction , velocity , acceleration;
	int state , power , hp , speed;

    MovingEntity( float x , float y , int w , int h );
    virtual ~MovingEntity ();
	
	void adjustAngle( Point );
		
	virtual void move() = 0;
	virtual void render() = 0;
	virtual void update();
};

#endif // MOVINGENTITY_H_INCLUDED
