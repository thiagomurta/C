#include <iostream>
#include "Rota.h"

using namespace std;

Rota::Rota(int nn){
    if(nn < 2){
        cout << "A rota deve ter ao menos 2 pontos";
        exit(1);
    }
    n = nn;
    tempos = new float[n-1];
}
Rota::~Rota(){
    delete [] tempos;
}
void Rota::leTempos(){
    for(int i = 0;i < n-1; i++){
        cin >> tempos[i];
        while(tempos[i] < 0){
            cout << "Digite um valor válido (não negativo): ";
            cin >> tempos[i];
        }
    }
}
float Rota::tempoTotal(){
    float total = 0;
    for(int i = 0;i < n-1; i++){
        total += tempos[i];
    }
    int horas = (int)total;
    int minutos = int((total-horas) * 60);
    cout << "Tempo total: " << horas << " horas e " << minutos << " minutos" << endl;
    return total;
}