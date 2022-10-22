#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int fatorial(int n){
    if(n == 0){
        return 0;
    }
    else if( n == 1){
        return 1;
    }
    else{
        return n * fatorial(n-1);
    }
}

void imprimeIntervalo(int a, int b, int inc){
    if(a < b){
        cout << a << " ";
        return imprimeIntervalo(a + inc,b,inc);
    }
    else{
        exit(1);
    }
}

void imprimeDecrescente(int n){
    if(n >=0 ){
        cout << n << " ";
        return imprimeDecrescente(n-1);
    }
    else{
        cout << endl;
        exit(1);
    }
}

float soma(int n, float vet[]){
    if(n >= 0){
        return vet[n] + soma(n - 1, vet);
    }
    else{
        return 0;
    }
}

float menor(int n, float vet[]){
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

int contaPares(int n, int vet[]){
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
            return 1 + contaPares(n - 1, vet);
        }
        else{
            return contaPares(n - 1, vet);
        }
    }
}

string binario(int n){
    string v;
    if(n != 0){
        v += binario(n/2);
        if(n % 2 == 0){
            v += '0';
        }
        else{
            v += '1';
        }
    }
    return v;
}

int main(){
    ///Recursividade
    /// 1
    /*
    int min, n, m = 0;
    cin >> n;
    cout << "Fatorial de " << n << ": " << fatorial(n) << endl;
    */
    /// 2
    /*
    int a, b, inc;
    cin >> a;
    cin >> b;
    cin >> inc;
    imprimeIntervalo(a, b, inc);
    */
    /// 3
    /*
    int n;
    cin >> n;
    imprimeDecrescente(n);
    */
    /// 4
    /*
    int n;
    float* vet;
    cin >> n;
    vet = new float[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    cout << soma(n,vet) << endl;
    delete [] vet;
    */
    /// 5
    /*
    int n;
    float* vet;
    cin >> n;
    vet = new float[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    cout << menor(n,vet) << endl;
    delete [] vet;
    */
    /// 6
    /*
    int n;
    int* vet;
    cin >> n;
    vet = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    cout << "Resultado: " << contaPares(n, vet) << endl;
    delete [] vet;
    */
    /// 7
    /*Fazer as mesmas questões mas sem recursão*/
    /// binario
    string v = binario(4);
    cout << v << endl;
    return 0;
}