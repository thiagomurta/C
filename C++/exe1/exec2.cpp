#include <iostream>
#include <iomanip>

using namespace std;

void geraValores(int min, int n, int v[], int *tam){
    int i=1;
    if(*v>=min){
        *v = *v/2;
        geraValores(min,n,*v+i, tam+i);
    }
}

int main(){
    int min, n, *v, tam;
    cout << "Digite um inteiro: ";
    cin >> min;
    cout << "Digite um inteiro: ";
    cin >> n;
    tam=0;
    v = new int [200];
    geraValores(min, n, v, &tam);
    cout << "ORDEM DECRESCENTE: "<< endl;
    for(int i=0;i<tam;i++){
        cout << "Valor "<< i <<": "<< v[i] << endl;
    }
    cout << endl << endl;
    cout << "ORDEM CRESCENTE: "<< endl;
    for(int j=0;j<=tam;tam--){
        cout << "Valor "<< tam <<": "<< v[tam] << endl;
    }
    delete []v;
}