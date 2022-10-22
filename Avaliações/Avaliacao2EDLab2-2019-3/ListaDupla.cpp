#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla ()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla ()
{
    // OMITIDO
}

void ListaDupla::insereInicio (int val)
{
    NoDuplo *p = new NoDuplo ();
    p->setInfo (val);
    p->setProx (primeiro);
    p->setAnt (NULL);

    if (n == 0)
    {
        ultimo = p;
    }
    else
    {
        primeiro->setAnt (p);
    }
    primeiro = p;
    n = n + 1;
}

void ListaDupla::imprime ()
{
    cout << "[";
    for (NoDuplo *p = primeiro; p != NULL; p = p->getProx ())
    {
        cout << p->getInfo ();
        if (p->getProx () != NULL)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// ----------------------------------------------------------------------------
//Q3

void ListaDupla::removeMaior()
{
    // Implemente aqui a sua solução para a questão 3.
    int indMaior = 0;
    NoDuplo* p = primeiro;
    NoDuplo* ant;
    NoDuplo* aux;
    if(primeiro == NULL){
        exit(1);
    }
    int maior = p->getInfo();
    for(int i = 1; i < n; i++){
        if(p->getInfo() > maior){
            maior = p->getInfo();
            ant = aux;
            aux = p;
            indMaior = i;
        }
        p = p->getProx();
    }
    ant->setProx(p->getProx()->getProx());
    delete aux;
    delete p;
    p = ant;
    n--;
}

//-Q3
// ----------------------------------------------------------------------------
