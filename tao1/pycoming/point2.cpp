#include <iostream>

using namespace std;

//typedef struct point
class Point
{
public:
/*
    void set_x(int m)
    {
        x = m;
    }
    void set_y(int n)
    {
        if (n < 240) 
        {
            y = n;
        }
        else
        {
             y = 0;
        }
    }
    */
/*
    void init(int a,int b)
    {
        x = a;
        y = b;
    }
    */
    Point(int x, int y)
    {this->x = x,this->y = y;}
    Point()
    {x = 0,y = 0;}
    ~Point()
    {}
    void show_Point()
    {
        cout<<"pt.x="<<x<<endl<<"pt.y="<<y<<endl;
    }
private:

        int x;
        int y;
};

int main(void)
{
    Point pt(1,2);
    //pt.x = 9;
    //pt.y = 5;
    //cout<<"pt.x="<<pt.x<<endl<<"pt.y="<<pt.y<<endl;
    //pt.set_x(9);
    //pt.set_y(241);
    //pt.init(5,9);
    pt.show_Point();
    return 0;
}
