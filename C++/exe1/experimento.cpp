#include <iostream>

using namespace std;

void troca(int *x, int *y){
    int aux = *x;
    *x=*y;
    *y=aux;
}

string converteBinario(int n)
{
    if(n == 0)
        return "0";
    if(n == 1)
        return "1";
    if(n%2 == 0)
        return converteBinario(n/2) + "0";
    return converteBinario(n/2) + "1";
}

int main(){
    /*
    int x = 10, y = 21;
    cout << "Endereço de x: "<< &x << "Endereço de y: "<< &y << endl;
    troca(&x,&y);
    cout << x << " " << y << endl;
    int *p;
    cout << &p << endl;
    p = &x;
    cout <<"Endereço de x em p:"<< p << endl << "Valor de x salvo em *p: "<< *p << endl;
    *p = 42;
    p=new int[2];
    p[0] = 2;
    p[1] = 4;
    troca(p,p+1);
    cout << *p << *(p+1) << endl;
    delete [] p;
    */
    int n, j;
    cout << "Digite um número para se converter em binário: ";
    cin >> n;
    cout << converteBinario(n);
}