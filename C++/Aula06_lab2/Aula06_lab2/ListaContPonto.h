#ifndef LISTACONT_H_INCLUDED
#define LISTACONT_H_INCLUDED
#include "Ponto.h"

class ListaCont
{
private:
    int max;
    int n;
    Ponto *vet;

public:
    ListaCont(int tam);
    ~ListaCont();

    Ponto get(int k);
    void set(int k, Ponto p);
    void insereFinal(Ponto p);
    void insereK(int k, Ponto p);
    void insereInicio(Ponto p);
    void removeFinal();
    void removeK(int k);
    void removeInicio();
    void imprime();
    int numNos();    
};

#endif // LISTACONT_H_INCLUDED
