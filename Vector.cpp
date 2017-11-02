#include "Vector.h"

const float PI = 3.14159265;
const float ANGLE = 180;

Vector::Vector( ) { x = y = 0; }
Vector::Vector( float x , float y )
{ 
    this->x = x;
    this->y = y;
}

Vector::~Vector( ) { }

float Vector::length() const { return sqrt( ( x * x ) + ( y * y ) ); }

float Vector::lengthSqr() const { return ( ( x * x ) + ( y * y ) ); }

void Vector::normalize()
{
    (*this) = (*this) / length();
}

Vector Vector::operator+( const Vector& v ) const { return Vector( x + v.x , y + v.y ); }

Vector Vector::operator-( const Vector& v ) const { return Vector( x - v.x , y - v.y ); }

Vector Vector::operator*( float scalar ) const { return Vector( x * scalar , y * scalar ); }

Vector Vector::operator/( float scalar ) const { return Vector( x / scalar , y / scalar ); }

float Vector::angle( Vector a ) { return ( ( ( atan2( a.y , a.x ) ) * ANGLE ) / PI ); }

