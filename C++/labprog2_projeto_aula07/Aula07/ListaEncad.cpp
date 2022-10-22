#include <iostream>
#include <cstdlib>
#include "ListaEncad.h"

using namespace std;

ListaEncad::ListaEncad()
{
    cout << "Criando objeto ListaEncad" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaEncad::~ListaEncad()
{
    cout << "Destruindo objeto ListaEncad" << endl;
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaEncad::busca(int val)
{
    No *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaEncad::get(int k)
{
    No *p = primeiro;
    int i = 0;
    while(i < k && p != NULL)
    {
        i++;
        p = p->getProx();
    }
    if(p == NULL)
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
    else
        return p->getInfo();
}

void ListaEncad::set(int k, int val)
{
    No *p = primeiro;
    int i = 0;
    while(i < k && p != NULL)
    {
        i++;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}


void ListaEncad::insereInicio(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(primeiro);

    primeiro = p;

    n++;
    if(n == 1) ultimo = p;
}

void ListaEncad::insereFinal(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(NULL);

    if(ultimo != NULL) 
    ultimo->setProx(p);
    ultimo = p;

    n++;
    if(n == 1) primeiro = p;
}

void ListaEncad::removeInicio()
{
    No* p;
    if(primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;

        n--;
        if(n == 0) ultimo = NULL;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

void ListaEncad::removeFinal()
{
    No* p;
    if(ultimo != NULL)
    {
        if(primeiro == ultimo)
        {
            primeiro = NULL;
            p = NULL;
        }
        else
        {
            p = primeiro;
            while(p->getProx() != ultimo)
                p = p->getProx();
            p->setProx(NULL);
        }
        delete ultimo;
        ultimo = p;
        n--;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}
///QUESTÃO 6.1
void ListaEncad::imprimeElemsEmOrdem(){
    No* p = primeiro;
    No* ant = NULL;
    while(p != NULL){
        if(ant==NULL){ //quando está no inicio
            if(p->getInfo()<= p->getProx()->getInfo()){
                cout << " " << p->getInfo();
            }
        }
        else if(p->getProx()==NULL){ // última posição
            if(p->getInfo() >= ant->getInfo()){
                cout << " " << p->getInfo();
            }
        }
        else{ // intermediário
            if(p->getInfo()<= p->getProx()->getInfo()){
                if(p->getInfo() >= ant->getInfo()){
                    cout << " " << p->getInfo();
                }
            }
        }
        ant = p;
        p = p->getProx();
    }
}
///QUESTÃO 6.6
bool ListaEncad::inserePosicaoVal(int k,int val){
    int pos, i = 1;
    No* p = primeiro;
    while(i < k && p!=NULL){
        i++;
        p = p->getProx();
    }
    if(p!=NULL){
        p->setInfo(val);
        p->getInfo();
        p = p->getProx();
        return true;
    }
    return false;
}
/*Gabarito 6.6
bool ListaEncad::inserePosicaoVal(int k,int val){
    int pos;

    int valK = get(k);
    if(valK >= n || valK < 0){
        return false;
    }
    if(valK == 0){
        insereInicio(val);
    }
    else{
        No* ant = NULL, *p = primeiro;
        for(int i = 0; i < valK; i++){
            ant = p;
            p = p->getProx();
        }
        No *novo = new No();
        novo->setInfo(val);
        novo->setProx(p);
        ant->setProx(novo);
        n++
    }
    return true;
}*/
///QUESTÃO 6.5
int* ListaEncad::menorProximo(){
    No* p = primeiro;
    No* ant = NULL;
    No* vet;
    int* v = new int[n];
    int i=0;
    while(p != NULL){
        vet = p;
        if(ant==NULL){ //quando está no inicio
            if(p->getInfo() < p->getProx()->getInfo()){
                //cout << "1";
                vet->setInfo(1);
                v[i]=vet->getInfo();
            }
            else{
                //cout<< "0";
                vet->setInfo(0);
                v[i]=vet->getInfo();
            }
        }
        else if(p->getProx()==NULL){ // última posição
            if(p->getInfo() > ant->getInfo()){
                //cout << "1";
                vet->setInfo(1);
                v[i]=vet->getInfo();
            }
            else{
                //cout << "0";
                vet->setInfo(0);
                v[i]=vet->getInfo();
            }
        }
        else{ // intermediário
            if(p->getInfo() < p->getProx()->getInfo()){
                //cout << "1";
                vet->setInfo(1);
                v[i] = vet->getInfo();
            }
            else{
                //cout << "0";
                vet->setInfo(0);
                v[i] = vet->getInfo();
            }
        }
        ant = p;
        p = p->getProx();
        i++;
    }
    delete []v;
    return v;
}

//PEGA O NÚMERO DE ELEMENTOS QUE EXISTE NA LISTA
int ListaEncad::getComprimento(){
    No* p=primeiro;
    int i = 0;
    while(p!=NULL){
        p = p->getProx();
        i++;
    }
    return i;
}


int ListaEncad::contaMaiores(int val){
    No* p = primeiro;
    int contador = 0;
    while(p!=NULL){
        if(p->getInfo()>val){
            contador++;
        }
        p = p->getProx();
    }
    return contador;
}

///Exercício 8
bool ListaEncad::igual(ListaEncad* l2){
    No* p = primeiro;
    No* q = l2->primeiro;
    int j = l2->n;
    int i = 0, aux = 0;
    cout << "O valor de j é: " << j << endl;
    while(q!=NULL && i<j){
        if(p->getInfo()==q->getInfo()){
            aux++;
        }
        p = p->getProx();
        q = q->getProx();
    }
    if(aux==j){
        return true;
    }
    else{
        return false;
    }
}


void ListaEncad::insereOrdenado(int val){
    No* p = primeiro, *ant = NULL;
    No* novo = new No();
    while(p != NULL){
        if(ant==NULL){ //quando está no inicio
            if(p->getInfo() <= p->getProx()->getInfo()){
                if(p->getInfo()>val){
                    No *novo = new No();
                    novo->setInfo(val);
                    novo->setProx(p);
                    ant->setProx(novo);
                    n++;
                }
            }
        }
        else if(p->getProx()==NULL){ // última posição
            if(p->getInfo() >= ant->getInfo()){
                if(p->getInfo()>val){
                        No *novo = new No();
                        novo->setInfo(val);
                        novo->setProx(p);
                        ant->setProx(novo);
                        n++;
                    }
            }
        }
        else{ // intermediário
            if(p->getInfo()<= p->getProx()->getInfo()){
                if(p->getInfo() >= ant->getInfo()){
                    if(p->getInfo()>val){
                        No *novo = new No();
                        novo->setInfo(val);
                        novo->setProx(p);
                        ant->setProx(novo);
                        n++;
                    }
                }
            }
        }
        ant = p;
        p = p->getProx();
    }
}

///Exercício 10
void ListaEncad::removeValor(int val){
    No* p = primeiro;
    No* ant = NULL;
    while(p!=NULL){
        if(p->getInfo()!=val){
            p->getInfo();
        }
        else{
            p->setInfo(p->getProx()->getInfo());
            p->setProx(p->getProx()->getProx());
            p->getInfo();
            n--;
        }
        p = p->getProx();
    }
}
/*No* ListaEncad::endereco(int k){
    No* p = primeiro;
    No* x;
    int i=0;
    while(p!=NULL && i<k){
        p = p->getProx();
        i++;
        x = p;
    }
    cout << &x << endl;
}*/

void ListaEncad::reduz_n(int n1){
    int i = 0;
    if(n1<0 || n1>n){
        cout << "Valor inválido!!" << endl;
        exit(1);
    }
    int nn = n;
    //n recebe o valor de n1
    n = n1;
    //diferença que serã excluída
    int t = nn-n;
    while(i < t){
        this->removeFinal();
        i++;
    }
}
///FIZ SÓ PRA TESTAR // IMPRIME ITENS DA LISTA
void ListaEncad::imprimir(){
    No* p = primeiro;
    while(p!=NULL){
        cout << p->getInfo() << " ";
        p = p->getProx();
    }
}