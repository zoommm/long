#include <iostream>
using namespace std;
class Animal
{
public:
        Animal(int wg)
        {
            weight = wg;
            cout<<"animal gouzao"<<endl;
        }
        ~Animal()
        {
            cout<<"animal xigouhaoshu"<<endl;
        }
        void show_info()
        {
            cout<<"animal weight ="<<weight<<endl;
        }
        void eat()
        {
            breath();
            cout<<"animal eat"<<endl;
        }
protected:
        void sleep()
        {
            cout<<"animal sleep"<<endl;
        }
private:
        int weight;
        void breath()
        {
            cout<<"animal breath"<<endl;
        }
};

class Person:public Animal 
{
public:
    Person(int weg):Animal(weg)
    {
        weight = weg;
        cout<<"person gouzao"<<endl;
    }
    ~Person()
    {
        cout<<"person xigouzao"<<endl;
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
    void eat()
    {
        Animal::eat();
        cout<<"person eat"<<endl;
    }
private:
        int weight;

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
/*
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
*/
int main(void)
{
     Animal an(34);

     an.show_info();
    //an.breath();
     Person p(33);
     p.show_info();
     p.eat();
     //Human man;
     //man.playy();
    //p.test();
    //p.walk();


    return 0;
}
