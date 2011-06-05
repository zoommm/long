#include <iostream>
#include <cstring>
using namespace std;
class Person
{
public:
        Person()
        {
            name = NULL;
        }
        Person(char *str)
        {
            name = new char[strlen(str)+1];
            //name = str;
            strcpy(name,str);
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
private:
        char *name;

};
int main(void)
{   
    char *p = new char[12];
    strcpy(p,"pycoming");
    Person one(p);
    //cout<<one.get_Name()<<endl;
    delete []p;
    p = NULL;
    cout<<one.get_Name()<<endl;

    return 0;
}
