#include "base_object.h"

void Point::set(int a,int b)
{
    this->x = a;
    this->y = b;
}

Point::Point()
{
    set(0,0);
}

Point& Point::operator=(Point t)
{
    this->x = t.x;
    this->y = t.y;
    return *this;
}

bool operator ==(Point a,Point b)
{
    return ((a.x == b.x ) && (a.y == b.y)) ? true : false;
}