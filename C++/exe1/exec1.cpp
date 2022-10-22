#include <iostream>
#include <iomanip>

using namespace std;

int* encontraMaior(int n1, int n2, int *t, int *m){
    int maior=0;
    if(n2>n1){
        *t = n2 - n1;
        for(int i=0;i<*t;i++){
            cin >> m[i];
            if(m[maior]<m[i]){
                maior = i;
            }
        }
    }
    else{
        return NULL;
    }
}

int main(){
    int n1, n2, t, m, *j, i;
    cout << "Digite um valor inteiro: ";
    cin >> n1;
    cout << "Digite outro valor inteiro: ";
    cin >> n2;
    j = encontraMaior(n1, n2, &t, &m);
    j=new int[t];
    for(i=0;i<t;i++){
        cout << *(j+i) << endl;
    }
    delete []j;
}