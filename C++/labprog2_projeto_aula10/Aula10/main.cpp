#include <iostream>
#include "ArvBin.h"
#include "ArvBin.cpp"
using namespace std;

int main()
{
    /*ArvBin arv;
    ArvBin vazia, a1, a2, a3;
    //arv.montaArvore();
    a1.cria(20, NULL, NULL);
    a2.cria(8, &vazia, &vazia);
    a3.cria(2, NULL, &a1);
    a1.cria(9, &a2, &a3);
    a2.cria(6, NULL, NULL);
    a3.cria(7, &a2, NULL);
    arv.cria(15, &a3, &a1);
    a1.anulaRaiz();
    a2.anulaRaiz();
    a3.anulaRaiz();
    //arv.insere(15);
    //arv.insere(25);
    //arv.insere(10);
    arv.preOrdem();
    arv.contaElegante();
    /*
    arv.contagens(0);
    arv.contagens(1);
    arv.contagens(2);
    arv.contagens(3);*/

    /*arv.contagens2(2,0);
    arv.contagens2(2,1);
    arv.contagens2(2,2);
    arv.contagens2(2,3);
    cout << arv.difMaxMinFolha() << endl;
    */
    ArvBin arv, vazia, a1, a2, a3;
    a1.cria(-35, &vazia, &vazia);
    a2.cria(-19, &vazia, &vazia);
    a3.cria(-20, &a1, &a2);
    a1.cria(-5, &vazia, &vazia);
    a2.cria(10, &a1, &vazia);
    a1.cria(-15, &a3, &a2);
    a2.cria(45, &vazia, &vazia);
    a3.cria(60, &vazia, &vazia);
    a2.cria(50, &a2, &a3);
    a3.cria(80, &vazia, &vazia);
    a2.cria(75, &a2, &a3);
    arv.cria(40, &a1, &a2);
    a1.anulaRaiz();
    a2.anulaRaiz();
    a3.anulaRaiz();
    int vet;
    cout << arv.criaVetFolhas(3, &vet) << endl;
    cout << vet<< endl;
    return 0;
}

// Pré-ordem: Raiz, Esquerda, Direita
// Pós-ordem: Esquerda, Direita, Raiz
// In-Ordem: Esquerda, Raiz, Direita