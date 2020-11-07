#ifndef __ANT_H__
#define __ANT_H__
#define TIME_INTERVAL 3

class Ant
{
    protected:
        bool lived;      //1 for live , 0 for dead
        bool job;        //0 for queen,1 for ergate
        int hungry_day;      //days that hungry
        int x , y;    //position
    public:
        Ant();
        virtual void work() {}
};

class Ergate:public Ant
{
    private:    
        bool food_detect;
        bool sensor();      //find food,1 for food detected,0 for food-undetected
    public:
        void work() {}
        Ergate();
        Ergate(int,int);
};

class Queen:public Ant  
{
    public:
        void work() {}
        //bool can_new();
        Queen();
        Queen(int,int);
};

class Food
{
    private:
        int days;
        int x,y;
    public:
        Food();
        Food(int,int);
};

class Pheromone
{
    private:
        int days;
        int magnitude;  //min:0 , max:TIME_INTERVAL
        int x,y;
    public:
        Pheromone();
        Pheromone(int,int);
};

#endif