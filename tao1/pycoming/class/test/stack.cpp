#include "stack.h"
int main()
{
    Stack<int> intstack1,intstack2;
    int val;
    for (val = 0; val < 4; ++val) 
    {
        intstack1.push(val);
        intstack2.push(2*val);
    }
    while(intstack1.count())
    {
        val = intstack1.pop();
        cout<<val<<endl;
    }
    Stack<char>stringstack;
    stringstack.push('A');
    stringstack.push('B');
    stringstack.push('C');
    char val2;
    while(stringstack.count())
    {
        val2 = stringstack.pop();
        cout<<val2<<endl;
    }
    cout<<"NOW instack2 will self destruct ."<<endl;
    return 0;
}
