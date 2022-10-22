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
    return 1 + auxContaNos(p->getEsq()) + auxContaNos(p->getDir());
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
    int he = auxAltura(p->getEsq()) + 1;
    int hd = auxAltura(p->getDir()) + 1;
    if(he > hd){
        return he;
    }
    else{
        return hd;
    }
}

int ArvBin::contaImpar(){
    return auxContaImpar(raiz);
}

int ArvBin::auxContaImpar(NoArv *p){
    if(p != NULL ){
        if(p->getInfo() % 2 != 0)
            return 1 + auxContaImpar(p->getDir()) + auxContaImpar(p->getEsq());
        else
            return auxContaImpar(p->getEsq()) + auxContaImpar(p->getDir());
    }
    else
        return 0;
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
    return 0;
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
    *n = 0;
    if(raiz == NULL){
        return NULL;
    }
    *n = pow(2,k);
    int* vet = new int[*n];
    if(raiz == NULL){
        return NULL;
    }
    // pos - funciona para verificar o nível
    int pos = 0;
    auxCriaVetFolhas(raiz, k, 0, vet, &pos);
    for(int i = pos; i < *n; i++){
        vet[i] = -1;
    }
    return vet;
}

void ArvBin::auxCriaVetFolhas(NoArv *p, int k, int atual, int vet[], int* pos){
    //raiz
    if(p != NULL){
        if(ehFolha(p)){
            vet[(*pos)++] = p->getInfo();
        }
        if(atual < k){
            //sae
            auxCriaVetFolhas(p->getEsq(), k, atual+1, vet, pos);
            //sad
            auxCriaVetFolhas(p->getDir(), k, atual+1, vet, pos);
        }
    }
}

bool ArvBin::ehFolha(NoArv *p){
    return p->getEsq() == NULL && p->getDir() == NULL;
}

int ArvBin::impares(){
    return auxImpares(raiz);
}

int ArvBin::auxImpares(NoArv *p){
    if(p != NULL){
        if(p->getInfo() % 2 != 0)
            return 1 + auxImpares(p->getEsq()) + auxImpares(p->getDir());
        else{
            return auxImpares(p->getEsq()) + auxImpares(p->getDir());
        }
    }
    else
        return 0;
}

int ArvBin::soma(){
    return auxSoma(raiz);
}

int ArvBin::auxSoma(NoArv *p){
    if(p != NULL){
        return p->getInfo() + auxSoma(p->getEsq()) + auxSoma(p->getDir());
    }
    else
        return 0;
}

float ArvBin::media(){
    int cont = 0;
    float soma = 0;
    auxMedia(raiz, &soma ,&cont);
    float media = soma/cont;
    return media; 
}

float ArvBin::auxMedia(NoArv *p, float* soma ,int* cont){
    if(p != NULL){
        *soma += p->getInfo();
        (*cont)++;
        return p->getInfo() + auxMedia(p->getEsq(), soma ,cont) + auxMedia(p->getDir(), soma ,cont);
    }
    else
        return 0;
}

float ArvBin::mediaPares(){
    int cont = 0;
    float soma = 0;
    auxMediaPares(raiz, &soma ,&cont);
    float media = soma/cont;
    return media; 
}

float ArvBin::auxMediaPares(NoArv *p, float* soma,int* cont){
    if(p != NULL){
        if(p->getInfo() % 2 == 0){
            *soma += p->getInfo();
            (*cont)++;
            return p->getInfo() + auxMediaPares(p->getEsq(), soma ,cont) + auxMediaPares(p->getDir(), soma ,cont);
        }
        else
            return auxMediaPares(p->getEsq(), soma ,cont) + auxMediaPares(p->getDir(), soma ,cont);
    }
    else
        return 0;
}

int ArvBin::maiorVal(){
    return auxMaiorVal(raiz);
}

int ArvBin::auxMaiorVal(NoArv *p){
    if(p != NULL){
        if(p->getDir() != NULL){
            return auxMaiorVal(p->getDir());
        }
        return p->getInfo();
    }
    else
        return 0;
}

int ArvBin::menorVal(){
    return auxMenorVal(raiz);
}

int ArvBin::auxMenorVal(NoArv *p){
    if(p != NULL){
        if(p->getEsq() != NULL){
            return auxMenorVal(p->getEsq());
        }
        return p->getInfo();
    }
    else
        return 0;
}

