#include <iostream>
#include <cstdlib>
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont (int tam)
{
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaCont::~ListaCont ()
{
    // OMITIDO
}

void ListaCont::insereFinal (int val)
{
    if (n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit (1);
    }
    vet[n] = val;
    n = n + 1;
}

void ListaCont::imprime ()
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << vet[i];
        if (i + 1 < n)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// ----------------------------------------------------------------------------
//Q2

bool ListaCont::insereIntervalo(int a, int b)
{
    int intervalo = b - a;
    int antMax = max;
    int novoMax;
    if(intervalo > n){
        novoMax = max + (intervalo-n);
    }
    else
        novoMax = max + (n-intervalo);
    if(intervalo > max-n){
        max = novoMax;
    }
    // alocacao
    for(int i = n; a <= b; i++){
        this->vet[i] = a;
        a++;
    }
    n += intervalo+1;
    if(max > antMax){
        return true;
    }
    else{
        return false;
    }
}
//-Q2
// ----------------------------------------------------------------------------
