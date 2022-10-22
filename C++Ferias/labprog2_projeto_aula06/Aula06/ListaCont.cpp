#include <iostream>
#include <cstdlib>
#include "Ponto.h"
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont(int tam)
{
    cout << "Criando objeto ListaCont" << endl;
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaCont::~ListaCont()
{
    cout << "Destruindo objeto ListaCont" << endl;
    delete [] vet;
}

int ListaCont::get(int k)
{
    if(k >= 0 && k < n)
        return vet[k];
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::set(int k, int val)
{
    if(k >= 0 && k < n)
        vet[k] = val;
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::insereFinal(int val)
{
    if(n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    vet[n] = val;
    n = n + 1;
}

void ListaCont::removeFinal()
{
    if(n == 0)
    {
        cout << "ERRO: Lista Vazia!" << endl;
        exit(1);
    }
    n = n - 1;
}

void ListaCont::insereK(int k, int val)
{
    if(n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    if(k >= 0 && k < n)
    {
        for(int i = n-1; i >= k; i--)
            vet[i+1] = vet[i];
        vet[k] = val;
        n = n + 1;
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::removeK(int k)
{
    if(k >= 0 && k < n)
    {
        for(int i = k; i < n-1; i++)
            vet[i] = vet[i+1];
        n = n - 1;
    }
    else
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
}

void ListaCont::insereInicio(int val)
{
    if(n == 0)
    {   //lista vazia. Sera o unico no da lista
        vet[n] = val;
        n = n + 1;
    }
    else
        insereK(0, val);
}

void ListaCont::removeMultiplos(int val){
    int *auxVet = new int[max];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if(vet[i] % val != 0){
            auxVet[j++] = vet[i];
        }
    }
    delete [] vet;
    vet = auxVet;
    n = j;
}

ListaCont* ListaCont::copiar(int valor){
    ListaCont* novaLista = new ListaCont(max);
    int j = -1;
    for(int i = 0;i < n; i++){
        if(vet[i] == valor){
            j = i;
            break;
        }
    }
    if(j != -1){
        for (int i = j; i < n; i++){
            novaLista->insereFinal(get(i));
        }
        for (int i = j; i < n;){
            removeFinal();
        }
    }
    return novaLista;
}

void ListaCont::removeInicio()
{
    removeK(0);
}

void ListaCont::imprime()
{
    cout << "[ ";
    for(int i = 0;i<n-1;i++){
        cout << get(i) << ", ";
    }
    cout << get(n-1) << " ]" << endl;
}

void ListaCont::inserirVet(int tam, int v[]){
    if(max == 0){
        max = tam;
        n = tam;
        for(int i = 0; i < tam; i++){
            vet[i] = v[i];
        }
    }
    else{
        max += tam;
        for(int i = n-1; i >= 0; i--){
            vet[i+tam] = vet[i];
        }
        n += tam;
        for(int i = 0; i < tam; i++){
            vet[i] = v[i];
        }
    }
}

void ListaCont::intercala(ListaCont *la, ListaCont *lb){
    delete [] this->vet;

    n = 0;
    max = la->max + lb->max;

    this->vet = new int[this->max];

    while(la->n > 0 && lb->n > 0){
        this->insereFinal(la->vet[0]);
        this->insereFinal(lb->vet[0]);
        la->removeInicio();
        lb->removeInicio();
    }

    while(la->n > 0){
        this->insereFinal(la->vet[0]);
        la->removeInicio();
    }

    while(lb->n > 0){
        this->insereFinal(lb->vet[0]);
        lb->removeInicio();
    }
}

bool ListaCont :: troca (int posicao1 , int posicao2 ){
    if(posicao1 < n && posicao2 < n){
        int aux = vet[posicao1];
        vet[posicao1] = vet[posicao2];
        vet[posicao2] = aux;
        return true;
    }
    return false;
}

bool ListaCont :: aumentaCapacidade (int novoMax ){
    if(novoMax > max){
        max = novoMax;
        int *aux = new int[max];
        for (int i = 0; i < n; i++)
        {
            aux[i] = vet[i];
        }
        delete [] vet;
        vet = aux;
        return true;
    }
    return false;
}

int ListaCont::buscaMaior(int val){
    int indMaior = -1;
    for( int i = 0; i < n; i++){
        if(get(i) > val){
            indMaior = i;
            break;
        }
    }
    if(indMaior != -1){
        return vet[indMaior];
    }
    else 
        return -1;
}

void ListaCont::limpar(){
    n = 0;
}

void ListaCont::insereValores(int tam, int vet2[]){
    if(max == 0){
        max = tam;
        n = 0;
        for( int i = 0; i < tam; i++ ){
            vet[n] = vet2[i];
            n++;
        }
    }
    if(max-n > tam){
        max += tam;
        for (int i = 0; i < tam; i++)
        {
            vet[n] = vet2[i];
            n++;
        }
    }
    else{
        cout << "Lista Cheia!" << endl;
        exit(1);
    }
}

ListaCont* ListaCont::divide(){
    ListaCont* novaLista = new ListaCont(max/2);
    int i = 0;
    while(i < max/2){
        novaLista->insereFinal(get(0));
        removeInicio();
        i++;
    }
    return novaLista;
}

int ListaCont::numNos(){
    return n;
}

int ListaCont::numMax(){
    return max;
}