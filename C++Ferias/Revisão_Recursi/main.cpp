#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void geraValores(int min, int n, int v[], int *tam){
    if(n <= 0){
        return;
    }
    if(n < min){
        return;
    }
    v[*tam] = n;
    (*tam)++;
    geraValores(min, n/2, v, tam);
    v[*tam] = n;
    (*tam)++;
}

int main(){
    int min, n, m = 0;
    cin >> min >> n;
    int *vet = new int[n/2];
    geraValores(min, n, vet, &m);
    for(int i = 0; i < m; i++){
        cout << vet[i] << " ";
    }
    delete [] vet;
    return 0;
}