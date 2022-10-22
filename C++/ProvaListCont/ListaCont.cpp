#include <iostream>
#include <stdlib.h>

#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont(int tam)
{
    //ctor
    max = tam;
    n = 0;
    inicio = max/2;  ///poderia ser em qq posi��o (0 e max-1).
    vet = new int[max];
}



ListaCont::~ListaCont()
{
    //dtor
    delete [] vet;
}


int ListaCont::get(int k)
{
    if(valido(k))
        return vet[k];
    else
    {
        cout<<"ERRO: indice invalido"<<endl;
        exit(1);
    }
}

void ListaCont::set(int k, int val)  ///altera valor na posicao k
{///altera o valor da posi�ao k para novo valor val
    if(valido(k))
        vet[k] = val;
    else
    {
        cout<<"ERRO: indice invalido"<<endl;
        exit(1);
    }
}

void ListaCont::insereFinal(int val)
{
   if(ultimo() == max - 1)
        realoca(); ///aumenta a capacidade do vetor suporte da lista

    vet[ultimo() + 1] = val;
    n = n + 1;
}

void ListaCont::realoca()
{
    max = max + 50;  ///max + max*10/100; ou max*1.1
    int *auxVet = new int[max];

    ///copia vet para auxVet
    for(int i=inicio; i<=ultimo(); i++)
        auxVet[i] = vet[i];

    delete [] vet;

    vet = auxVet;
}

void ListaCont::insereK(int k, int val)
{
    if(ultimo() == max - 1)
        realoca(); ///aumenta a capacidade do vetor suporte da lista
    if(n == 0)
    {
        if(k>=0 && k<max)
        {
            inicio = k;
            vet[k] = val;
            n++;
        }
        else
            cout<<"ERRO: indice invalido (vetor)"<<endl;
    }
    else if(valido(k))
    {
        for(int i=ultimo(); i>=k; i--)
            vet[i+1] = vet[i];
        vet[k] = val;
        n = n + 1;
    }
    else
    {
        cout<<"ERRO: indice invalido"<<endl;
        exit(2);
    }
}

void ListaCont::insereInicio(int val)
{
    if(n == 0)
    {///lista vazia. Ser� unico elemento da lista
        inicio = max/2; ///poderia ser em qualquer posição de max
        vet[inicio] = val;
        n++;
    }
    else if(inicio > 0)  ///verifica se tem folga no come�o do vetor
    {
        inicio = inicio - 1;
        vet[inicio] = val;
        n++;
    }
    else
    {
        cout<<"Nao ha folga no inicio do vetor";
        exit(3);
    }
}

void ListaCont::removeFinal()
{
    if(n == 0)
    {
        cout<<"Erro: lista vazia";
        exit(4);
    }
    n = n - 1;
    if(n == 0)
        inicio = max/2;
}

void ListaCont::removek(int k)
{
    if(valido(k))
    {
        for(int i=k; i<=ultimo() - 1; i++)  ///desloca para direita
            vet[i] = vet[i + 1];
        n--;

        if(n == 0)
            inicio = max/2;
    }
    else
    {
        cout<<"Erro: indice invalido ou lista vazia";
        exit(5);
    }
}
void ListaCont::removeInicio()
{
    if(n == 0)
    {
        cout<<"Erro: lista vazia";
        exit(6);
    }
    else  ///lista n�o est� vazia
    {
        inicio++;
        n--;

        if(n == 0)
            inicio = max/2;
    }
}

void ListaCont::imprime()
{
    if(n!=0){
        for(int i=inicio; i<=ultimo(); i++){
            cout<< vet[i] << " ";
        }
        cout<<endl;
    }
    else{
        cout << "Lista Vazia" << endl;
    }
}

