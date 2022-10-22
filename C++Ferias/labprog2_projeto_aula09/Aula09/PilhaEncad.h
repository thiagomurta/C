#ifndef PILHAENCAD_H_INCLUDED
#define PILHAENCAD_H_INCLUDED
#include "No.h"

using namespace std;

class PilhaEncad
{
private:
    No *topo;                /// ponteiro p/ o No do topo
    int n;
public:
    PilhaEncad();
    ~PilhaEncad();
    int getTopo();           /// retorna valor do No do topo
    void empilha(int val);   /// insere No no topo
    int desempilha();        /// elimina No do topo
    bool vazia();            /// verifica se est� vazia
    int tamanho(){return n;};
    void imprime();
    void removeDaPilha(PilhaEncad *p, int x);
};

#endif // PILHAENCAD_H_INCLUDED
