#include "Point.h"

Point::Point( ) { x = y = 0; }
Point::Point( float x , float y ) { this->x = x; this->y = y; }

Point::~Point( ) { }

Vector operator-( Point a , Point b )
{
	return Vector( b.x - a.x , b.y - a.y );
}
