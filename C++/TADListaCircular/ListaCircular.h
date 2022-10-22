#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include "NoDuplo.h"

class ListaCircular
{
    public:
    ListaCircular();
    void imprime();
    void insereFinal(int val);
    NoDuplo* insereNoAntes(NoDuplo *p, int val);

    bool vazia(){return n==0;}
private:
    NoDuplo *primeiro;
    int n;
    NoDuplo *ultimo;
};

#endif // LISTACIRCULAR_H
