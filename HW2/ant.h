#ifndef __ANT_H__
#define __ANT_H__
#define TIME_INTERVAL 3

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
        virtual void work() {}
};

class Ergate:public Ant
{
    private:    
        Point next_step;
        Point sensor();      //find food,1 for food detected,0 for food-undetected
    public:
        void work();
        Ergate();
        Ergate(Point);
};

class Queen:public Ant  
{
    public:
        void work() {}
        //bool can_new();
        Queen();
        Queen(Point);
};

class Food
{
    private:
        int days;
        Point now;
    public:
        Food();
        Food(Point);
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