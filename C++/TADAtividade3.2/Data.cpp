#include <iostream>
#include "Data.h"

using namespace std;

Data::Data(int d,int m,int a){
    setDiaMesAno(d,m,a);
}

Data::~Data(){
}

void Data::setDiaMesAno(int d, int m, int a){
    dia = 1;
    if(d>=1 && d<=30){
        dia = d;
    }
    mes = 1;
    if(m>=1 && m<=12){
        mes = m;
    }
    ano = 1000;
    if(a>0){
        ano = a;
    }
}

void Data::imprime(){
    if(dia<10){
        cout << "0"<< dia <<"/";
    }
    else{
        cout << dia << "/";
    }
    if(mes<10){
        cout << "0"<< mes <<"/";
    }
    else{
        cout << mes << "/";
    }
    if(ano<10){
        cout << "000"<< ano;
    }
    if(ano<100){
        cout << "00" << ano;
    }
    if(ano<1000){
        cout << "0" << ano;
    }
    else{
        cout << ano;
    }
}

Data* Data::somaAnos(int nAnos){
    Data* aux = new Data(dia, mes, ano + nAnos);
    return aux;
}