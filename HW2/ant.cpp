#include "ant.h"
#include <stdlib.h>
using namespace std;

void Point::set(int a,int b)
{
    this->x = a;
    this->y = b;
}
Point::Point()
{
    set(0,0);
}

Point::Point(int a,int b)
{
    set(a,b);
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

Ant::Ant()
{
    this->lived = true;
    this->hungry_day = 0;
}

Ergate::Ergate()
{
    this->job = true;
}

Ergate::Ergate(Point t)
{
    this->job = true;
    this->next_step = this->now = t;
}

Queen::Queen()
{
    this->job = false;
}

Queen::Queen(Point t)
{
    this->job = false;
    this->now = t;
}

Food::Food()
{
    this->days = 0;
}


Food::Food(Point t)
{
    this->days = 0;
    this->now = t;
}

Pheromone::Pheromone()
{
    this->days = 0;
    this->magnitude = TIME_INTERVAL;    //TIME_INTERVAL in space.h
}

Pheromone::Pheromone(Point t)
{
    this->days = 0;
    this->magnitude = TIME_INTERVAL;    //TIME_INTERVAL in space.h
    this->now = t;
}

Point Ergate::sensor(Space* sp)     //Space is defined in 
{
    Point for_return;
    for(int i = this->now.y - SPACE_INTERVAL ; i <= this->now.y + SPACE_INTERVAL ; i++)
        for(int j = this->now.x - SPACE_INTERVAL ; j < this->now.x + SPACE_INTERVAL ; j++)
            if(sp[i][j] == FOOD)
                return Point(j,i);
    return this->now;
}

void Ergate::work()
{
    this->next_step = this->sensor();   //if food-undetected , random walk
    if(this->next_step == this->now)
    {
        this->now.set(this->now.x + random() % SPACE_INTERVAL , this->now.y + random() % SPACE_INTERVAL);
        if(++this->hungry_day == TIME_INTERVAL)
            this->lived = false;
    }
        
    else
    {
        this->now = this->next_step;
        this->hungry_day = 0;
    }       
}