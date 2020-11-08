#include "ant.h"
#include <stdlib.h>

using namespace std;

Point::Point(int a,int b)
{
    set(a,b);
    if(this->x < MIN_X)
        this->x = MIN_X;
    if(this->y < MIN_Y)
        this->y = MIN_Y;
    if(this->x > MAX_X)
        this->x = MAX_X;
    if(this->y > MAX_Y)
        this->y = MAX_Y;
}

Ant::Ant()
{
    this->lived = true;
    this->days = 0;
}

Ergate::Ergate()
{
    this->job = true;
    this->carry_food = false;
}

Ergate::Ergate(Point t)
{
    this->job = true;
    this->carry_food = false;
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
    this->number = 0;
}

Food::Food(Point t,int x)
{
    this->days = 0;
    this->now = t;
    this->number = x;
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

Point Ergate::sensor(Space** sp)     //Space is defined in 
{
    if((this->carry_food))      //go home
        return Point(this->now.x - SPACE_INTERVAL ,this->now.y - SPACE_INTERVAL);
    
    for(int i = this->now.y - SPACE_INTERVAL ; i <= this->now.y + SPACE_INTERVAL ; i++)
    {
        for(int j = this->now.x - SPACE_INTERVAL ; j < this->now.x + SPACE_INTERVAL ; j++)
        {
            switch(sp[i][j])
            {
                case FOOD:
                    this->carry_food = true;
                    return Point(j,i);
                case PHEROMONE:
                    return Point(j,i);
                default:
                    break;
            }
        }
    }
    return this->now;
}

void Ergate::work(Space** sp)
{
    int xx,yy;
    do
    {
        xx = random() % SPACE_INTERVAL;
        yy = random() % SPACE_INTERVAL;
    } while((xx < MIN_X)||(yy < MIN_Y)||(xx > MAX_X)||(yy > MAX_X));

    this->next_step = this->sensor(sp);   //if food-undetected , random walk
    if(this->next_step == this->now)
    {
        this->now.set(this->now.x + xx , this->now.y + yy);
        add_feature(sp,ANT,this->now,this);
        if(++this->days == TIME_INTERVAL)
            this->lived = false;
    }
        
    else
    {
        //cout << "(" << this->now.x << "," << this->now.y << ") (" << this->next_step.x << "," << this->next_step.y << ")" << endl;
        sp[this->now.x][this->now.y] = 0;
        this->now = this->next_step;
        add_feature(sp,ANT,this->now,this);
        this->days = 0;
    }       
}

bool Ant::add_day()
{
    if(++(this->days) == TIME_INTERVAL)
        this->lived = false;
    return this->lived;
}

void Food::add_day()
{
    if(++this->days == TIME_INTERVAL)
        return false;
    return true;
}

void Pheromone::add_day()
{
    this->days++;
    this->magnitude--;
    if(this->days == TIME_INTERVAL)
        return false;
    return true;
}

void add_feature(Space** s,int t)
{
    int x,y;
    do
    {
        x = rand() % space_size;
        y = rand() % space_size;
    }while(s[x + MIN_X][y + MIN_Y] != 0);
    
    s[x + MIN_X][y + MIN_Y] = t;
    switch(t)
    {
        case ANT:
            space_map[Point(x+MIN_X,y+MIN_Y)] = new Ergate(Point(x+MIN_X,y+MIN_Y));
            break;
        case PHEROMONE:
            space_map[Point(x+MIN_X,y+MIN_Y)] = new Pheromone(Point(x+MIN_X,y+MIN_Y));
            break;
        case FOOD:
            space_map[Point(x+MIN_X,y+MIN_Y)] = new Food(Point(x+MIN_X,y+MIN_Y),random()%20);
            break;
        default:
            break;
    }
}

void add_feature(Space** s,int t,Point o,Base *b)
{
    s[o.y][o.x] = t;
    cache[o] = b;
}

void delete_ant(Space** s, int x, int y)              //change space[x][y] ant into nothing
{
    if(x < MIN_X || y < MIN_Y || x > MAX_X || y > MAX_Y)
        cerr << "delete range out of bondary" << endl;
    else
    {
        s[x][y] = 0;
        p = space_map.find(Point(x,y));
        delete p->second;
        space_map.erase(p);
    }
}