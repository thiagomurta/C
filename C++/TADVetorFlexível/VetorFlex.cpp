#include <iostream>
#include <stdlib.h>

#include "VetorFlex.h"

// construtor
VetorFlex::VetorFlex(int cc, int ff)
{
    if(cc>ff)
    {
        int aux = cc;
        cc = ff;
        ff = aux;
    }
    c = cc;
    f = ff;
    n = f - c + 1;
    vet = new float[n];

}
// destrutor
VetorFlex::~VetorFlex()
{
    delete [] vet;
}

int VetorFlex::detInd(int indice)
{
    if(c <= indice && indice <= f)
        return (indice - c);
    else
        return -1;
}

float VetorFlex::get(int indice)
{
    int i = detInd(indice);
    if(i != -1)
        return vet[i];
    else
    {
        std::cout << "Indice invalido: get\n";
        exit(1);
    }
}
void VetorFlex::set(int indice, float val)
{
    int i = detInd(indice);
    if(i != -1)
        vet[i] = val;
    else
    {
        std::cout << "Indice invalido: set\n";
        exit(1);
    }
}
