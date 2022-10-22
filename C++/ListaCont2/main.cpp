#include <iostream>
#include "ListaCont2.h"
#include "ListaCont2.cpp"

int main()
{
    int n = 1;
    ListaCont2 lista(n);
    ListaCont2* lista2;
    //ListaCont2* lista3;
    //int v[3] = {-5,6,7}; 
    /*for(int i=0; i<=n; i++)
    {
        lista.insereInicio(i+1);
        lista.imprime();
        lista.insereFinal(n - i);
        lista.imprime();
    }*/
    lista.insereFinal(9);
    lista.insereFinal(3);
    lista.insereFinal(5);
    lista.insereFinal(15);
    lista.insereFinal(25);
    lista.insereFinal(40);
    lista.insereFinal(90);
    lista.imprime();
    cout << "O número de nós é: " << lista.numNos() << endl;
    //questão das atividades
    /*
    bool troca = lista.troca(2,5);
    if(troca){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    lista.imprime();
    */
    /*lista.insereFinal(3);
    lista.insereFinal(2);
    lista.insereFinal(5);
    lista.insereFinal(5);
    lista.insereFinal(9);*/
    
    //bool aumenta = lista.aumentaCapacidade(20);

    //lista2 = lista.copiar(5);
    //////////////lista.inserirVet(3, v);
    /*lista.imprime();*////////////////////////////////////
    //lista2->imprime();
    /*lista.insereFinal(3);
    lista.insereFinal(4);
    lista2->insereFinal(6);
    lista2->insereFinal(7);
    lista2->insereFinal(8);
    lista2->insereFinal(9);
    lista2->insereFinal(10);
    lista3->insereFinal(0);
    lista3->insereFinal(1);
    lista3->insereFinal(2);
    lista.inserirVet();
    lista.intercala(lista2, lista3);
    lista.imprime();*/
    //delete lista2;

    //testar a função intervalo
    
    return 0;
}
