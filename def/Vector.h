#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <cmath>
#include <stdio.h>

extern const float PI;
extern const float ANGLE;

class Vector
{
public:
	float x , y;
	
    Vector();
    Vector( float , float);
    virtual ~Vector ();
   
    float length() const;
    float lengthSqr() const;
    void normalize();
    
    Vector operator+( const Vector& ) const;
    Vector operator-( const Vector& ) const;
    Vector operator*( float ) const;
    Vector operator/( float ) const;
    static float angle( Vector );
};


#endif // VECTOR_H_INCLUDED
