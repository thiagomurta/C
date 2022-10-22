#ifndef LISTADUPLA_H_INCLUDED
#define LISTADUPLA_H_INCLUDED
#include "NoDuplo.h"

class ListaDupla
{
public:
    ListaDupla();
    ~ListaDupla();
    bool busca(int val);
    int get(int k);
    void set(int k, int val);
    void insereInicio(int val);
    void removeInicio();
    void insereFinal(int val); /// exercicio
    void removeFinal();        /// exercicio
    //
    void imprime();
    void imprimeReverso();
    //fiz para testar
    void removeValor(int val);
    void inserek(int k, int val);
    void removek(int k);
    ListaDupla* concatena(ListaDupla *l2);
    ListaDupla* concatena2(ListaDupla *l2);
    ListaDupla* partir(int x);
    ListaDupla* partir2(int x);
    //teste
    void removeDepoisMaior();
    ListaDupla* criaListaMenorMaior();
    void insereDepoisMenor(int val);
    int getComprimento(){return n;};
    void reduz_n(int n1);

    void removeEntre(NoDuplo* p, NoDuplo* q);
    void remove1Ocorrencia(int val);
    void removeOcorrencias(int val);
private:
    NoDuplo *primeiro;
    NoDuplo *ultimo;
    int n;
};
#endif