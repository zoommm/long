#include <iostream>
using namespace std;
class Complex;
class B
{
Complex operator +(Complex &c);
Complex operator +(double c);
};
class Complex
{
public:
        Complex(double r = 0, double i = 0)
        {
            real = r;
            img  = i;
        }
        void print()
        {
            cout<<"real = "<<real<<" img = "<<img<<endl;
        }
        Complex operator +(Complex &c);
        Complex operator +(double  x);
private:
        double real;
        double img;

};
/*
Complex Complex::operator +(Complex &c)
{
    Complex temp;
    temp.real = real+c.real;
    temp.img =img+c.img;
    return temp;
}
*/
/*
Complex Complex::operator +(double x)
{
    Complex temp;
    temp.real = real+x;
    temp.img = img;
    return temp;
}
*/
Complex B::operator +(Complex &c)
{
    Complex temp;
    temp.real = real+c.real;
    temp.img =img+c.img;
    return temp;
}

Complex B::operator +(double x)
{
    Complex temp;
    temp.real = real+x;
    temp.img = img;
    return temp;
}
int main(void)
{
    Complex c1(12,20),c2(23,12),c;
    //c = c1 + c2;
    c.print();
    //c = c1 + 20;
    c.print();
    B b1;
    b1 = c1 + c2;
    c.print();
    b1 = c1 + 20;
    c.prnt();
    return 0;
}

