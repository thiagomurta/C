#include <iostream>

using namespace std;

int* encontraMaior(int n1, int n2, int *t, int *m){
    *t = 0;
    int* r;
    if(n2>n1){
        *t = n2-n1;
        r = new int[*t];
        cin >> r[0];
        *m = r[0];
        for(int i = 1; i < *t; i++){
            cin >> r[i];
            if(*m < r[i]){
                *m = r[i];
            }
        }
        return r;
    }
    else{
        return NULL;
    }
}

void geraValores(int min, int n, int v[], int *tam){
    if(n < min){
        return;
    }
    if(n <= 0){
        return;
    }
    v[*tam] = n;
    (*tam)++;
    geraValores(min, n/2, v, tam);
    v[*tam] = n;
    (*tam)++;
}

int main(){
    /*
    int n1, n2, t, m, *r;
    cin >> n1 >> n2;
    r = encontraMaior(n1, n2, &t, &m);
    cout << "[";
    for (int i = 0; i < t; i++)
    {
        cout << r[i] << " ";
    }
    cout << "]" << endl;
    cout << "Maior valor: " << m << endl;
    delete [] r;
    */
    int min, n, tam = 0;
    cin >> min >> n;
    int* v = new int[n/2];
    geraValores(min, n, v, &tam);
    for (int i = 0; i < tam; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    delete [] v;
    return 0;
}