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
    Point for_return = this->now;
    if((this->carry_food))      //go home
        return Point(this->now.x - SPACE_INTERVAL ,this->now.y - SPACE_INTERVAL);
    
    for(int i = this->now.x - SPACE_INTERVAL ; i <= this->now.x + SPACE_INTERVAL ; i++)
    {
        for(int j = this->now.y - SPACE_INTERVAL ; j < this->now.y + SPACE_INTERVAL ; j++)
        {
            switch(sp[i][j])
            {
                case FOOD:
                    this->carry_food = true;
                    return Point(i,j);
                case PHEROMONE:
                    break;
                default:
                    break;
            }
        }
    }
    for(int i = this->now.x - SPACE_INTERVAL  - 2 ; i <= this->now.x + SPACE_INTERVAL + 2 ; i++)
    {
        for(int j = this->now.y - SPACE_INTERVAL - 2 ; j < this->now.y + SPACE_INTERVAL + 2 ; j++)
        {
            if(i >= this->now.x - SPACE_INTERVAL || i <= this->now.x + SPACE_INTERVAL || j >= this->now.y - SPACE_INTERVAL || j <= this->now.y + SPACE_INTERVAL)
                continue;
            else if(sp[i][j] == PHEROMONE)
            {
                for_return = Point(i,j);
                break;
            }
        }
    }
    return for_return;
}

void Ergate::work(Space** sp)
{
    int xx,yy,sum;
    do
    {
        xx = (random() % (SPACE_INTERVAL*2-1)) - (SPACE_INTERVAL);
        yy = (random() % (SPACE_INTERVAL*2-1)) - (SPACE_INTERVAL);
    } while((this->now.x + xx < MIN_X)||(this->now.y + yy < MIN_Y)||(this->now.x + xx > MAX_X)||(this->now.y + yy > MAX_Y));
    if(this->now != Point(MIN_X,MIN_Y))
        sp[this->now.x][this->now.y] = PHEROMONE + PHEROMONE_CONST;
    this->next_step = this->sensor(sp);   //if food-undetected , random walk
    if(this->next_step == this->now)
    {
        this->now.set(this->now.x + xx , this->now.y + yy);
        add_feature(sp,ANT,this,this->now);
    }
    else
    {
        this->now = this->next_step;
        if(this->now == Point(MIN_X,MIN_Y))
        {
            this->carry_food = false;
            queen = 0;
            sum = 0;
            do
            {
                xx = (random() % (SPACE_INTERVAL));
                yy = (random() % (SPACE_INTERVAL));
                sum ++;
            }while(sp[xx+MIN_X][yy+MIN_Y] != 0 && sum < f(SPACE_INTERVAL));
        }
            
        else
            add_feature(sp,ANT,this,this->now);
        if(this->carry_food)
            this->days = 0;
    }       
}

bool Ant::add_day()
{
    if(++(this->days) == TIME_INTERVAL)
        this->lived = false;
    return this->lived;
}

bool Food::add_day()
{
    if(++this->days == TIME_INTERVAL)
        return false;
    return true;
}

bool Pheromone::add_day()
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
    Base* res;
    switch(t)
    {
        case ANT:
            res = new Ergate(Point(x+MIN_X,y+MIN_Y));
            break;
        case PHEROMONE:
            res= new Pheromone(Point(x+MIN_X,y+MIN_Y));
            break;
        case FOOD:
            res = new Food(Point(x+MIN_X,y+MIN_Y),random()%20);
            break;
        default:
            break;
    }
    space_map[res] = Point(x+MIN_X,y+MIN_Y);
}

void add_feature(Space** s,int t,Base *b,Point o)
{
    s[o.x][o.y] = t;
    if(t == ANT)
        cache[b] = o;
}

int f(int x)
{
    int sum = 0;
    for(int i = 1 ; i <= x ; i++)
        sum += i*2+1;
    return sum;
}

void delete_ant(Space** s, int x, int y)              //change space[x][y] ant into nothing
{
    if(x < MIN_X || y < MIN_Y || x > MAX_X || y > MAX_Y)
        cerr << "delete range out of bondary" << endl;
    else
        s[x][y] = 0;
}
