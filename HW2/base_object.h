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

class Base
{
    protected:
        int days;
        Point now;
    public:
        virtual void add_day() {}
};