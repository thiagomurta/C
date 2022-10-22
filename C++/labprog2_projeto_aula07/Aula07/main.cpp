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
    int NumNos = 8;///12
    int* v = new int[8];
    //ListaEncad* L1;
    //ListaEncad* L2
    ListaEncad L2;
    ///QUESTÃO 6.6
    L2.insereFinal(3);
    L2.insereFinal(2);
    L2.insereFinal(5);
    L2.insereFinal(7);
    L2.insereFinal(8);//9
    L2.insereFinal(2);
    L2.insereFinal(4);
    L2.insereFinal(8);
    L2.imprimir();
    cout << endl;
    ///Exercício 10
    L2.removeValor(2);
    L2.imprimir();
    cout << "Removeu" << endl;

    ///Exercício 8
    /*cout << endl;
    cout << "Lista que será comparada: " << endl;
    l.insereFinal(3);
    l.insereFinal(2);
    l.insereFinal(5);
    l.insereFinal(7);
    l.insereFinal(8);//9
    l.insereFinal(2);
    l.insereFinal(4);
    l.insereFinal(8);
    l.imprimir();
    bool iguala = L2.igual(&l);
    if(iguala){
        cout << "Verdade" << endl;
    }
    else{
        cout << "Falso" << endl;
    }*/
    cout << "----------------------"<< endl;

    /*/// FIZ PARA VER O ENDEREÇO DE CADA ELEMENTO EM DETERMINADO NÓ
    cout << "Endereço: ";
    L2.endereco(3);
    L2.endereco(5);
    L2.endereco(1);*/

    //Atividade 3 dos Exercícios
    //cout << "O Comprimento da lista é: " << L2.getComprimento() << endl;
    //
    //Atividade 4 dos Exercícios
    /*
    cout << endl;
    cout << "Os números maiores que estão na lista são: " << L2.contaMaiores(6) << endl;*/
    //Atividade 5 dos Exercícios
    /*cout << endl;
    cout << "Exercício 5: " << endl;
    L2.insereOrdenado(15);
    L2.imprimir();*/
    /////
    bool troca = L2.inserePosicaoVal(7,1);
    if (troca){
        cout << "TRUE" << endl;
    }
    else{
        cout << "FALSE" << endl;
    }
    L2.imprimir();
    
    /*///QUESTÃO 6.1
    L2.imprimeElemsEmOrdem();*/
    
    
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
    /*
    l.insereFinal(3);
    l.insereFinal(2);
    l.insereFinal(5);
    l.insereFinal(7);
    l.insereFinal(9);
    l.insereFinal(2);
    l.insereFinal(4);
    l.insereFinal(8);
    l.imprimir();
    */
    /* ///QUESTÃO 6.5
    v=l.menorProximo();
    cout << "[";
    for(int i=0;i<NumNos;i++){
        cout<<v[i]<<", ";
    }
    cout << "]"<< endl;
    l.imprimir();
    */

    /*bool troca = l.inserePosicaoVal(0,200);
    cout << endl;
    cout << "Houve troca de de números? ";
    if (troca)
    {
        cout << "TRUE" << endl;
    }
    else{
        cout << "FALSE" << endl;
    }
    l.imprimir();
    cout << endl;

    bool existe = l.busca(20);
    cout << "O valor 20 esta na lista? ";
    if(existe)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;
*/

    return 0;
}

