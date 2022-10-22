#include <iostream>
#include "MatAlternada.h"
#include "MatAlternada.cpp"

using namespace std;

int main()
{
    int n=11;
    MatAlternada mat(n);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            mat.set(i,j,i+j-10);


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout << "\t" << mat.get(i,j);
        cout << endl;
    }
    return 0;
}
