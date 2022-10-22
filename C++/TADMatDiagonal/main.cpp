#include <iostream>
#include "Diagonal.cpp"
#include "Diagonal.h"

using namespace std;

int main()
{
    int x = 10;
    Diagonal m(x);

    for(int i=0; i<x; i++)
        m.set(i, i, i*i + x);

    m.imprime();
    return 0;
}
