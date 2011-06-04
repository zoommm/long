#include <iostream>
using namespace std;
void swap(int &x,int &y)
{
    int tem;
    tem = x;
    x = y;
    y = tem;
}
int main()
{
    int i = 3,j = 4;
    swap(i,j);
    cout<<"i = "<<i<<endl<<"j = "<<j<<endl;
}
