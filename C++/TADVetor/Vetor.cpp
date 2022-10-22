#include <iostream>
#include <stdlib.h>
#include "Vetor.h"

using namespace std;

Vetor::Vetor(int tam){
    n=0;
    if(tam>0)
        n=tam;
    vet = new float[n];
    for(int i=0; i<n; i++)
        vet[i] = 0.0;
}

Vetor::~Vetor(){
    delete [] vet;
}

bool Vetor::verifica(int indice){
    return indice >= 0 && indice <n;
};

float Vetor::get(int indice){
    if ( verifica(indice) )
    return vet[indice];
    else {
        cout << "Indice inválido: get" << endl;
        exit(1) ; // finaliza o programa
    }
}

void Vetor::set(int indice, float valor){
    if ( verifica(indice) )
    //armazena valor na posicao indice de vet
        vet[indice] = valor;
    else
        cout << "Indice inválido: set" << endl;
}