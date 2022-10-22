#include <iostream>
#include <cstdlib>
#include "ListaEncad.h"

using namespace std;

ListaEncad::ListaEncad ()
{
    primeiro = NULL;
}

ListaEncad::~ListaEncad ()
{
    // OMITIDO
}

void ListaEncad::insereInicio(int val)
{
    No *novo = new No ();
    novo->setInfo (val);
    novo->setProx (primeiro);
    primeiro = novo;
}

void ListaEncad::imprime ()
{
    cout << "[";
    for (No *p = primeiro; p != NULL; p = p->getProx ())
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
//Q4

void ListaEncad::removeBloco(int a, int b)
{
    // Implemente aqui a sua solução para a questão 4.
    No* p = primeiro;
    No* ant = NULL;
    No* aux = NULL;
    int indCom, indTerm;
    for(int i = a; i <= b;i++){
        if(p->getInfo() == a){
            ant = p;
            indCom = i;
        }
        if(p->getInfo() == b){
            aux = p;
            indTerm = i;
            break;
        }
        p = p->getProx();
    }
    /// deletar termos
    p = ant;
    for (int i = indCom; i < indTerm || p != NULL; i++)
    {
        delete p;
        p = p->getProx();
    }
}

//-Q4
// ----------------------------------------------------------------------------
