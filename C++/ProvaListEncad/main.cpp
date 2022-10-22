#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaEncad.h"
#include "ListaEncad.cpp"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand()%(b - a + 1) ; /// retorna um numero inteiro aleat�rio entre a e b
}

int main()
{
    ListaEncad l; /// cria lista vazia
    int NumNos = 7;

    l.insereFinal(36);
    l.insereFinal(41);
    l.insereFinal(26);
    l.insereFinal(15);
    l.insereFinal(45);

    l.reduz_n(1);
    l.imprimir();
    cout << endl;
    /*Lista apenas para teste no momento da prova
    l2->insereFinal(5);
    l2->insereFinal(98);
    l2->insereFinal(23);
    l2->insereFinal(6);
    l2->insereFinal(18);
    l2->insereFinal(63);
    l2->insereFinal(52);
    l2->insereFinal(7);
    l2->insereFinal(69);
    l2->insereFinal(3);
    */
    /*
    srand(time(NULL));
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

