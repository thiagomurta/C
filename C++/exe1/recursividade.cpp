#include <iostream>
#include <iomanip>

using namespace std;

int somatorio(int n){
    if(n==0){
        return 0;
    }
    else if(n<0){
        return somatorio(-n);
    }
    else{
        return n + somatorio(n-1);
    }
}

int compara(float vet[], int n){
    int k;
    if(vet[n]==vet[n-1]){
        return k = compara(vet,n-1);
    }
    else if(n<0){
        return k= compara(vet,-n);
    }
    else if(vet[n]>vet[n-1]){
        return k = compara(vet,n-1);
    }
    else{
        return n;
    }
}

float somavetor(int vet[], int n){
    if(n==0){
        return vet[n];
    }
    else if(n<0){
        return somavetor(vet,-n);
    }
    else{
        return vet[n] + somavetor(vet,n-1);
    }
}

int par(int vet[], int n){
    int i;
    if(n==0){
        i = vet[n]%2;
        if(i==0){
            return 1;
        }
        else{
            i=0;
        }
    }
    else if(vet[n]%2==0){
        return 1+ par(vet,n-1);
    }
    else if(n<0){
        return par(vet,-n);
    }
    else if(vet[n]%2==1){
        return par(vet,n-1);
    }
}

int main(){
    /*EXERCÍCIO 1*/
    /*
    int n,j;
    cout << "Digite um número inteiro: ";
    cin >> n;
    j=somatorio(n);
    cout << j << endl;
    */
    /*EXERCÍCIO 2*/
    /*
    int n, j;
    cout << "Digite o número de vetores: ";
    cin >> n;
    float *vet = new float[n];
    for(int i=0;i<n;i++){
        cout << "Digite o valor do vetor " << i <<": ";
        cin >> vet[i];
    }
    j = compara(vet,n);
    cout << "O menor valor eh " << vet[j];
    delete [] vet;
    */
    //VOLTAR DEPOIS!!!!!!
    /*EXERCÍCIO 3*/
    /*
    int n;
    float j;
    cout << "Digite o número de vetores: ";
    cin >> n;
    float *vet = new float[n];
    for(int i=0;i<n;i++){
        cout << "Digite o valor do vetor " << i <<": ";
        cin >> vet[i];
    }
    j = somavetor(vet,n);
    cout << "A soma dos vetores é: " << j << endl;
    delete [] vet;
    */
    /*EXERCÍCIO 4*/
    int n, j;
    cout << "Digite o número de inteiros que irá calcular: ";
    cin >> n;
    int *vet = new int[n];
    for(int i=0;i<n;i++){
        cout << "Digite o valor do inteiro " << i <<": ";
        cin >> vet[i];
    }
    j = par(vet,n);
    cout << "O número de valores pares é: " << j << endl;
    delete [] vet;
    return 0;
}