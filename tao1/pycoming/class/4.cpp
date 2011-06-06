#include <iostream>
using namespace std;
template <class T, class P,int zz>
P sum(T x,P y)
{
    return x + y+zz;
}

int main(void)
{
    //cout<<"sum(2,'a')="<<sum(2,'a')<<endl;
    //cout<<"sum(2,3)="<<sum(2,3)<<endl;
    //cout<<"sum('a',2)="<<sum('a',2)<<endl;
    cout<<"sum(2,'a')="<<sum<int,char,10>(2,'a')<<endl;
    cout<<"sum(2,3)="<<sum<int,int,20>(2,3)<<endl;
    cout<<"sum('a',2)="<<sum<char,int,10>('a',2)<<endl;
    return 0;
}
