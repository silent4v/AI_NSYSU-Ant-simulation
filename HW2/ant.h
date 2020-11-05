#ifndef __ANT_H__
#define __ANT_H__

class Ant
{
    protected:
        bool lived;      //1 for live , 0 for dead;
        bool job;        //0 for queen,1 for ergate,
        int hungry_day;      //days that hungry
    public:
        virtual void work();
};

class Ergate:public Ant
{
    public:
        void work();
        Ergate();
};

class Queen:public Ant
{
    public:
        void work();
        bool can_new();
        Queen();
};

class Food
{
    private:
        int days;
    public:
        Food();
};

class Pheromone
{
    private:
        int days;
        int magnitude;  //min:0 , max:TIME_INTERVAL
    public:
        Pheromone();
};

#endif