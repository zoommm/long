#include <stdio.h>

int main(int argc, const char *argv[])
{
    const char* p = "12345";
    const char**q = &p;
    *q = "abcde";
    const char*s = ++p;
    p = "XYZWVU";
    printf("%c\n",*++s);
    return 0;

}
