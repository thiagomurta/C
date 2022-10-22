#include <iostream>
#include "PilhaEncad.h"
#include "FilaEncad.h"
#include "PilhaEncad.cpp"
#include "FilaEncad.cpp"

using namespace std;

int* inverte(int* vet, int n){
    int *novoVet = new int[n];
    PilhaEncad p;
    for (int i = 0; i < n; i++){
        p.empilha(vet[i]);
    }
    ///desempilha os elementos de p e os coloca em novoVet
    int i = 0;
    while(!p.vazia()){
        novoVet[i] = p.desempilha();
        i++;
    }

    return novoVet;
}

void inverteFila(FilaEncad *f){
    PilhaEncad p;
    while(!f->vazia()){
        p.empilha(f->desenfileira());
    }
    while(!p.vazia()){
        f->enfileira(p.desempilha());
    }
}

FilaEncad* concatena(FilaEncad *f1,FilaEncad *f2){

    FilaEncad* novaFila = new FilaEncad();

    while(!f1->vazia()){
        novaFila->enfileira(f1->desenfileira());
    }
    ///enfileira os valores de f2 apenas se tais valores não se encontram na fila novaFila
    while(!f2->vazia()){
        int val = f2->desenfileira();

        if(!novaFila->pertence(val)){
            novaFila->enfileira(val);
        }
    }

    return novaFila;
}

void removeDaPilha(PilhaEncad *p, int x){
    ///remove a primeira ocorrência do valor x
    /// da pilha p usando apenas as operções do TAD
    PilhaEncad paux;

    while(!p->vazia()){
        int val = p->desempilha();
        
        if(val == x){
            break;
        }
        else{
            paux.empilha(val);
        }
    }
    while(!paux.vazia()){
        p->empilha(paux.desempilha());
    }
}

FilaEncad* reorganiza(FilaEncad *f){
    FilaEncad* novaFila = new FilaEncad();
    int primeiro, ant;
    
    //caso a fila seja vazia
    if(f->vazia()){
        return novaFila;
    }

    //primeiro elemento já que não entra na repetição
    primeiro = ant = f->desenfileira();
    //mandou pra última posição
    f->enfileira(primeiro);
    //pega o primeiro enquanto for diferente do primeiro que foi para a última posição
    while(f->getInicio() != primeiro){
        //desenfileira e pega o valor da primeira posição
        int val = f->desenfileira();
        if(val > 70 && ant > 70){
            //salva na nova fila
            novaFila->enfileira(val);
        }
        else{
            //continua na fila antiga
            f->enfileira(val);
        }
        ant = val;
    }
    return novaFila;
}

int compara(FilaEncad* f1,FilaEncad* f2){
    if(f1->getNumNos() > f2->getNumNos()){
        return 1;
    }
    else if(f1->getNumNos() == f2->getNumNos()){
        return 0;
    }
    else{
        return -1;
    }
}

int fibonacci(int n){
    PilhaEncad p;
    PilhaEncad* f;
    int i=0;
    p.empilha(n);
    while(i<n){
        f->empilha(p.desempilha());
        i++;
    }
    int fib = 0;
    //se fib = 1
    if(n==1){
        fib = 1;
        return fib;
    }
    // se fib = 0
    else if(n==0){
        fib = 0;
        return fib;
    }
    else{
        return fib + fibonacci(n-1);
    }
}

int main()
{
    /// TESTE COM PILHA
    PilhaEncad p;
    FilaEncad f;
    FilaEncad f3;

    f.enfileira(15);
    f.enfileira(85);
    f.enfileira(71);
    f.enfileira(75);
    f.enfileira(62);
    f.enfileira(70);
    f.enfileira(30);
    f.enfileira(92);
    f.enfileira(100);
    f.enfileira(54);
    cout << fibonacci(4) << endl;
    /*f3.enfileira(15);
    f3.enfileira(85);
    f3.enfileira(71);
    f3.enfileira(75);
    f3.enfileira(62);
    f3.enfileira(70);
    f3.enfileira(30);
    f3.enfileira(92);
    f3.enfileira(100);
    f3.enfileira(54);*/
    //cout << compara(&f,&f3) << endl;
    //FilaEncad* f2 = reorganiza(&f);
    //f.imprime();
    //f2->imprime();
    /*

    for(int i = 0; i < 5; i++) 
        p.empilha(i);
    cout << "Pilha apos inserir 5 valores" << endl;
    ///p.imprime();

    for(int i = 20; i < 25; i++) p.empilha(i);
    cout << "Pilha apos inserir mais 5 valores" << endl;
    ///p.imprime();

    /// TESTE COM FILA
    
    FilaEncad f;
    for(int i=0; i<5; i++) f.enfileira(i);
    cout << "Fila apos inserir 5 valores" << endl;
    ///f.imprime();

    for(int i = 20; i < 25; i++) f.enfileira(i);
    cout << "Fila apos inserir mais 5 valores" << endl;
    ///f.imprime();

    */   
    return 0;
}