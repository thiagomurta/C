#include <iostream>
#include  "VetorFlex.cpp"
#include "VetorFlex.h"
using namespace std;

int main ( )
{
    int cc = -29;
    int ff = 30 ;

    VetorFlex v(cc, ff) ;
    for (int i = cc; i<=ff; i++)
    {
        // valor e s no int e r v a l o 1 . . . 6 0
        double val = i - cc + 1;
        v.set(i, val);
    }

    for (int i=cc; i<=ff; i++)
    {
        double val = v.get(i);
        cout << val << endl;
    }
    return 0;
}
