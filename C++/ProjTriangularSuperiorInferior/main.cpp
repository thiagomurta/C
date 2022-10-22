#include <iostream>
#include "matriztriinf.h"
#include "MatrizTriangSup.h"

using namespace std;

int main()
{
    MatrizTriangSup mat(9);

    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            mat.set(i,j,i+j+10);


    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
            cout<<"\t"<<mat.get(i,j);
        cout<<endl;
    }

    return 0;
}
