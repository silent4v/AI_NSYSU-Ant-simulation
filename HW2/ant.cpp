#include "ant.h"

Ergate::Ergate()
{
    this->lived(true);
    this->job(true);
    this->hungry_day(0);
}

Queen::Queen()
{
    this->lived(true);
    this->job(false);
    this->hungry_day(0);
}

Food::Food()
{
    this->days(0);
}

Pheromone::Pheromone()
{
    this->days(0);
    this->magnitude(TIME_INTERVAL);
}

