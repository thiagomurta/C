#include <iostream>
#include <iomanip>

using namespace std;

bool func(int tam, int vet[], int *par, int *impar, int *neg){
    for (int i = 0; i < tam; i++)
    {
        if (vet[i] < 0)
        {
            (*neg)++;
        }
        
        if (vet[i]%2==0)
        {
            (*par)++;
        }

        else
        {
            (*impar)++;
        }
    }
    if((*neg) > 0){
        return true;
    }
    else{
        return false;
    }
}

float calcMedia(int n, float vet[]){
    float soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += vet[i];
    }
    return soma / n;
}

float* alocaVetor(int n){
    float *vet = new float[n];
    return vet;
}

int main(){
    /// 3
    /*
    int tam, *vet, par = 0, impar = 0, negativos = 0;
    cout << "Digite o tamanho do vetor: ";
    cin >> tam;
    vet = new int[tam];
    for (int i = 0; i < tam; i++)
    {
        cin >> vet[i];
    }
    if(func(tam, vet, &par, &impar, &negativos)){
        cout << "TRUE" << endl;
    }
    else{
        cout << "FALSE" << endl;
    }
    cout << "Pares: " << par << endl;
    cout << "Ímpares: " << impar << endl;
    cout << "Negativos: " << negativos << endl;
    delete [] vet;
    */
    /// 4
    /*
    int n;
    float *vet, soma = 0;
    cout << "Digite o tamanho do vetor: ";
    cin >> n;
    vet = new float[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
        soma += vet[i];
    }
    cout << "A média é: " << soma / n << endl;
    delete [] vet;
    */
    /// 5
    /*
    int n;
    float *vet;
    cout << "Digite o tamanho do vetor: ";
    cin >> n;
    vet = new float[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    cout << "A média é: " << calcMedia(n,vet) << endl;
    delete [] vet;
    */
    /// 6
    /*
    int n;
    float *vet;
    cout << "Digite o tamanho do vetor: ";
    cin >> n;
    vet = alocaVetor(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    cout << "A média é: " << calcMedia(n,vet) << endl;
    delete [] vet;
    */
}