#include <iostream>
#include <cmath>
#include "ArvBinBusca.h"

using namespace std;


// ----------------------------------------------------------------------------
//Q1
void ArvBinBusca::contaElegante()
{
    // Implemente aqui a sua solução para a questão 1.
}
//-Q1

// ----------------------------------------------------------------------------

// ------------------------------------------------------------------------
//Q2
int ArvBinBusca::somaIntervalo(int a, int b)
{
    // Implemente aqui a sua solução para a questão 2
    // Se necessário, remova o código abaixo.
    return 0;
}
//-Q2
// ------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//Q3
void ArvBinBusca::removeNo(int val)
{
    // Implemente aqui a sua solução para a questão 3.
}
//-Q3
// ----------------------------------------------------------------------------


NoArv* ArvBinBusca::auxInsere (NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv ();
        p->setInfo (val);
        p->setEsq (NULL);
        p->setDir (NULL);
    }
    else if (val < p->getInfo ())
        p->setEsq (auxInsere (p->getEsq (), val));
    else
        p->setDir (auxInsere (p->getDir (), val));
    return p;
}

void ArvBinBusca::imprime()
{
    cout << "ABB em ordem: ";
    imprimeEmOrdem (raiz);
    cout << endl;
}

void ArvBinBusca::imprimeEmOrdem (NoArv *p)
{
    if (p != NULL)
    {
        imprimeEmOrdem (p->getEsq ());
        cout << p->getInfo () << " ";
        imprimeEmOrdem (p->getDir ());
    }
}
