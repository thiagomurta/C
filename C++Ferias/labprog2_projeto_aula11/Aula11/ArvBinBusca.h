#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    bool vazia(); // verifica se a �rvore est� vazia
    bool busca(int val);
    void insere(int val);
    void remove(int val);
    void imprime();
    float mediaCaminho(int ch);
    void remove1Filho(int val);
    NoArv* tem1Filho(NoArv *p);
    int contaNos();
    bool eABB();
    void imprimeFilhos(int x);
    void imprimeIntervalo(int x, int y);
    void imprimeCrescente();
    void imprimeDecrescente();
    NoArv* buscaValor(int val);
    int nos1Filho();
    int nos2Filho();
    int classificaNo(int val);
    void insereDoVetor(int n, int *vet);
    int* insereVetorCrescente();
    int* insereNoVetDecrescente();

private:
    NoArv* raiz; // ponteiro para o No raiz da �rvore
    bool auxBusca(NoArv *p, int val);
    NoArv* auxInsere(NoArv *p, int val);
    NoArv* auxRemove(NoArv *p, int val);
    NoArv* menorSubArvDireita(NoArv *p);
    NoArv* removeFolha(NoArv *p);
    NoArv* remove1Filho(NoArv *p);
    void imprimePorNivel(NoArv* p, int nivel);
    NoArv* libera(NoArv *p);
    ///////
    bool auxEABB(NoArv *p);
    void auxImprimeFilhos(NoArv *p, int x);
    void auxImprimeIntervalo(NoArv *p, int x, int y);
    void auxImprimeCrescente(NoArv *p);
    void auxImprimeDecrescente(NoArv *p);
    int auxContaNos(NoArv *p);
    NoArv* auxBuscaValor(NoArv *p, int val);
    int auxNos1Filho(NoArv *p);
    int auxNos2Filho(NoArv *p);
    int auxClassificaNo(NoArv *p, int val);
    void auxInsereDoVetor(NoArv *p, int n, int *vet);
    int* auxInsereVetorCrescente(NoArv *p, int *vet, int i);
    int* auxInsereNoVetDecrescente(NoArv *p);
};

#endif // ARVBINBUSCA_H_INCLUDED
