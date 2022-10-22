#include <iostream>
#include <cstdlib>
#include "MatrizEspecial.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q3
MatrizEspecial::MatrizEspecial(int nn)
{
    // Implemente aqui sua solucao!
    // Se necessario remova o codigo abaixo.
    n = 0;
}
MatrizEspecial::~MatrizEspecial()
{
    // Implemente aqui sua solucao!
}

bool MatrizEspecial::verificaIndice(int i, int j)
{
    // Implemente aqui sua solucao!
    // Se necessario remova o codigo abaixo.
    return false;
}

float MatrizEspecial::get(int i, int j)
{
    // Implemente aqui sua solucao!
    // Se necessario remova o codigo abaixo.
    return 0;
}

void MatrizEspecial::set(int i, int j, float val)
{
    // Implemente aqui sua solucao!
}
//-Q3
// ----------------------------------------------------------------------------

void MatrizEspecial::imprimir()
{
    cout << "Matriz " << n << "x" << n << ":" << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout << get(i, j) << "\t";
        cout << endl;
    }
    cout << endl;
}
