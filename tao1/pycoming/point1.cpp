#include <iostream>

using namespace std;

typedef struct point
{
    int x;
    int y;
    void show_point()
    {
        cout<<"pt.x="<<x<<endl<<"pt.y="<<y<<endl;
    }
}POINT;

int main(void)
{
    POINT pt;
    pt.x = 9;
    pt.y = 5;
    //cout<<"pt.x="<<pt.x<<endl<<"pt.y="<<pt.y<<endl;
    pt.show_point();
    return 0;
}
