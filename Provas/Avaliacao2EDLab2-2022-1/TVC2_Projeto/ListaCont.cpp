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
    delete [] vet;
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
    cout << "]";
}

void ListaCont::limpar()
{
    n = 0;
}

// ----------------------------------------------------------------------------
//Q1
bool ListaCont::insereValores(int k, int tam, int v[])
{
    // Implemente aqui a sua solução para a questão 1.
    // Se necessário, remova o código abaixo.
    return false;
}
//-Q1
// ----------------------------------------------------------------------------
