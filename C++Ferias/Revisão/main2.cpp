#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void divisao(int num, int div, int *q, int *r){
    *r = num % div;
    *q = num / div;
}

bool func(int tam, int vet[], int *par, int *impar, int *negativos){
    for (int i = 0; i < tam; i++)
    {
        if (vet[i] < 0)
        {
            (*negativos)++;
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
    if((*negativos) > 0){
        return true;
    }
    else{
        return false;
    }
}

float prodEscalar(int n, float x[], float y[]){
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += x[i] * y[i];
    }
    return res;
}

int main(){
    /// Ponteiros
    /// 1
    /*
    int *pt;
    cout << "Endereço de pt: " << &pt << endl;
    int x;
    cin >> x;
    pt = &x;
    cout << "Variável pt: " << *pt << endl;
    cout << "Variável x: " << x << endl;
    *pt = x * 10;
    cout << "Variável x: " << x << endl;
    *pt = *pt + 10;
    cout << "Variável pt somado +10: " << *pt << endl;
    */
    /// 2
    /*
    int a, b;
    cin >> a;
    cin >> b;
    cout << "Valor 1:" << a << endl << "Valor 2: " << b << endl;
    troca(&a, &b);
    cout << "Novo valor 1:" << a << endl << "Novo valor 2: " << b << endl;
    */
    /// 3
    /*
    int num, div, q, r;
    cout << "Numerador: ";
    cin >> num;
    cout << "Divisor: ";
    cin >> div;
    divisao(num, div, &q, &r);
    cout << "Quociente: " << q << endl;
    cout << "Resto: " << r << endl;
    */
    /// 4
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
    /// 5
    /*
    int n, *vet, somat = 0;
    cout << "Digite o tamanho do vetor: ";
    cin >> n;
    vet = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
        somat += vet[i];
    }
    float media;
    media = somat/n;
    cout << "A média é: " << media << endl;
    delete [] vet;
    */
    /// 6
    /*
    int n;
    float *x, *y;
    cout << "Digite o tamanho do vetor: ";
    cin >> n;
    x = new float[n];
    y = new float[n];
    int j = 1;

    for (int i = 0; i < n; i++)
    {
        cout << "Digite o " << j << "º valor para x: ";
        cin >> x[i];
        j++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Digite o " << j << "º valor para y: ";
        cin >> y[i];
        j++;
    }

    cout << "Resultado: " << prodEscalar(n, x, y) << endl;
    */
}