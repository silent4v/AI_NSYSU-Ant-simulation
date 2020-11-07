#ifndef __ANT_H__
#define __ANT_H__
#define TIME_INTERVAL 3
#include "space.h"

class Point
{
    public:
        int x,y;
        Point& operator =(Point); 
        Point();
        Point(int,int);
        void set(int,int);
        friend bool operator ==(Point,Point);
};

class Ant
{
    protected:
        bool lived;      //1 for live , 0 for dead
        bool job;        //0 for queen,1 for ergate
        int hungry_day;      //days that hungry
        Point now;    //position
    public:
        Ant();
        virtual void work(Space**) {}
};

class Ergate:public Ant
{
    private:    
        Point next_step;
        bool carry_food;
        Point sensor(Space **);      //find food,1 for food detected,0 for food-undetected
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

class Food
{
    private:
        int days,number;
        Point now;
    public:
        Food();
        Food(Point,int);
};

class Pheromone
{
    private:
        int days;
        int magnitude;  //min:0 , max:TIME_INTERVAL
        Point now;
    public:
        Pheromone();
        Pheromone(Point);
};

#endif