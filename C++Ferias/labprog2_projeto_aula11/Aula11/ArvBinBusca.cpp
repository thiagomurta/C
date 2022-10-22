#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}

void ArvBinBusca::insere(int val)
{
    raiz = auxInsere(raiz, val);
}

NoArv* ArvBinBusca::auxInsere(NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else
        p->setDir(auxInsere(p->getDir(), val));
    return p;
}

bool ArvBinBusca::busca(int val)
{
    return auxBusca(raiz, val);
}

bool ArvBinBusca::auxBusca(NoArv *p, int val)
{
    if(p == NULL)
        return false;
    else if(p->getInfo() == val)
        return true;
    else if(val < p->getInfo())
        return auxBusca(p->getEsq(), val);
    else
        return auxBusca(p->getDir(), val);
}

void ArvBinBusca::remove(int val)
{
    raiz = auxRemove(raiz, val);
}

NoArv* ArvBinBusca::auxRemove(NoArv *p, int val)
{
    if(p == NULL)
        return NULL;
    else if(val < p->getInfo())
        p->setEsq(auxRemove(p->getEsq(), val));
    else if(val > p->getInfo())
        p->setDir(auxRemove(p->getDir(), val));
    else
    {
        if(p->getEsq() == NULL && p->getDir() == NULL)
            p = removeFolha(p);
        else if((p->getEsq() == NULL) || (p->getDir() == NULL))
            p = remove1Filho(p);
        else
        {
            NoArv *aux = menorSubArvDireita(p);
            int tmp = aux->getInfo();
            p->setInfo(tmp);
            aux->setInfo(val);
            p->setDir(auxRemove(p->getDir(), val));
        }
    }
    return p;
}

NoArv* ArvBinBusca::removeFolha(NoArv *p)
{
    delete p;
    return NULL;
}

NoArv* ArvBinBusca::remove1Filho(NoArv *p)
{
    NoArv *aux;
    if(p->getEsq() == NULL)
        aux = p->getDir();
    else
        aux = p->getEsq();
    delete p;
    return aux;
}

NoArv* ArvBinBusca::menorSubArvDireita(NoArv *p)
{
    NoArv *aux = p->getDir();
    while(aux->getEsq() != NULL)
        aux = aux->getEsq();
    return aux;
}

void ArvBinBusca::imprime()
{
    imprimePorNivel(raiz, 0);
}

void ArvBinBusca::imprimePorNivel(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ")";
        for(int i = 1; i <= nivel; i++)
            cout << "--";
        cout << p->getInfo() << endl;
        imprimePorNivel(p->getEsq(), nivel+1);
        imprimePorNivel(p->getDir(), nivel+1);
    }
}

ArvBinBusca::~ArvBinBusca()
{
    raiz = libera(raiz);
}

