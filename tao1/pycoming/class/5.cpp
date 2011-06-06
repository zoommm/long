#include <iostream>
using namespace std;

template <typename T,typename P>
class Csum
{
public:
        Csum()
        {ret = 0;}
        ~Csum()
        {}
        void show(void)
        {
            cout<<"ret = "<<ret<<endl;
        }
        void sum(T x,P y)
        {
            ret = x + y; 
        }
        void sum(T x,T y)
        {
            ret = x + y;
        }
        void sum(P x,P y);
            //{
            //ret = x + y;
            //}
private:
        T ret;
};
template <class S,class R>
void Csum<S,R>::sum(R x,R y)
{
    ret = x + y;
}
int main(void)
{
   
    Csum<char,double>one;
    one.sum(2,'a');
    one.show();
    Csum<int,double>two;
    two.sum(5,5);
    two.show();
    return 0;
}

