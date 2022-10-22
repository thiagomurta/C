#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaDupla.h"

#include "ListaDupla.cpp"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand()%(b - a + 1); /// retorna um numero inteiro aleat�rio entre a e b
}

int main()
{
    ListaDupla l; /// cria lista vazia
    //ListaDupla* l2 = new ListaDupla();
    //int NumNos = 10;
    //
    l.insereFinal(3);//20
    l.insereFinal(2);//97
    l.insereFinal(5);//45
    l.insereFinal(12);//12
    l.insereFinal(7);//2
    l.insereFinal(4);
    l.imprime();
    l.remove1Ocorrencia(4);
    //l.removeDepoisMaior();
    //ListaDupla* l3 = l.criaListaMenorMaior();
    //l3->imprime();
    l.imprime();
    /*l2->insereFinal(78);
    l2->insereFinal(67);
    l2->insereFinal(54);
    l2->insereFinal(34);
    l2->insereFinal(5);
    l.removeValor(97);
    l.removek(4);
    l.imprime();
    l2->imprime();*/
    //
    /*ListaDupla* l3 = l.concatena(l2);
    l3->imprime();
    ListaDupla* l4 = l.partir(45);
    l.imprime();
    l4->imprime();*/

    /*srand(time(NULL));

    /// ATENCAO: os valores inseridos na lista sao gerados
    /// aleatoriamente e mudam em cada execucao do programa!!!
    cout << "Inserindo valores: ";
    for(int i = 1; i <= NumNos; i++)
    {
        int val =  numAleatorio(0, 50); /// cria um valor aleat�rio entre 0 e 50
        cout << val << ", ";
        l.insereInicio(val);
    }
    cout << endl;

    bool existe = l.busca(20);
    cout << "O valor 20 esta na lista? ";
    if(existe)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;
    */
    return 0;
};

