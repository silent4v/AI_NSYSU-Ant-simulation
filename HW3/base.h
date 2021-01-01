#include <iostream>
#define TIME_INTERVAL 5

using namespace std;


class Ant
{
    protected:
        int blood;
        string job;
    public:
        virtual void work();
};

class Space;

class Pheromone
{
    private:
        int density;
    public:
        int get_density() {return density;}
        void decrease_density() {density --;}
        void increase_density() {density ++; if(density > TIME_INTERVAL*2) density = TIME_INTERVAL*2;}
};

class Queen:public Ant
{
    public:
        Queen();
};

class Worker:public Ant
{
    public:
        Worker();
        bool sensor();
};