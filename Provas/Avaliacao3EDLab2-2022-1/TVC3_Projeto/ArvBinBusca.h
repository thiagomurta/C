#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
public:
    ArvBinBusca(){ raiz = NULL; }

    void insere(int val){raiz = auxInsere (raiz, val);}

    void imprime();

    //Q1
    void contaElegante();
    //Q2
    int somaIntervalo(int a, int b);
    //Q3
    void removeNo(int val);

private:
    NoArv* raiz; // ponteiro para o No raiz da árvore


    NoArv* auxInsere(NoArv *p, int val);
    void imprimeEmOrdem(NoArv* p);
    bool ehFolha(NoArv* p);
};

#endif // ARVBINBUSCA_H_INCLUDED
