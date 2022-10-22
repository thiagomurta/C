#include <cstdlib>
#include <iostream>
#include "Atividade3.cpp"
#include "Atividade3.h"

using namespace std;

int main(int argc, char** argv) {
    int p;
    cout << "Digite o número de valores que deseja fazer a média: ";
    cin >> p;
    Atividade3 atv(p);
    cout << "A média é:" << atv.getM();
    return 0;
}