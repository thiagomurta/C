#include <iostream>
#include "Rota.h"

using namespace std;

Rota::Rota(int nn){
    if(nn < 2){
        cout << "A rota tem que ter ao menos 2 pontos!";
        exit(1);
    }
    n = nn;
    tempos = new float[n-1];
}
Rota::~Rota(){
    delete [] tempos;
}
void Rota::leTempos(){
    for(int i=0;i < n; i++){
        cin >> tempos[i];
        while(tempos[i] < 0){
            cout << "Digite um tempo válido!";
            cin >> tempos[i];
        }
    }
}
float Rota::tempoTotal(){
    float total = 0;
    for (int i = 0; i < n; i++)
    {
        total += tempos[i];
    }
    int horas = (int)total;
    int minutos = (int)((total - horas)*60);
    cout << "O tempo total foi de: " << horas << " horas e " << minutos << " minutos" << endl;
    return total;
}