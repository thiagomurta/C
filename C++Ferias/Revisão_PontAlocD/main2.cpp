#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void troca(int *a, int *b){
    int aux;
    aux = *b;
    *b = *a;
    *a = aux;
}

bool func(int tam, int vet[], int *par, int *impar, int *negativos){
    for(int i = 0; i < tam; i++){
        if(vet[i] >= 0){
            if(vet[i] % 2 == 0){
                (*par)++;
            }
            else{
                (*impar)++;
            }
        }
        else{
            (*negativos)++;
        }
    }
    return *negativos > 0;
}

void divisao(int num, int div, int *q, int *r){
    *q = num / div;
    *r = num % div;
}

float prodEscalar(int n, float x[], float y[]){
    float prod;
    for(int i = 0; i < n; i++){
        prod += x[i] * y[i];
    }
    return prod;
}

int main(){
    /// Ponteiro
    /// 1
    /*
    int *pt;
    cout << &pt << endl;
    int x;
    cin >> x;
    pt = &x;
    cout << *pt << endl << &x << endl;
    *pt = x * 10;
    cout << x << endl;
    *pt = *pt + 10;
    cout << *pt;
    */
    /// 2
    /*
    int n, m;
    cin >> n >> m;
    troca(&n, &m);
    cout << n << endl << m;
    */
    /// 3
    /*
    int num, div, q, r;
    cin >> num;
    cin >> div;
    divisao(num, div, &q, &r);
    cout << "Quociente: " << q << endl << "Resto: " << r << endl;
    */
    /// 4
    /*
    int negativos = 0, impar = 0, par = 0, tam, *vet;
    cin >> tam;
    vet = new int[tam];
    for(int i = 0; i < tam;i++){
        cin >> vet[i];
    }
    if(func(tam, vet, &par, &impar, &negativos)){
        cout << "TRUE" << endl;
    }
    else{
        cout << "FALSE" << endl;
    }
    cout << "Ímpares: " << impar << endl;
    cout << "Par: " << par << endl;
    cout << "Negativos: " << negativos << endl;
    delete [] vet;
    */
    /// 5
    /*
    int n, *vet;
    float tot = 0, media;
    cin >> n;
    vet = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
        tot += vet[i];
    }
    media = tot/n;
    cout << "Média: " << media << endl;
    delete [] vet;
    */
    /// 6
    /*
    float *x, *y, prod;
    int n;
    cin >> n;
    x = new float[n];
    y = new float[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }
    prod = prodEscalar(n,x,y);
    cout << "Produto Escalar: " << prod << endl;
    delete [] x;
    delete [] y;
    */
}