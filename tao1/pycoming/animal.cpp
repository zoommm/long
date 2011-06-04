#include <iostream>
using namespace std;
class Animal
{
public:
        Animal()
        {
            cout<<"animal gouzao"<<endl;
        }
        void eat()
        {
            cout<<"animal eat"<<endl;
        }
protected:
        void sleep()
        {
            cout<<"animal sleep"<<endl;
        }
private:
        void breath()
        {
            cout<<"animal breath"<<endl;
        }
};

class Person:public Animal 
{
public:
    Person()
    {
        cout<<"person gouzao"<<endl;
    }
    void walk()
    {
        cout<<"person walk"<<endl;
    }
    void test()
    {
        //sleep();
        //breath();
    }

#if 0
public:
        void eat()
        {
            cout<<"Person eat"<<endl;
        }
        void sleep()
        {
            cout<<"Person sleep"<<endl;
        }
        void breath()
        {
            cout<<"Person breath"<<endl;
        }
#endif
};
class Human:protected Animal
{
public:
        void playy()
        {
            test1();
            cout<<"human play"<<endl;
        }
protected:
        void test1()
        {
            sleep();
        }

};

int main(void)
{
    //Animal an;
    //an.breath();
     Person p;
     //Human man;
     //man.playy();
    //p.test();
    //p.walk();


    return 0;
}
