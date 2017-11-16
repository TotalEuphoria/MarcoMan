#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include "Vector.h"
#include <cmath>

class Point
{
public:
	float x , y;
	
	Point();  
	Point( float , float );
	virtual ~Point();
};
extern Vector operator-( Point , Point );

#endif // POINT_H_INCLUDED
