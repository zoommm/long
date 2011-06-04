#include <iostream>

using namespace std;

int add(int x,int y)
{
    return x+y;
}

double add(double x, double y)
{
    return x+y;
}

int main(void)
{
    cout<<add(1,2)<<endl<<add(2.1,3.14)<<endl;    
    return 0;
}
