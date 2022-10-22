#include <iostream>
#include "ListaEncad.h"
#include "No.h"

using namespace std;

int main()
{
    ListaEncad lista;

    lista.insereInicio(20);
    lista.insereInicio(30);
    lista.insereInicio(-10);
    lista.insereInicio(15);

    lista.imprimir();

    lista.removeInicio();

    lista.imprimir();

    lista.insereFinal(90);
    lista.insereFinal(98);
    lista.imprimir();

    lista.removeFinal();
    lista.removeFinal();
    lista.removeFinal();

    lista.imprimir();
    return 0;
}