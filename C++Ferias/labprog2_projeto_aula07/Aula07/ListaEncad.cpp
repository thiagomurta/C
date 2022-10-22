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

void ListaEncad::reduz_n(int n1){
    if(n1 >= 0 && n1 < n){
        No* p = primeiro;
        for (int cont = 1; cont <= n1; cont++)
        {
            ultimo = p;
            p = p->getProx();
        }
        
        while(p != NULL){
            No* t = p;
            p = p->getProx();
            delete t;
        }
        if(n1 == 0){
            primeiro = NULL;
            ultimo = NULL;
        }
        else{
            ultimo->setProx(NULL);
        }
        n = n1;
    }
    else{
        cout << "Valor inválido!" << endl;
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

int ListaEncad::numNos(){
    return n;
}

int ListaEncad::buscaMaior(int val){
    int indMaior = -1;
    if(n != 0){
        for (int i = 0; i < n; i++)
        {
            if(get(i) > val){
                indMaior = i;
                break;
            }
        }
        if(indMaior != -1)
            return indMaior;
        else
            return -1;
    }
    else{
        return -1;
    }
}
void ListaEncad::limpar(){
    No* p = primeiro;
    No* ant = NULL;
    while(p != NULL){
        ant = p->getProx();
        delete p;
        p = ant;
        n--;
    }
}

float ListaEncad::calculaMedia(){
    No* p = primeiro;
    int soma = 0;
    while(p != NULL){
        soma += p->getInfo();
        p = p->getProx();
    }
    float media = soma/n;
    return media;
}

void ListaEncad::concatena(ListaEncad *l2){
    No* p = primeiro;
    n += l2->n;
    while(p != NULL){
        p = p->getProx();
    }
    ultimo->setProx(l2->primeiro);
    ultimo = l2->ultimo;
    while(p != NULL){
        p = p->getProx();
    }
}

ListaEncad* ListaEncad::partir(int x){
    ListaEncad* l3 = new ListaEncad();
    No* p = primeiro;
    No* ant = NULL;
    int j = -1;
    if(x > n){
        cout << "Índice Inválido!" << endl;
        exit(1);
    }
    for(int i = 0; i < n; i++){
        if(i == x){
            j = x;
            break;
        }
        ant = p;
        p = p->getProx();
    }
    l3->ultimo = ultimo;
    ultimo = ant;
    ultimo->setProx(NULL);
    n = j;
    l3->n = n - x;
    l3->primeiro = p;
    No* p2 = l3->primeiro;
    while(p2 != NULL){
        p2 = p2->getProx();
    }
    return l3;
}