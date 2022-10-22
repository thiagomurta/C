#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cmath>
#include "ArvBin.h"

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "�rvore vazia!" << endl;
        exit(1);
    }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(x);
    if(sae != NULL){
        p->setEsq(sae->raiz);
    }
    else{
        p->setEsq(NULL);
    }
    if(sad != NULL){
        p->setDir(sad->raiz);
    }
    else{
        p->setDir(NULL);
    }
    raiz = p;
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

void ArvBin::montaArvore()
{
    if(!vazia())
        cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
    else
    {
        cout << "Montagem da arvore em pre-ordem:" << endl;
        raiz = auxMontaArvore();
    }
}

NoArv* ArvBin::auxMontaArvore()
{
    string linha;
    cout << "Valor: ";
    cin >> linha;
    if(linha != "NULL" && linha != "null")
    {
        istringstream ent(linha);
        int valor;
        ent >> valor;
        NoArv *p = new NoArv();
        p->setInfo(valor);
        cout << "Esquerda" << endl;
        p->setEsq(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        cout << "Direita" << endl;
        p->setDir(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        return p;
    }
    else
        return NULL;
}

void ArvBin::insere(int x)
{
    raiz = auxInsere(raiz, x);
}

NoArv* ArvBin::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if(direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), x));
        else
            p->setDir(auxInsere(p->getDir(), x));
    }
    return p;
}

bool ArvBin::vazia()
{
    return (raiz == NULL);
}

bool ArvBin::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(NoArv *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (auxBusca(p->getEsq(), x))
        return true;
    else
        return auxBusca(p->getDir(), x);
}

ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

void ArvBin::preOrdem()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxPreOrdem(raiz);
}

void ArvBin::auxPreOrdem(NoArv *p)
{
    if (p != NULL)
    {
        cout << p->getInfo() << " ";
        auxPreOrdem(p->getEsq());
        auxPreOrdem(p->getDir());
    }
}

int ArvBin::contaNos(){
    return auxContaNos(raiz);
}

int ArvBin::auxContaNos(NoArv *p){
    if(p == NULL){
        return 0;
    }

    return auxContaNos(p->getEsq()) + auxContaNos(p->getDir()) + 1;
}

int ArvBin::contaNosFolhas(){
    return auxContaNosFolhas(raiz);
}

int ArvBin::auxContaNosFolhas(NoArv *p){
    if(p == NULL){
        return 0;
    }
    if(p->getEsq() == NULL && p->getDir() == NULL){
        return auxContaNosFolhas(p->getEsq()) + auxContaNosFolhas(p->getDir()) + 1;
    }
    else{
        return auxContaNosFolhas(p->getEsq()) + auxContaNosFolhas(p->getDir());
    }
}
int ArvBin::altura(){
    return auxAltura(raiz);
}

int ArvBin::auxAltura(NoArv *p){
    if(p == NULL){
        return -1;
    }
    int he = auxAltura(p->getEsq());
    int hd = auxAltura(p->getDir());
    if(he > hd){
        return he+1;
    }
    else{
        return hd+1;
    }
}

int ArvBin::contaImpar(){
    return auxContaImpar(raiz);
}

int ArvBin::auxContaImpar(NoArv *p){
    if(p == NULL){
        return 0;
    }
    int total = auxContaImpar(p->getEsq()) + auxContaImpar(p->getDir());
    if(p->getInfo() % 2 == 1){
        total++;
    }
    return total;
}

void ArvBin::imprimeNivel(int k){
    auxImpNivel(raiz, k);
}

void ArvBin::auxImpNivel(NoArv *p, int k){
    if(p != NULL && k >= 0){
        if(k == 0){
            cout << p->getInfo() << " ";
        }
        auxImpNivel(p->getEsq(), k-1);
        auxImpNivel(p->getDir(), k-1);
    }
}

float ArvBin::mediaNivel(int k){
    int soma = 0, cont = 0;
    auxMediaNivel(raiz, k, &soma, &cont);
    if(cont > 0){
        return soma / (float)cont;
    }
    else{
        return 0;
    }
}

void ArvBin::auxMediaNivel(NoArv *p, int k, int *soma, int *cont){
    if(p != NULL && k >= 0){
        if(k == 0){
            *soma = *soma + p->getInfo();
            (*cont)++;
        }
        auxMediaNivel(p->getEsq(), k-1, soma, cont);
        auxMediaNivel(p->getDir(), k-1, soma, cont);
    }
}

int ArvBin::min(){
    if(raiz == NULL)
    {
        cout << "Arvore vazia!";
        exit(1);
    }

    int menor = raiz->getInfo();
    auxMin(raiz, &menor);
    return menor;
}

void ArvBin::auxMin(NoArv *p, int *menor){
    if(p != NULL)
    {
        if(p->getInfo() < *menor)
            *menor = p->getInfo();

        auxMin(p->getEsq(), menor);
        auxMin(p->getDir(), menor);
    }
}

