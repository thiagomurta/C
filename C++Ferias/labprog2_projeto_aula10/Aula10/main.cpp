#include <iostream>
#include "ArvBin.h"
#include "ArvBin.cpp"
using namespace std;

int main()
{
    /*
    ArvBin arv;
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
    */
    /*
    arv.contagens(0);
    arv.contagens(1);
    arv.contagens(2);
    arv.contagens(3);
    */

    /*
    arv.contagens2(2,0);
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
    cout << "\t\t\t\t\t\t------------------OPERAÇÕES------------------" << endl;
    cout << "\t\t\t\t\t\t------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\tNúmero de nós na árvore a1: " << a1.contaNos() << endl;
    cout << "\t\t\t\t\t\tNúmero de nós na árvore a2: " << a2.contaNos() << endl;
    cout << "\t\t\t\t\t\tNúmero de nós na árvore a3: " << a3.contaNos() << endl;
    cout << "\t\t\t\t\t\tNúmero de nós na árvore: " << arv.contaNos() << endl;
    cout << "\t\t\t\t\t\t------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\tNúmero de folhas na árvore a1: " << a1.contaNosFolhas() << endl;
    cout << "\t\t\t\t\t\tNúmero de folhas na árvore a2: " << a2.contaNosFolhas() << endl;
    cout << "\t\t\t\t\t\tNúmero de folhas na árvore a3: " << a3.contaNosFolhas() << endl;
    cout << "\t\t\t\t\t\tNúmero de folhas na árvore: " << arv.contaNosFolhas() << endl;
    cout << "\t\t\t\t\t\t------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\tAltura da árvore a1: " << a1.altura() << endl;
    cout << "\t\t\t\t\t\tAltura da árvore a2: " << a2.altura() << endl;
    cout << "\t\t\t\t\t\tAltura da árvore a3: " << a3.altura() << endl;
    cout << "\t\t\t\t\t\tAltura da árvore: " << arv.altura() << endl;
    cout << "\t\t\t\t\t\t------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\tNúmeros ímpares da árvore a1: " << a1.contaImpar() << endl;
    cout << "\t\t\t\t\t\tNúmeros ímpares da árvore a2: " << a2.contaImpar() << endl;
    cout << "\t\t\t\t\t\tNúmeros ímpares da árvore a3: " << a3.contaImpar() << endl;
    cout << "\t\t\t\t\t\tNúmeros ímpares da árvore: " << arv.contaImpar() << endl;
    cout << "\t\t\t\t\t\t------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\tMédia do nível 0: " << arv.mediaNivel(0) << endl;
    cout << "\t\t\t\t\t\tMédia do nível 1: " << arv.mediaNivel(1) << endl;
    cout << "\t\t\t\t\t\tMédia do nível 2: " << arv.mediaNivel(2) << endl;
    cout << "\t\t\t\t\t\tMédia do nível 3: " << arv.mediaNivel(3) << endl;
    cout << "\t\t\t\t\t\t------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\tImpressão por Nível: ";
    cout << endl;
    cout << "\t\t\t\t\t\tNível 0: ";
    arv.imprimeNivel(0);
    cout << endl;
    cout << "\t\t\t\t\t\tNível 1: ";
    arv.imprimeNivel(1);
    cout << endl;
    cout << "\t\t\t\t\t\tNível 2: ";
    arv.imprimeNivel(2);
    cout << endl;
    cout << "\t\t\t\t\t\tNível 3: ";
    arv.imprimeNivel(3);
    cout << endl;
    cout << "\t\t\t\t\t\tNível 4: ";
    arv.imprimeNivel(4);
    cout << endl;
    cout << "\t\t\t\t\t\t------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\tSoma de todos os elementos da árvore: " << arv.soma() << endl;
    cout << "\t\t\t\t\t\tMédia de todos os elementos da árvore: " << arv.media() << endl;
    cout << "\t\t\t\t\t\tMédia de todos os elementos pares da árvore: " << arv.mediaPares() << endl;
    cout << "\t\t\t\t\t\tMaior elemento da árvore: " << arv.maiorVal() << endl;
    cout << "\t\t\t\t\t\tMenor elemento da árvore: " << arv.menorVal() << endl; 
    cout << "\t\t\t\t\t\tNúmero de elementos da árvore maiores que -5: " << arv.maiores(-5) << endl;
    cout << "\t\t\t\t\t\tSucessor de -40: " << arv.sucessor(-40) << endl;
    cout << "\t\t\t\t\t\tSucessor de 5: " << arv.sucessor(5) << endl;
    cout << "\t\t\t\t\t\tSucessor de 15: " << arv.sucessor(15) << endl;
    cout << "\t\t\t\t\t\tSucessor de 40: " << arv.sucessor(40) << endl;
    cout << "\t\t\t\t\t\tSucessor de 50: " << arv.sucessor(50) << endl;
    cout << "\t\t\t\t\t\tSucessor de 60: " << arv.sucessor(60) << endl;
    cout << "\t\t\t\t\t\tSucessor de 75: " << arv.sucessor(75) << endl;
    cout << "\t\t\t\t\t\tSucessor de 80: " << arv.sucessor(80) << endl;
    cout << "\t\t\t\t\t\tÁrvore Completa: ";
    if(arv.eCompleta())
        cout << "TRUE";
    else
        cout << "FALSE";
    cout << endl; 
    //arv.imprimirNivel(2);
    cout << "\t\t\t\t\t\t------------------------------------------------------------------------------------------" << endl;
    a1.anulaRaiz();
    a2.anulaRaiz();
    a3.anulaRaiz();
    return 0;
}

// Pré-ordem: Raiz, Esquerda, Direita
// Pós-ordem: Esquerda, Direita, Raiz
// In-Ordem: Esquerda, Raiz, Direita