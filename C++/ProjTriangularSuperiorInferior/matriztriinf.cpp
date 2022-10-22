#include <iostream>
#include "matriztriinf.h"

MatrizTriInf::MatrizTriInf(int ordem)
{
    //ctor
    n = ordem;
    int tam = n*(n + 1)/2;
    vet = new float[tam];
}

MatrizTriInf::~MatrizTriInf()
{
    //dtor
    delete [] vet;
}

bool MatrizTriInf::verifica(int i, int j)
{
    if(i >= 0 && i < n && j >= 0 && j < n)
        return true;
    else
        return false;
};

float MatrizTriInf::get(int i, int j)
{
    if(verifica(i, j ))
    {
        if(i >= j)
        {
            int k = i*(i + 1)/2 + j;
            return vet[k];
        }
        else
            return 0.0;
    }
    else
        std::cout << "Erro: indice invalido\n";
    exit(1);
}

void MatrizTriInf::set(int i, int j, float valor)
{
    if(verifica(i, j) )
    {
        if(i >= j)
        {
            int k = i*(i + 1)/2 + j;
            vet[k] = valor;
        }
        else if(valor != 0.0)
            std::cout << "Elemento fora da parte "
                 << "triangular inferior\n";
    }
    else
        std::cout << "Erro: indices invalidos\n";
}
