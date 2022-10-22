#include <iostream>
#include "Vetor.cpp"
#include "Vetor.h"

using namespace std;

int main()
{

    int tam = 60;
    Vetor v(tam); // aloca vet[60]

    for(int i=0; i<tam; i++) // armazena seq
        v.set(i, i+1); // de 1 a 60

    for(int i=0; i<tam; i++)
    {
        float val = v.get(i) ;
        cout << val << endl;
    }
    return 0;
}