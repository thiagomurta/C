#include <iostream>
#include "Data.cpp"
#include "Data.h"

using namespace std;

int main(){
    cout << "RODANDO"<< endl;
    int d, m, a;
    cin >> d >> m >> a;

    Data data1(d,m,a);
    Data* data2 = data1.somaAnos(12);
    data2->imprime();
    delete data2;
    return 0;
}