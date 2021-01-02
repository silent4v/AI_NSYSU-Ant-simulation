#ifndef __BASE_H__
#define __BASE_H__

#include <iostream>
#include <map>
#include <list>

#define TIME_INTERVAL 5
#define SPACE_BOUND_START 0
#define SPACE_INTERVAL 3
#define SPACE_BOUND_END 20
#define EMPTY 0
#define QUEEN 1
#define WORKER 2
#define PHEROMONE 3
#define FOOD 4
#define NEST 9

using namespace std;

typedef int Food;

class Space
{
    public:
        int field[SPACE_BOUND_END][SPACE_BOUND_END];
        Space();
        void outputField();
};

class Point
{
    public:
        int x,y;
        Point(int a,int b):x(a),y(b) {}
        Point():x(0),y(0) {}
        Point operator =(Point c)
        {
            this->x = c.x;
            this->y = c.y;
            return *this;
        }
        friend bool operator ==(Point,Point);
        friend bool operator <(Point a, Point b) 
        {
            if( a.x == b.x)
                return a.y > b.y;
            return  a.x > b.x;
        }
};

class Ant
{
    protected:
        int blood;
        string job;
        int name;
        bool carried;
        Point position;
        static int food_num;
    public:
        int get_name() {return name;}
        void add_food() { food_num ++; }
        void clear_food() { food_num = 0; }
        void minus_blood() { blood--; }
        int get_blood() {return blood;}
        virtual void work(Space&) {cout << "hello lll" << endl;}
        friend bool operator <(Ant a, Ant b) { return true; }
};



class Pheromone
{
    private:
        int density;
    public:
        int name;
        static list<Point>forDelete;
        Pheromone(int a, int b):density(a),name(b) {}
        Pheromone():density(0) {}
        int get_density() { return density; }
        void decrease_density() { density --; }
        void increase_density() { density ++; if(density > TIME_INTERVAL * 2) density = TIME_INTERVAL * 2;}
        friend bool operator <(Pheromone a, Pheromone b) { return true; }
        
};

class Worker:public Ant
{
    private:
        Point lastfood;
    public:
        static map<Point,Worker*>antPoint;
        static map<Point,Pheromone>pheromonePoint;
        static list<Point>forDelete;
        static int object_num;
        Worker();
        Point sensor(Space &);
        void put_phe();
        void move(Space &);
        void work(Space &);
};

class Queen:public Ant
{
    public:
        Queen();
        void addAnt(Space&);
        void makeLOVE(Space&);
        void work(Space&);
};

#endif