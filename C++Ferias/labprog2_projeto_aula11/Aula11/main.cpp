#include <iostream>
#include "ArvBinBusca.h"
#include "ArvBinBusca.cpp"

using namespace std;

int main()
{
    ArvBinBusca arv;

    cout << "Criando Arvore Binaria de Busca (ABB)" << endl;
    arv.insere(15);
    arv.insere(9);
    arv.insere(20);
    arv.insere(7);
    arv.insere(11);
    arv.insere(18);
    arv.insere(24);
    arv.insere(6);
    arv.insere(8);
    arv.insere(10);
    arv.insere(12);
    arv.insere(17);
    arv.insere(19);
    arv.imprime();
    cout << endl;

    cout << "Media do caminho ate o no com valor 18: " << arv.mediaCaminho(18) << endl;

    cout << "Busca o valor 20: " << arv.busca(20) << endl;
    cout << "Busca o valor  5: " << arv.busca(5) << endl;
    cout << endl;

    cout << "Removendo os valores 24, 6, 7, 12, 18, 5." << endl;
    arv.remove(24);
    arv.remove(6);
    arv.remove(7);
    arv.remove(12);
    arv.remove(18);
    arv.remove(5);
    cout << endl;

    cout << "Arvore Binaria de Busca final:" << endl;
    arv.imprime();

    cout << "\t\t\t\t\t\t----------------------OPERAÇÕES----------------------" << endl;
    cout << "Árvore Binária de Busca: ";
    if(arv.eABB()){
        cout << "TRUE";
    }
    else{
        cout << "FALSE";
    }
    cout << endl;
    cout << "Filhos de 9: "; 
    arv.imprimeFilhos(9);
    cout << endl;
    cout << "Intervalo entre 9 e 20 na ABB: ";
    arv.imprimeIntervalo(9, 20);
    cout << endl;
    cout << "Imprimindo Crescente: ";
    arv.imprimeCrescente();
    cout << endl;
    cout << "Imprimindo Decrescente: ";
    arv.imprimeDecrescente();
    cout << endl;
    /*
    NoArv* p = arv.buscaValor();
    cout << "p: " << p->getInfo();
    */
    cout << "Nós com apenas 1 filho: " << arv.nos1Filho() << endl;
    cout << "Nós com 2 filho: " << arv.nos2Filho() << endl;
    cout << "Número de nós da árvore: " << arv.contaNos() << endl;
    cout << "Classificação do nó de valor 9: " << arv.classificaNo(9) << endl;
    /*
    int* vet = arv.insereVetorCrescente();
    int i = 0;
    cout << "Vetor em ordem crescente: ";
    while(i < arv.contaNos()){
        cout << vet[i] << " ";
        i++;
    }
    cout << endl;
    cout << "Insere vetor em ordem crescente: ";
    int v[5];
    int k = 0;
    for(int i = 0; i < 5; i++){
        v[i] = k;
        k +=10;
    }
    cout << v[0];
    arv.insereDoVetor(5, v);
    */
    arv.imprime();
    cout << endl;
    cout << "\t\t\t\t\t\t----------------------OPERAÇÕES----------------------" << endl;
    //arv.remove1Filho(17);
    //arv.imprime();

    return 0;
}

