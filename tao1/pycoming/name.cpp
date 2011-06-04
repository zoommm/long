#include <iostream>
#include <cstring>
//////////2/////////
//using namespace std;

namespace my
{
    char name[]="wangjianli";
    void show_name()
    {
       /////////////2/////
       std::cout<<name<<endl;
       //cout<<name<<endl;
    }
}
namespace your
{
    char name[]="pycoming";
    void show_name()
    {
        //////////2//////////
        std::cout<<name<<endl;
        //cout<<name<<endl;
    }
}
////1/////////
using namespace my;
int main(void)
{
    ////1///////
    //my::show_name();
    show_name();
    strcpy(my::name,"zhangsan");
    your::show_name();
    ////1///////
    //my::show_name();
    show_name();
    return 0;
}
