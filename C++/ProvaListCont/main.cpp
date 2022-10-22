#include <iostream>
#include "ListaCont.h"
#include "ListaCont.cpp"

using namespace std;

int main(){
    ListaCont l(0);

    /*l.insereFinal(3);
    l.insereFinal(2);
    l.insereFinal(5);
    l.insereFinal(4);
    l.insereFinal(9);*/
    l.insereFinal(4);
    l.insereFinal(16);
    l.insereFinal(29);
    l.insereFinal(9);
    l.insereFinal(15);
    l.removeMultiplos(3);
    cout << endl;
    /*Apenas para testes no momento da prova caso necessário
    l2->insereFinal(23);
    l2->insereFinal(6);
    l2->insereFinal(7);
    l2->insereFinal(18);
    l2->insereFinal(5);
    */


    l.imprime();
    /*
    l.insereInicio(10);

    l.imprime();

    int indice = l.buscaMaior(10);
    if(indice != -1)
        cout << "Elemento maior: " << l.get(indice) << endl;
    else 
        cout << "Nao foi encontrado valor maior na lista." <<endl;
    
    l.limpar();
    l.imprime();

    int vet[6] = {11,12,13,14,15,16};
    l.insereValores(6, vet);

    l.imprime();

    int vet2[4] = {11,12,13,14};
    l.insereValores(4, vet2);

    l.imprime();*/
    return 0;
}