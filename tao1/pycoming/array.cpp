#include <iostream>
using namespace std;
int main()
{
    int i,n,sum = 0;
    cout<<"input a array:"<<endl;
    cin>>n;
    int *p = new int [n];
    if (!p) 
    {
        return 1;
    }
    cout<<"input"<<n<<endl<<"array:"<<endl;
    for (i = 0; i < n; i++) 
    {
        cin>>p[i];
    }
    for (i = 0; i < n; i++) 
    {
        sum += p[i];
    }
    cout<<endl;
    cout<<"restlut:"<<endl<<sum<<endl;
    delete []p;
    return 0;
}

