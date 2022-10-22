#include <iostream>
#include "ArvBinBusca.h"
#include "ArvBinBusca.cpp"

using namespace std;

void preencheABB(ArvBinBusca *a, int p, int q){
    if(p<=q){
        int m = (p+q)/2;
        a->insere(m);
        preencheABB(a, p, m-1);
        preencheABB(a, m+1, q);
    }
}

int main()
{
    ArvBinBusca arv;
    arv.insere(15);
    arv.insere(10);
    arv.insere(20);
    arv.insere(6);
    arv.insere(12);
    arv.insere(17);
    arv.insere(25);
    arv.insere(-3);
    arv.insere(8);
    arv.insere(30);
    arv.insere(40);
    arv.imprime();
    cout << "Conta:  " << arv.contaNos() << endl;
    cout << "Conta2: " << arv.contaNos2() << endl;
    cout << "Soma:   " << arv.somaNos() << endl;
    cout << "Media:  " << (float)arv.somaNos()/arv.contaNos() << endl;
    cout << "Media:  " << arv.mediaNos() << endl;
    cout << "Media2: " << arv.mediaNos2() << endl;

    arv.imprimeNivel(2);
    arv.imprimeMenores(15);
    /*
    arv.remove(8);
    arv.imprime();
    arv.remove(25);
    arv.imprime();
    arv.remove(20);
    arv.imprime();
    arv.remove(15);
    arv.imprime();
    */

    /*
    cout << arv.busca(18) << endl;
    cout << arv.buscaIt(18) << endl;
    cout << arv.busca(25) << endl;
    cout << arv.buscaIt(25) << endl;
    */
   // Ex 1:
   cout << "Maior valor: " << arv.maior() << endl;
   cout << endl;

   // Ex 2:
   cout << "Menor valor: " << arv.menor() << endl;
   cout << endl;

   // Ex 3:
   arv.removeMaior();
   // Ex 4:
   arv.removeMenor();
   arv.imprime();
   cout << endl;

   // Ex 5:
   int x;
   cin >> x;
   cout << "Pares da raiz até " << x << ": " << arv.contaParesCaminho(x) << endl;
   cout << endl;

   // Ex 7:
   ArvBinBusca *arv2 = new ArvBinBusca();
   cout << "Árvore balanceada: " << endl;
   preencheABB(arv2, 1, 10);
   arv2->imprime();
    return 0;
}