int ArvBin::maiores(int val){
    return auxMaiores(raiz, val);
}

int ArvBin::auxMaiores(NoArv *p, int val){
    if(p != NULL){
        if(p->getInfo() > val){
            return 1 + auxMaiores(p->getDir(), val) + auxMaiores(p->getEsq(), val);
        }
        return auxMaiores(p->getDir(), val) + auxMaiores(p->getEsq(), val);
    }
    else
        return 0;
}

void ArvBin::auxMediaNivel2(NoArv *p, int k, int *soma, int *cont){
    if(p != NULL && k >= 0){
        if(k == 0){
            *soma += p->getInfo();
            (*cont)++;
        }
        auxMediaNivel2(p->getEsq(), k-1, soma, cont);
        auxMediaNivel2(p->getDir(), k-1, soma, cont);
    }
}

void ArvBin::imprimirNivel(int nivel){
    cout << "Imprimindo em Pré-Ordem: ";
    auxImprimirNivelPreO(raiz, nivel);
    cout << endl;
    cout << "Imprimindo em Pós-Ordem: ";
    auxImprimirNivelPO(raiz, nivel);
    cout << endl;
    cout << "Imprimindo em In-Ordem: ";
    auxImprimirNivelIO(raiz, nivel);
    cout << endl;
}

void ArvBin::auxImprimirNivelPreO(NoArv *p, int nivel){
    if(p != NULL && nivel >= 0){
        cout << p->getInfo() << " ";
        auxImprimirNivelPreO(p->getEsq(), nivel-1);
        auxImprimirNivelPreO(p->getDir(), nivel-1);
    }
}

void ArvBin::auxImprimirNivelPO(NoArv *p, int nivel){
    if(p != NULL && nivel >= 0){
        auxImprimirNivelPO(p->getEsq(), nivel-1);
        auxImprimirNivelPO(p->getDir(), nivel-1);
        cout << p->getInfo() << " ";
    }
}


void ArvBin::auxImprimirNivelIO(NoArv *p, int nivel){
    if(p != NULL && nivel >= 0){
        auxImprimirNivelIO(p->getEsq(), nivel-1);
        cout << p->getInfo() << " ";
        auxImprimirNivelIO(p->getDir(), nivel-1);
    }
}

void ArvBin::impressao(){
    auxImpressao(raiz);
}

void ArvBin::auxImpressao(NoArv *p){
    cout << "Imprimindo em Pré-Ordem: ";
    auxImprimirPreO(raiz);
    cout << endl;
    cout << "Imprimindo em Pós-Ordem: ";
    auxImprimirPO(raiz);
    cout << endl;
    cout << "Imprimindo em In-Ordem: ";
    auxImprimirIO(raiz);
    cout << endl;
}

void ArvBin::auxImprimirPreO(NoArv *p){
    if(p != NULL){
        cout << p->getInfo() << " ";
        auxImprimirPreO(p->getEsq());
        auxImprimirPreO(p->getDir());
    }
}

void ArvBin::auxImprimirPO(NoArv *p){
    if(p != NULL){
        auxImprimirPO(p->getEsq());
        auxImprimirPO(p->getDir());
        cout << p->getInfo() << " ";
    }
}

void ArvBin::auxImprimirIO(NoArv *p){
    if(p != NULL){
        auxImprimirIO(p->getEsq());
        cout << p->getInfo() << " ";
        auxImprimirIO(p->getDir());
    }
}

int ArvBin::sucessor(int val){
    int Nmenor = raiz->getInfo();
    int Nmaior = 0;
    int menor = 0;
    auxSucessor(raiz, val, &Nmaior, &Nmenor, &menor);
    return menor;
}

void ArvBin::auxSucessor(NoArv *p, int val, int *Nmaior, int *Nmenor, int *menor){
    if(p != NULL){
        auxSucessor(p->getDir(), val, Nmaior, Nmenor, menor);
        if(p->getInfo() > val){
            *Nmaior = p->getInfo();
        }
        if(*Nmaior <= *Nmenor){
            *menor = *Nmaior;
        }
        *Nmenor = *Nmaior;
        auxSucessor(p->getEsq(), val, Nmaior, Nmenor, menor);
    }
}

bool ArvBin::eCompleta(){
    if(pow(2, altura()+1) - 1 == contaNos())
        return true;
    return false;
}