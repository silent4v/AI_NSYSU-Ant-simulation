#include "ant.h"
using namespace std;

Ant::Ant()
{
    this->lived = true;
    this->hungry_day = 0;
}

Ergate::Ergate()
{
    this->job = true;
}

Ergate::Ergate(int a,int b)
{
    this->job = true;
    this->x = a;
    this->y = b;
}

Queen::Queen()
{
    this->job = false;
}

Queen::Queen(int a,int b)
{
    this->job = false;
    this->x = a;
    this->y = b;
}

Food::Food()
{
    this->days = 0;
}


Food::Food(int a,int b)
{
    this->days = 0;
    this->x = a;
    this->y = b;
}

Pheromone::Pheromone()
{
    this->days = 0;
    this->magnitude = TIME_INTERVAL;    //TIME_INTERVAL in space.h
}

Pheromone::Pheromone(int a,int b)
{
    this->days = 0;
    this->magnitude = TIME_INTERVAL;    //TIME_INTERVAL in space.h
    this->x = a;
    this->y = b;
}

bool Ergate::sensor()
{
    bool food(false);
}