void ArvBin::contaElegante(){
    int cont1 = 0; // multiplos de 3
    int cont2 = 0; // folhas negativas
    auxContaElegante(raiz, &cont1, &cont2);
    cout << endl;
    cout << "Múltiplos de 3: "<< cont1 << endl;
    cout << "Folhas Negativas: "<< cont2 << endl;
}

void ArvBin::auxContaElegante(NoArv *p, int *cont1, int *cont2){
    if(p != NULL){
        auxContaElegante(p->getEsq(), cont1, cont2);// sae
        auxContaElegante(p->getDir(), cont1, cont2);// sad
        // raiz
        if(p->getInfo() % 3 == 0){
            (*cont1)++;
        }
        if(ehFolha(p) && p->getInfo() < 0){
            (*cont2)++;
        }
    }
}

/*bool ArvBin::ehFolha(NoArv *p){
    return p->getEsq() == NULL && p->getDir() == NULL;
}*/

void ArvBin::contagens(int k){
    int cont1 = 0;
    int cont2 = 0;
    auxContagens(raiz, 0, k, &cont1, &cont2);
    cout << endl;
    cout << "Conta 1: "<< cont1 << endl;
    cout << "Conta 2: "<< cont2 << endl;
}

void ArvBin::auxContagens(NoArv *p, int atual, int k, int *cont1, int *cont2){
    if(p != NULL){
        auxContagens(p->getEsq(), atual+1, k, cont1, cont2);// sae
        auxContagens(p->getDir(), atual+1, k, cont1, cont2);// sad
        // raiz
        if(p->getInfo() % 2 == 0 && p->getDir() == NULL && p->getEsq() != NULL){
            (*cont1)++;
        }
        if(ehFolha(p) && atual <= k){
            (*cont2)++;
        }
    }
}

void ArvBin::contagens2(int val, int k){
    int cont1 = 0;
    int cont2 = 0;
    auxContagens2(raiz, val, 0, k, &cont1, &cont2);
    cout << endl;
    cout << "Conta 1: "<< cont1 << endl;
    cout << "Conta 2: "<< cont2 << endl;
}

void ArvBin::auxContagens2(NoArv *p, int val, int atual, int k, int *cont1, int *cont2){
    if(p != NULL){
        // raiz
        if(p->getInfo() > val && p->getEsq() == NULL && p->getDir() != NULL){
            (*cont1)++;
        }
        if(p->getDir() != NULL && p->getEsq() != NULL && atual <= k){
            (*cont2)++;
        }
        auxContagens2(p->getEsq(), val, atual+1, k, cont1, cont2);// sae
        auxContagens2(p->getDir(), val, atual+1, k, cont1, cont2);// sad
    }
}

int ArvBin::difMaxMinFolha(){
    if(raiz == NULL){
        return -1;
    }
    bool primeiraFolha = true;
    int min, max;
    auxDifMaxMinFolha(raiz, &min, &max, &primeiraFolha);
    return abs(max-min);
}

int ArvBin::auxDifMaxMinFolha(NoArv *p, int *min, int *max, bool *primeiraFolha){
    if(p != NULL){

        if(ehFolha(p)){
            if(*primeiraFolha){
                *min = *max = p->getInfo();
                *primeiraFolha = false;
            }
            if(p->getInfo() < *min){
                *min = p->getInfo();
            }
            if(p->getInfo() > *max){
                *max = p->getInfo();
            }
        }
        auxDifMaxMinFolha(p->getEsq(), min, max, primeiraFolha);
        auxDifMaxMinFolha(p->getDir(), min, max, primeiraFolha);
    }
}



void ArvBin::imprime()
{
    auxImprime(raiz);
}

void ArvBin::auxImprime(NoArv *p)
{
    cout << "[ ";
    if(raiz != NULL){
        cout << p->getInfo() << " ";
        auxImprime(p->getEsq());
        auxImprime(p->getDir());
    }
    cout << "]";
}

int* ArvBin::criaVetFolhas(int k, int *n){
    int j = pow(2,k);
    n = new int[j];
    if(raiz == NULL){
        return NULL;
    }
    // m - funciona para verificar o nível
    int m = 0;
    int h = 0;
    n = auxCriaVetFolhas(raiz, k, n, &m, &h);

    for(int i = 0; i < j; i++){
        if(n[i] == NULL){
            n[i] = -1;
        }
    }
    return n;
}

int* ArvBin::auxCriaVetFolhas(NoArv *p, int k, int *n, int* m, int* h){
    //raiz
    if(ehFolha(p) && k <= *m){
        n[(*h)] = p->getInfo();
        //incrementar para a próxima folha que poderá ter no mesmo nível
        (*h)++;
    }
    else{
        //sae
        auxCriaVetFolhas(p->getEsq(), k, n, m+1, h);
        //sad
        auxCriaVetFolhas(p->getDir(), k, n, m+1, h);
    }
    return n;
}

bool ArvBin::ehFolha(NoArv *p){
    return p->getEsq() == NULL && p->getDir() == NULL;
}