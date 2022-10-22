#include <iostream>
#include "Rota.h"
#include "Rota.cpp"

using namespace std;

int main()
{
    int nn;
    cout << "Digite o número de pontos a calcular:";
    cin >> nn;
    Rota rota(nn);
    rota.leTempos();
    rota.tempoTotal();
    return 0;
}