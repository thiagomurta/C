#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

int main()
{
    ArvBinBusca arv;

    cout << "Criando uma Arvore Binaria de Busca (ABB)" << endl;
    arv.insere(15); arv.insere(9);  arv.insere(20);
    arv.insere(7);  arv.insere(11); arv.insere(18);
    arv.insere(24); arv.insere(6);  arv.insere(8);
    arv.insere(10); arv.insere(12); arv.insere(17);
    arv.insere(-19); arv.imprime(); cout << endl;


    cout<<"TESTES PARA A QUESTAO 1 ------------------------------------------------"<<endl;
    cout<<"Valor esperado: Quant. nos pares: 7"<<endl;
    cout<<"Valor esperado: Quant. folhas nao negativas: 5"<<endl;

    arv.contaElegante();
    cout << endl << endl;



    // -----------------------------------------------------------------------------
    cout<<"TESTES PARA A QUESTAO 2 ------------------------------------------------"<<endl;

    cout<<"Valor esperado: 83,   "<<"Valor obtido: "<<arv.somaIntervalo(10, 19)<<endl;
    cout<<"Valor esperado:  0,   "<<"Valor obtido: "<<arv.somaIntervalo(25, 30)<<endl;
    cout<<"Valor esperado: 55,   "<<"Valor obtido: "<<arv.somaIntervalo(16, 22)<<endl;

    cout << endl << endl;
    // -----------------------------------------------------------------------------


    cout<<"TESTES PARA A QUESTAO 3 ------------------------------------------------"<<endl;
    arv.removeNo(24);
    arv.removeNo(20);
    arv.removeNo(15);
    arv.removeNo(12);
    arv.removeNo(11);
    arv.removeNo(-19);

    cout<<"ABB em ordem esperada: 6 7 8 9 10 11 15 17 18 20."<<"   ABB obtida: ";

    arv.imprime();
    cout << endl << endl;
    // -----------------------------------------------------------------------------
    return 0;
}
