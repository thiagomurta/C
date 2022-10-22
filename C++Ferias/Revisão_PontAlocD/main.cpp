#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int* encontraMaior(int n1, int n2, int *t, int *m){
    *t = 0;
    if(n2 <= n1){
        return NULL;
    }
    *t = n2 - n1;
    int *r = new int[*t];
    cin >> r[0];
    *m = r[0];
    for(int i = 1; i < *t; i++){
        cin >> r[i];
        if(r[i] > *m){
            *m = r[i];
        }
    }
    return r;
}

int main(){
    int n1, n2, t, m, *r;
    cin >> n1 >> n2;
    r = encontraMaior(n1, n2, &t, &m);
    for (int i = 0; i < t; i++)
    {
        cout << r[i] << endl;
    }
    cout << endl;
    cout << m << endl;
    delete [] r;
    return 0;
}