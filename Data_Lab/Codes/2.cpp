#include <iostream>

using namespace std;

int main ()
{
    int x = 10;
    int y =12;
    int *p1 =&x;
    const int * p2 =&x;
    int *const p3 = &x;
    const int *const p4 = &x;

    *p1 = 10;
    *p2 = 12;
    p3 = &y;
    *p4 = 14;
    
    return 0;
}

