#include <iostream>
#include "ListaCircular.h"

ListaCircular::ListaCircular()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

NoDuplo* ListaCircular::insereNoAntes(NoDuplo *p, int val)
{
    NoDuplo* novo = new NoDuplo();
    novo->setInfo(val);
    if(primeiro == NULL){ // lista vazia
        novo->setProx(novo);
        novo->setAnt(novo);
        primeiro = ultimo = novo;
    }
    else{
        NoDuplo* ant = p->getAnt();
        novo->setAnt(ant);
        novo->setProx(p);
        ant->setProx(novo);
        p->setAnt(novo);
        if(p == primeiro){
            primeiro = novo;
        }
    }
    n++;
    return novo;
}

void ListaCircular::insereFinal(int val)
{
    primeiro = insereNoAntes(primeiro, val);
}

void ListaCircular::imprime()
{
    std::cout << "Lista: ";
    int i=0;
    NoDuplo *p = primeiro;
    while(i<n)
    {
        std::cout << p->getInfo() << " ";
        p = p->getProx();
        i++;
    }
    std::cout << std::endl;
}