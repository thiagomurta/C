#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int * pt = new int; // aloca espaco p/ int
    *pt = 202; // armazena valor
    cout << "valor do int = " << *pt;
    cout << ": endereco = " << pt << endl;
    // ...
    double * pd = new double; // aloca espaco
    *pd = 10000001.0; // armazena valor
    cout << "valor do double =" << *pd;
    cout << ": endereco = " << pd << endl;
    cout << "endereco do ponteiro pd: ";
    cout << &pd << endl;
    // ...
   return 0;
}