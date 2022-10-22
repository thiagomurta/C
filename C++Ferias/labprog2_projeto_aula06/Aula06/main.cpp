#include <iostream>
#include "Ponto.h"
#include "ListaCont.h"
#include "ListaCont.cpp"

using namespace std;

int main()
{
    /*
    ListaCont l(10);
    ListaCont lb(10);

    l.insereFinal(24);
    l.insereFinal(3);
    l.insereFinal(2);
    l.insereFinal(-1);
    l.insereFinal(99);
    lb.insereFinal(25);
    lb.insereFinal(4);
    lb.insereFinal(3);
    lb.insereFinal(0);
    lb.insereFinal(100);
    */
    /*
    if(l.troca(1,3)){
        cout << "TRUE!" << endl;
    }
    else{
        cout << "FALSE!" << endl;
    }*/
    /*cout << l.numMax() << endl;
    if(l.aumentaCapacidade(15)){
        cout << "TRUE!" << endl;
    }
    else{
        cout << "FALSE!" << endl;
    }
    */
   /*
    cout << l.numMax() << endl;
    cout << l.numNos() << endl;
    int alg = 3;
    //cin >> alg;
    cout << "A primeira ocorrência de um número maior que " << alg << ": " << l.buscaMaior(alg) << endl;
    l.imprime();
    l.limpar();
    l.insereFinal(3);
    int vet[] = {1,2,3};
    l.insereValores(3, vet);
    l.imprime();
    */
    /*
    l.insereFinal(3);
    l.insereFinal(2);
    l.insereFinal(5);
    l.insereFinal(4);
    l.insereFinal(9);
    l.imprime();
    l.removeMultiplos(3);
    l.imprime();
    */
    /*
    ListaCont* l2 = l.copiar(3);
    l.imprime();
    l2->imprime();
    */
    /*ListaCont* l2;
    l2->intercala(&l,&lb);
    l2->imprime();*/
    /*
    cout << "Número de nós: " << l.numNos() << endl;
    cout << "Número máximo: " << l.numMax() << endl;
    int v[3] = {-5,6,7};
    l.inserirVet(3, v);
    l.imprime();
    cout << "Número de nós atualmente: " << l.numNos() << endl;
    cout << "Número máximo atualmente: " << l.numMax() << endl;
    */
    ListaCont l(50);
    for(int i = 0; i < 50; i++){
        l.insereFinal(i);
    }
    ListaCont* l2 = l.divide();
    ListaCont* l3 = l.divide();
    l2->imprime();
    l3->imprime();
    return 0;
}
