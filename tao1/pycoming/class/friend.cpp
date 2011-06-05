#include <iostream>
using namespace std;
class Point;
//////shengminglei zhi hou /////dou///zai wai mian shi xian hanshu de gong
//neng //
class B
{
public:
    Point inflate(Point &pt,int nOffset);

    //Point inflate(Point &pt,int nOffset)
    //{
    //pt.x += nOffset;
    //pt.y += nOffset;
    //}

    private:
    //Point pt;
};

class Point
{
    friend class B;
    //friend Point B::inflate(Point &pt,int nOffset);
public:
        Point(int x = 0, int y = 0)
        {
            this->x = x;
            this->y = y;

        }
        void print()
        {
            cout<<"Point("<<x<<","<<y<<")"<<endl;
        }

private:
        int x;
        int y;

};

Point B::inflate(Point &pt,int nOffset)
{
        pt.x += nOffset;
        pt.y += nOffset;
}

int main(void)
{
    Point pb(10,20);
    B pt;
    pt.inflate(pb,30);
    //inflate(pb,30);
    pb.print();
    return 0;
}
