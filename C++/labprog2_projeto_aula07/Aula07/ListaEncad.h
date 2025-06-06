#ifndef LISTAENCAD_H_INCLUDED
#define LISTAENCAD_H_INCLUDED
#include "No.h"

class ListaEncad
{
public:
    ListaEncad();
    ~ListaEncad();
    bool busca(int val);        /// retorna true caso val esteja na lista e false caso contrario
    int get(int k);             /// retorna o valor do k-�simo elemento
    void set(int k, int val);   /// altera o valor do k-�simo elemento
    void insereInicio(int val); /// insere um novo No contendo val no in�cio da lista
    void insereFinal(int val);  /// insere um novo No contendo val no final da lista
    void removeInicio();        /// remove o primeiro No da lista
    void removeFinal();         /// remove o �ltimo No da lista

    void imprimeElemsEmOrdem();
    bool inserePosicaoVal(int k,int val);
    void imprimir();
    int* menorProximo();
    int getComprimento();
    int contaMaiores(int val);
    void insereOrdenado(int val);
    //No* endereco(int k); /// não da certo
    ///Exercício 8
    bool igual(ListaEncad* l2);
    ///Exercício 10
    void removeValor(int val);
    void reduz_n(int n1);

private:
    No *primeiro;  /// ponteiro para o primeiro No da lista
    No *ultimo;    /// ponteiro para o ultimo No da lista
    int n;         /// numero de nos na lista
};
#endif
