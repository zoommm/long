#include <iostream>
#include <cstring>
using namespace std;
class Person
{
public:
        Person()
        {
            name = NULL;
            age = NULL;
        }
        Person(char *str,int a)
        {
            age = a ; 
            name = new char[strlen(str)+1];
            //name = str;
            strcpy(name,str);
        }
        Person(Person &x)
        {
            this->name = new char[strlen(x.name)+1];
            strcpy(this->name,x.name);
            //this->age = x.age;
            age = x.age;
        }
        ~Person()
        {
            if(name)
            {
                delete []name;
//////////delete////zhihou///yao zhi kong ////==NULL///
                name = NULL;
            }

        }
        char *get_Name()
        {
            return name; 
        }
        int get_Age()
        {
            return age;
        }
private:
        char *name;
        int age;

};
int main(void)
{   
    int a = 15;
    char *p = new char[12];
    strcpy(p,"pycoming");
    Person one(p,a);
    Person two(one);
    Person three;
    //Person three(one);
    //three = one;
    //cout<<one.get_Name()<<endl;
    //cout<<one.get_Age()<<endl;
    cout<<two.get_Name()<<endl;
    cout<<two.get_Age()<<endl;
    delete []p;
    p = NULL;
    //cout<<three.get_Name()<<endl;
    //cout<<three.get_Age()<<endl;

    return 0;
}
