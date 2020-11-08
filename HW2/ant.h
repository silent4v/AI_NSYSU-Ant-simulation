#ifndef __ANT_H__
#define __ANT_H__
#include "space.h"

class Ant:public Base
{
    protected:
        bool lived;      //1 for live , 0 for dead
        bool job;        //0 for queen,1 for ergate
    public:
        bool add_day();
        Ant();
        void work(Space**) {}
};

class Ergate:public Ant
{
    private:    
        Point next_step;            //next position
        bool carry_food;            //true for carry food , 0 for not
        Point sensor(Space **);      //return next position
    public:
        void work(Space **);
        Ergate();
        Ergate(Point);
};

class Queen:public Ant  
{
    public:
        void work(Space**) {}

        Queen();
        Queen(Point);
};

class Food:public Base
{
    private:
        int number;    
    public:
        bool add_day();
        void work(Space **) {}
        Food();
        Food(Point,int);    //point:position int:number
};

class Pheromone:public Base
{
    private:
        int magnitude;  //min:0 , max:TIME_INTERVAL
    public:
        bool add_day();
        void work(Space **) {}
        Pheromone();
        Pheromone(Point);
};

int f(int);
#endif