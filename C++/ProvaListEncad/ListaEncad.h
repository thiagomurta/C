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

    void imprimeElemsEmOrdem(); //ordena os elementos em ordem crescente
    bool inserePosicaoVal(int k,int val); // insere um valor val na posição k
    void imprimir();
    int* menorProximo(); //se o anterior for maior que o próximo uma nova lista com o valor 1 para o menor e 0 para o maior
    int getComprimento(); //número de elementos na lista
    int contaMaiores(int val); //número de nós que possuem o valor maior que val
    void insereOrdenado(int val); //não consegui, mas ele aloca um novo nó em ordem crescente
    //No* endereco(int k); /// não da certo
    ///Exercício 8
    bool igual(ListaEncad* l2);// verifica se duas listas são iguais
    ///Exercício 10
    void removeValor(int val); // remove as ocorrências do valor val

    void reduz_n(int n1);

private:
    No *primeiro;  /// ponteiro para o primeiro No da lista
    No *ultimo;    /// ponteiro para o ultimo No da lista
    int n;         /// numero de nos na lista
};
#endif
