#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int somatorio(int n){
    if(n > 0){
        return n + somatorio(n-1);
    }
    else{
        return 0;
    }
}

int menor(int n, int vet[]){
    if(n == 1){
        return vet[0];
    }
    else{
        int m = menor(n-1, vet);
        if(vet[n-1] < m){
            return vet[n-1];
        }
        else{
            return m;
        }
    }
}

int somaVet(int n, int vet[]){
    if(n == 1){
        return vet[0];
    }
    else{
        return vet[n-1] + somaVet(n - 1, vet);
    }
}

int contaPar(int n, int vet[]){
    if(n == 1){
        if(vet[0] % 2 == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(vet[n-1] % 2 == 0){
            return 1 + contaPar(n - 1, vet);
        }
        else{
            return contaPar(n - 1, vet);
        }
    }
}

int main(){
    /// 1
    /*
    int n;
    cin >> n;
    cout << "Somatório: " << somatorio(n) << endl;
    */
    /// 2
    /*
    int n, *vet;
    cin >> n;
    vet = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    cout << "Menor vetor: " << menor(n, vet) << endl;
    */
    /// 3
    /*
    int n, *vet;
    cin >> n;
    vet = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    cout << "Resultado da soma de vetores: " << somaVet(n, vet) << endl;
    */
    /// 4
    /*
    int n, *vet;
    cin >> n;
    vet = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    cout << "Vetores pares: " << contaPar(n, vet) << endl;
    */
    /// 5
    return 0;
}