ListaCont* ListaCont::copiar(int val){
    int j = -1;
    for(int i=inicio; i<= ultimo(); i++){
        if(vet[i]==val){
            j = i;
            break;
        }
    }
    ListaCont* p = new ListaCont(max);
    if(j!=-1){
        for (int i = j; i <= ultimo(); i++)
        {
            p->insereFinal(get(i));
        }
        for (int i = j; i <= ultimo();)
        {
            removeFinal();
        }
    }
    return p;
}
///QUESTÃO 5.3
void ListaCont::insereValores(int tam, int v[]){
    max = max + tam;
    int *vetAux = new int[max]; ///aloca um novo vetor auxiliar

    ///copia os elementos da lista deslocando tam posições
    for (int i = 0; i < n; i++)
    {
        vetAux[i + tam] = vet[i];
    }

    ///copia os elementos de v para vetAux
    for (int i = 0; i < tam; i++)
    {
        vetAux[i] = v[i];
    }

    n = n + tam; ///atualiza o número de elementos da lista

    ///libera vet e atualiza como vetAux
    delete [] vet;
    vet = vetAux;
}
///QUESTÃO 5.6
void ListaCont::intercala(ListaCont *la, ListaCont *lb){
    ///Limpar a lista
    delete [] this->vet;
    ///
    n = 0;
    max = la->max + lb->max;

    this->vet = new int[this->max];

    while(la->n > 0 && lb->n > 0){
        ///adiciona o primeiro de cada uma das listas
        this->insereFinal(la->vet[0]);
        this->insereFinal(lb->vet[0]);
        ///remove o primeiro de cada uma das listas
        la->removeInicio();
        lb->removeInicio();
    }

    //Caso tenham tamanhos diferentes, copia o restante da maior lista

    while(la->n > 0){
        this->insereFinal(la->vet[0]);
        la->removeInicio();
    }

    while(lb->n > 0){
        this->insereFinal(lb->vet[0]);
        lb->removeInicio();
    }
}

bool ListaCont::troca (int posicao1 , int posicao2 ){
    int aux;
    if(posicao1>=inicio && posicao2<=ultimo()){
        aux = vet[posicao1];
        set(posicao1,vet[posicao2]);
        set(posicao2,aux);
        /*
        aux = posicao1;
        posicao1 = posicao2;
        posicao2 = aux;*/
        return true;
    }
    else{
        return false;
    }
}

bool ListaCont::aumentaCapacidade(int novoMax){
    if(novoMax>max){
        max = novoMax;
        int *auxVet = new int[max];
        
        ///copia vet para auxVet
        for(int i=inicio; i<=ultimo(); i++)
            auxVet[i] = vet[i];

        delete [] vet;

        vet = auxVet;
            return true;
    }
    else{
        return false;
    }
}

int ListaCont::numNos(){
    return n;
}

void ListaCont::limpar(){
    n=0;
}
int ListaCont::buscaMaior(int val){
    int i;
    for(i=0;i<n;i++){
        if(vet[i]>val){
            return i;
        }
    }
    return -1;
}

/*void ListaCont::removeMultiplos(int val){
    float res;
    int *auxVet = new int[max];

    //copia os dados para auxiliar
    for(int i = inicio; i <= ultimo() ; i++){
        auxVet[i] = vet[i];
    }

    for(int i = inicio; i <= ultimo(); i++){
        res = auxVet[i] % val;
        if((int)res == 0){
            if(i==ultimo()){//ultima posição
                removeFinal();
            }
            else if(i==inicio){//primeira posição
                removeInicio();
            }
            else{//meio
                auxVet[i] = auxVet[i+1];
                n--;
            }
        }
        else{
            auxVet[i] = get(i);
        }
    }
   delete [] vet;
   vet = auxVet;
}*/
void ListaCont::removeMultiplos(int val){
    float res;
    int *auxVet = new int[max];

    //copia os dados para auxiliar
    for(int i = inicio; i <= ultimo() ; i++){
        auxVet[i] = vet[i];
    }


    for(int i = inicio; i <= ultimo(); i++){
        if(auxVet[i] % val == 0){
            if(i==ultimo()){//ultima posição
                removeFinal();
            }
            else if(i==inicio){//primeira posição
                removeInicio();
            }
            else{//meio
                auxVet[i] = auxVet[i+1];
                n--;
            }
        }
        else{
            auxVet[i] = get(i);
        }
    }
    for(int i = inicio; i <= ultimo(); i++){
        res = auxVet[i] % val;
        if(res==0){
            removek(i);
        }
        else{
            vet[i] = auxVet[i];
        }
    }
}