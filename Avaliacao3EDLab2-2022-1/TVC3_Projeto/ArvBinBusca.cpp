#include <iostream>
#include <cmath>
#include "ArvBinBusca.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q1
void ArvBinBusca::contaElegante()
{
    // Implemente aqui a sua solução para a questão 1.
    int k = 0;
    int f = 0;
    auxContaElegante(raiz, &k, &f);
    cout << "Quantidade de Nós pares: " << k << endl;
    cout << "Quantidade de Nós folhas não negativas: " << f << endl;
}

void ArvBinBusca::auxContaElegante(NoArv *p, int *k, int *f){
    if(p != NULL){
        if(p->getDir() == NULL && p->getEsq() == NULL){
            if(p->getInfo() >= 0){
                (*f)++;
            }
        }
        if(p->getInfo() % 2 == 0)
            (*k)++;
        
        auxContaElegante(p->getEsq(), k, f);
        auxContaElegante(p->getDir(), k, f);
    }
}
//-Q1

// ----------------------------------------------------------------------------

// ------------------------------------------------------------------------
//Q2
int ArvBinBusca::somaIntervalo(int a, int b)
{
    // Implemente aqui a sua solução para a questão 2
    // Se necessário, remova o código abaixo.
    return auxSomaIntervalo(raiz, a, b);
}

int ArvBinBusca::auxSomaIntervalo(NoArv *p, int a, int b){
    if(p != NULL){
        if(p->getInfo() >= a && p->getInfo() <= b){
            return p->getInfo() + auxSomaIntervalo(p->getEsq(), a, b) + auxSomaIntervalo(p->getDir(), a, b);
        }
        return auxSomaIntervalo(p->getEsq(),a,b) + auxSomaIntervalo(p->getDir(),a,b);
    }
    return 0;
}
//-Q2
// ------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//Q3
void ArvBinBusca::removeNo(int val)
{
    // Implemente aqui a sua solução para a questão 3.
    NoArv* ant = NULL;
    auxRemoveNo(raiz, ant, val);
}

void ArvBinBusca::auxRemoveNo(NoArv *p, NoArv *ant, int val){
    while(p != NULL){
        if(p->getInfo() < val){
            ant = p;
            p = p->getDir();
        }
        else if(p->getInfo() > val){
            ant = p;
            p = p->getEsq();
        }
        else{
            if(p->getDir() == NULL && p->getEsq() == NULL){
                if(ant->getEsq() == p){
                    delete p;
                    ant->setEsq(NULL);
                }
                else{
                    delete p;
                    ant->setDir(NULL);
                }
                p = NULL;
            }
            else{
                cout << "Não foi possível deletar " << val << ", pois o nó não é folha!!!" << endl;
                break;
            }
        }
    }
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
