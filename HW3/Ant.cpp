#include "base.h"
#include <math.h>

bool operator ==(Point a,Point b)
{
    return (a.x == b.x) && (a.y == b.y);
}

int Ant::food_num = 0;
int Worker::object_num = 0;

map<Point,Worker*> Worker::antPoint;
map<Point,Pheromone> Worker::pheromonePoint;
list<Point> Worker::forDelete;

list<Point> Pheromone::forDelete;

Worker::Worker()
{
    blood = TIME_INTERVAL;
    job = "Worker";
    name = ++object_num;
    carried = false;
    lastfood = Point();
}

Point Worker::sensor(Space &f)
{
    int pheromon_density = 0;
    Point for_return;
    for(int i = position.x - SPACE_INTERVAL ; i <= position.x + SPACE_INTERVAL ; i++)
    {
        if(i < 0 || i >= SPACE_BOUND_END)
            continue;
        for(int j = position.y - SPACE_INTERVAL ; j <= position.y + SPACE_INTERVAL ; j++)
        {
            if(j < 0 || j >= SPACE_BOUND_END)
                continue;
            switch(f.field[i][j])
            {
                case FOOD:
                    return Point(i,j);
                case PHEROMONE:
                    if(pheromonePoint[Point(i,j)].get_density() > pheromon_density && pheromonePoint[Point(i,j)].name == this->name)
                    {
                        for_return = Point(i,j);
                        pheromon_density = pheromonePoint[Point(i,j)].get_density();
                    }
                    break;
                default:
                    break;
            }
        }
    }

    if(for_return.x == 0 && for_return.y == 0)
    {
        if(lastfood == Point())
            return Point(rand() % SPACE_BOUND_END,rand() % SPACE_BOUND_END);
        return (abs(lastfood.x) > abs(lastfood.y)) ? Point(position.x + lastfood.x , position.y) : Point(position.x , position.y + lastfood.y);           

    }
    return for_return;
}

void Worker::put_phe()
{
    if(!(position == Point(0,0)))
        pheromonePoint[position] =  Pheromone(TIME_INTERVAL,object_num);
}

void Worker::move(Space &g)
{
    if(!(position == Point(0,0)))
        g.field[position.x][position.y] = PHEROMONE;
    //antPoint.erase(position);
    forDelete.push_back(position);
    if(carried)
    {
        int cache_x = position.x - SPACE_BOUND_START;
        int cache_y = position.y - SPACE_BOUND_START;
        int shrinkize = ceil(SPACE_INTERVAL / sqrt(cache_x*cache_x + cache_y*cache_y));
        cache_x *= shrinkize;
        cache_y *= shrinkize;
        Point next_point(cache_x,cache_y);
        antPoint[next_point] = this;
        g.field[next_point.x][next_point.y] = WORKER;
    }
    else
    {
        position = sensor(g);
        antPoint[position] = this;
        g.field[position.x][position.y] = WORKER;
    }
    
}

void Worker::work(Space &g)
{
    if(position == Point(SPACE_BOUND_START,SPACE_BOUND_START))
        add_food();
    put_phe();
    move(g);
}

Queen::Queen()
{
    blood = TIME_INTERVAL * 2;
    job = "Queen";
    position = Point();          
}

void Queen::addAnt(Space &f)
{
    int x, y;
    Worker* AntCache;
    while(true)
    {
        x = rand() % SPACE_BOUND_END;
        y = rand() % SPACE_BOUND_END;
        if(f.field[x][y] != 0)
            continue;
        else
        {
            AntCache = new Worker();
            f.field[x][y] = WORKER;
            Point tempPoint(x, y);
            Worker::antPoint[tempPoint] = AntCache;
            break;
        }
    }
}

void Queen::makeLOVE(Space &g)
{
    //Worker cache;
    addAnt(g);
}

void Queen::work(Space &g)
{
    if(blood > TIME_INTERVAL/2)
        makeLOVE(g);
    if(food_num > 0)
    {
        blood += 2*food_num;
        clear_food();
        if(blood > 2*TIME_INTERVAL)
            blood = 2*TIME_INTERVAL;
    }
    else
        blood --;
}
