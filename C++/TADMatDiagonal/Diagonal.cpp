#include <iostream>
#include <stdlib.h>
#include "Diagonal.h"

using namespace std;

Diagonal::Diagonal(int nn)
{
    //ctor
    n = nn;
    vet = new float[n];
}

Diagonal::~Diagonal()
{
    //dtor
    delete [] vet;
}

bool Diagonal::verifica(int i, int j)
{
    return i>=0 && i<n && j>=0 && j<n;
}

int Diagonal::detInd(int i, int j)
{
    int k;
    if(verifica(i,j))
    {
        if(i == j)
            k = i;  ///k=j, valor de k corresponde a(i,j) != 0
        else
            k = -1;  ///fora da diagonal principal; a(i,j) == 0
    }
    else
        k = -2; ///indice fora do intervalo

    return k;
}

float Diagonal::get(int i, int j)
{
    int k = detInd(i, j);
    if(k != -2)
    {
        if(k != -1)
            return vet[k];
        else
            return 0.0;
    }
    else
    {
        cout<<"Indices invalidos: get()"<<endl;
        exit(1);
    }
}

void Diagonal::set(int i, int j, float valor)
{
    int k = detInd(i, j);
    if(k != -2)
    {
        if(k != -1)
        {
            vet[k] = valor;
        }
        else if(valor != 0)
            cout<<"Valor invalido. Deveria ser 0";
    }
    else
    {
        cout<<"Indices invalidos: set()"<<endl;
        exit(1);
    }
}

void Diagonal::imprime()
{
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<get(i, j)<<"\t";
        cout<<endl;
    }
}
