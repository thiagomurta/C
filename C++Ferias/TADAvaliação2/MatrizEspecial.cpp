#include <iostream>
#include "MatrizEspecial.h"

using namespace std;

MatrizEspecial::MatrizEspecial(int nn){
    n = nn;
    vet = new int [n];
}

MatrizEspecial::~MatrizEspecial(){
    delete [] vet;
}

int MatrizEspecial::getInd(int i, int j){
    if(i < n && i >= 0 && j < n && j >= 0 && i+j == 2){
        return -2;
    }
    else{
        return -1;
    }
}

int MatrizEspecial::get(int i, int j){
    int k = getInd(i,j);
    if(k==-2){
        return 0;
        cout << "ERRO"<<endl;
        exit(1);
    }
    else{
        return k;
    }
}

void MatrizEspecial::set(int i, int j, float val){
    int k = getInd(i,j);
    if(k==-2){
        cout << "ERRO" << endl;
        exit(1);
    }
    else{
        val = i + j;
    }
}