#include <iostream>
#include "MatrizTriangSup.h"

MatrizTriangSup::MatrizTriangSup(int ordem)
{
    //ctor
    n = ordem;
    int tam = n*(n + 1)/2;
    vet = new float[tam];
}

MatrizTriangSup::~MatrizTriangSup()
{
    //dtor
    delete [] vet;
}

bool MatrizTriangSup::verifica(int i, int j)
{
    if(i >= 0 && i < n && j >= 0 && j < n)
        return true;
    else
        return false;
};

int MatrizTriangSup::detInd(int i, int j)
{
    if(verifica(i,j))
    {
        if(i<=j)
            return j*(j + 1)/2 + i;
        else
            return -1;
    }
    else
        return -2;

}

float MatrizTriangSup::get(int i, int j)
{
    int k = detInd(i,j);
    if(k != -2)
    {
        if(k != -1)
            return vet[k];
        else
            return 0.0;
    }
    else
        std::cout << "Erro: indice invalido\n";
}

void MatrizTriangSup::set(int i, int j, float valor)
{
    int k = detInd(i,j);
    if(k != -2)
    {
        if(k != -1)
            vet[k] = valor;
    }
    else
        std::cout << "Erro: indice invalido\n";
}
