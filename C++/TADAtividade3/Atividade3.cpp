#include <iostream>
#include <cstdlib>
#include "Atividade3.h"

using namespace std;

Atividade3::Atividade3(int nn){
    n=nn;
    x = new int[n];
    setX();
}

void Atividade3::setX(){
    for (int i = 0; i < n; i++)
    {
        cout << "Digite o " << i+1 << "º valor para calcular: ";
        cin >> x[i];
    }
    setM();
}

Atividade3::~Atividade3(){
}

void Atividade3::setM(){
    m = 0;
    for (int i = 0; i < n; i++)
    {
        m = m + x[i];
    }
    m = m/n;
}

float Atividade3::getM(){
    return m;
}