NoArv* ArvBinBusca::libera(NoArv *p)
{
    if(p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return p;
}

float ArvBinBusca::mediaCaminho(int ch)
{
    int soma = 0, cont = 0;
    NoArv *p = raiz;
    while(p != NULL)
    {
        cont++;
        soma += p->getInfo();
        if(ch == p->getInfo())
            break;
        else if(ch > p->getInfo())
            p = p->getDir();
        else
            p = p->getEsq();
    }
    return (float)soma/cont;
}

///////////////////////////////////////////////

void ArvBinBusca::remove1Filho(int val){
    NoArv* p = raiz;
    NoArv* paip = NULL;
    bool paiEsq;
    while( p != NULL && p->getInfo() != val ){
        paip = p;
        if(val < p->getInfo()){
            p = p->getEsq();
            paiEsq = true;
        }
        else{
            p = p->getDir();
            paiEsq = false;
        }
    }
    NoArv* filhoNaoNull = tem1Filho(p);
    if(p != NULL && filhoNaoNull != NULL){
        if(paiEsq){
            paip->setEsq(filhoNaoNull);
        }
        else{
            paip->setDir(filhoNaoNull);
        }
        delete p;
    }
    else{
        cout << "Valor não se encontra na ABB ou noh com valor encontrado não tem filho único!";
    }
}

NoArv* ArvBinBusca::tem1Filho(NoArv *p){
    if(p->getEsq() == NULL && p->getDir() != NULL)
        return p->getDir();
    else if(p->getEsq() != NULL && p->getDir() == NULL)
        return p->getEsq();
    else
        return NULL;
}

bool ArvBinBusca::eABB(){
    return auxEABB(raiz);
}

bool ArvBinBusca::auxEABB(NoArv *p){
    if(p == NULL){
        return true;
    }
    if(p->getEsq()->getInfo() < p->getInfo())
        return true;
    if(p->getDir()->getInfo() >= p->getInfo())
        return true;
    else{
        return false;
    }
    auxEABB(p->getDir());
    auxEABB(p->getEsq());
}

void ArvBinBusca::imprimeFilhos(int x){
    auxImprimeFilhos(raiz, x);
}

void ArvBinBusca::auxImprimeFilhos(NoArv *p, int x){
    if(p != NULL){
        if(p->getInfo() == x){
            cout << p->getEsq()->getInfo() << " ";
            cout << p->getDir()->getInfo() << " ";
        }
    auxImprimeFilhos(p->getEsq(), x);
    auxImprimeFilhos(p->getDir(), x);
    }
}

void ArvBinBusca::imprimeIntervalo(int x, int y){
    auxImprimeIntervalo(raiz, x, y);
}

void ArvBinBusca::auxImprimeIntervalo(NoArv *p, int x, int y){
    if(p != NULL){
        if(p->getInfo() >= x && p->getInfo() <=y){
            cout << p->getInfo() << " ";
        }
        auxImprimeIntervalo(p->getEsq(), x, y);
        auxImprimeIntervalo(p->getDir(), x, y);
    }
}

void ArvBinBusca::imprimeCrescente(){
    auxImprimeCrescente(raiz);
}

void ArvBinBusca::auxImprimeCrescente(NoArv *p){
    if(p != NULL){
        auxImprimeCrescente(p->getEsq());
        cout << p->getInfo() << " ";
        auxImprimeCrescente(p->getDir());
    }
}

void ArvBinBusca::imprimeDecrescente(){
    auxImprimeDecrescente(raiz);
}

void ArvBinBusca::auxImprimeDecrescente(NoArv *p){
    if(p != NULL){
        auxImprimeDecrescente(p->getDir());
        cout << p->getInfo() << " ";
        auxImprimeDecrescente(p->getEsq());
    }
}

int ArvBinBusca::contaNos(){
    return auxContaNos(raiz);
}

int ArvBinBusca::auxContaNos(NoArv *p){
    if(p != NULL){
        return 1 + auxContaNos(p->getEsq()) + auxContaNos(p->getDir());
    }
    else
        return 0;
}

NoArv* ArvBinBusca::buscaValor(int val){
    NoArv* p = NULL;
    p = auxBuscaValor(raiz, val);
    return p; 
}

NoArv* ArvBinBusca::auxBuscaValor(NoArv *p, int val){
    if(p != NULL){
        if(p->getInfo() == val){
            return p;
        }
        auxBuscaValor(p->getEsq(), val);
        auxBuscaValor(p->getDir(), val);
    }
}

int ArvBinBusca::nos1Filho(){
    return auxNos1Filho(raiz);
}

int ArvBinBusca::auxNos1Filho(NoArv *p){
    if(p != NULL){
        if((( p->getDir() == NULL && p->getEsq() != NULL) || (p->getDir() != NULL && p->getEsq() == NULL ))){
            return 1 + auxNos1Filho(p->getEsq()) + auxNos1Filho(p->getDir());
        }
        else{
            return auxNos1Filho(p->getEsq()) + auxNos1Filho(p->getDir());
        }
    }
    return 0;
}

int ArvBinBusca::nos2Filho(){
    return auxNos2Filho(raiz);
}

int ArvBinBusca::auxNos2Filho(NoArv *p){
    if(p != NULL){
        if( p->getDir() != NULL && p->getEsq() != NULL){
            return 1 + auxNos2Filho(p->getEsq()) + auxNos2Filho(p->getDir());
        }
        else{
            return auxNos2Filho(p->getEsq()) + auxNos2Filho(p->getDir());
        }
    }
    return 0;
}

int ArvBinBusca::classificaNo(int val){
    return auxClassificaNo(raiz, val);
}

int ArvBinBusca::auxClassificaNo(NoArv *p, int val){
    if( p != NULL ){
        if(p->getInfo() == val){
            if(p->getEsq() == NULL && p->getDir() == NULL){
                return 0;
            }
            else if( ( (p->getEsq() != NULL && p->getDir() == NULL) || (p->getEsq() == NULL && p->getDir() != NULL) ) ){
                return 1;
            }
            else{
                return 2;
            }
        }
        return auxClassificaNo(p->getEsq(), val) + auxClassificaNo(p->getDir(), val);
    }
    return 0;
}

void ArvBinBusca::insereDoVetor(int n, int *vet){
    auxInsereDoVetor(raiz, n, vet);
}

void ArvBinBusca::auxInsereDoVetor(NoArv *p, int n, int *vet){
    if(p != NULL){
        auxInsereDoVetor(p->getEsq(), n, vet);
        auxInsereDoVetor(p->getDir(), n, vet);
        insere(vet[n]);
    }
}

int* ArvBinBusca::insereVetorCrescente(){
    int* vet = new int[contaNos()];
    int i = 1; 
    vet = auxInsereVetorCrescente(raiz, vet, i);
    return vet;
}

int* ArvBinBusca::auxInsereVetorCrescente(NoArv *p, int *vet, int i){
    if(p != NULL){
        auxInsereVetorCrescente(p->getEsq(), vet, i);
        vet[0] = p->getInfo();
        auxInsereVetorCrescente(p->getDir(), vet, i);
    }
    return vet;
}

int* ArvBinBusca::insereNoVetDecrescente(){}

int* ArvBinBusca::auxInsereNoVetDecrescente(NoArv *p){}