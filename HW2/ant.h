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
};

class Queen:public Ant
{
    public:
        void work();
};

#endif