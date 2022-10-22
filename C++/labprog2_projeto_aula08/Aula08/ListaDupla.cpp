#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"
#include "NoDuplo.h"

using namespace std;

ListaDupla::ListaDupla()
{
    cout << "Criando uma ListaDupla" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    cout << "Destruindo ListaDupla" << endl;
    NoDuplo *p = primeiro;
    while(p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaDupla::busca(int val)
{
    NoDuplo *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaDupla::get(int k)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
    else
        return p->getInfo();
}

void ListaDupla::set(int k, int val)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}

void ListaDupla::insereInicio(int val)
{
	NoDuplo *p = new NoDuplo();
	p->setInfo(val);
	p->setProx(primeiro);
	p->setAnt(NULL);

	if(n == 0){// || (ultimo == NULL) || (primeiro == NULL)
        ultimo = p;
    }
	else{
        primeiro->setAnt(p);
    }

	primeiro = p;
	n = n + 1;
}

void ListaDupla::removeInicio()
{
	NoDuplo *p = new NoDuplo();
	if(primeiro != NULL)
	{
		p = primeiro;
		primeiro = p->getProx();
		delete p;
		n = n - 1;

		if(n == 0){
            ultimo = NULL;
        }
		else{
            primeiro->setAnt(NULL);
        }
	}
	else{
        cout << "ERRO: lista vazia" << endl;
    }
}

// Atividades feitas em sala de aula
void ListaDupla::insereFinal(int val){
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setAnt(ultimo);
    p->setProx(NULL);
    if(primeiro == NULL){
        primeiro = p;
    }
    else{
        ultimo->setProx(p);
    }
    ultimo = p;
    n++;
}

void ListaDupla::removeFinal(){
    NoDuplo *p;
    if(ultimo != NULL)
	{
		p = ultimo;
		ultimo = p->getAnt();
		delete p;
        n--;

		if(n == 0){
            primeiro = NULL;
        }

		else{
            ultimo->setProx(NULL);
        }
	}
	else{
        cout << "ERRO: lista vazia" << endl;
    }
}

void ListaDupla::imprime(){
    NoDuplo* p = primeiro;
    if(p!=NULL){
        cout << "[ ";
        while(p!=NULL){
            cout << p->getInfo() << " ";
            p = p->getProx();
        }
        cout << "]";
        cout << endl;
    }
    else{
        cout << "ERRO: LISTA VAZIA" << endl;
    }
}

void ListaDupla::imprimeReverso(){
    NoDuplo* p = ultimo;
    if(p!=NULL){
        cout << "[ ";
        while(p!=NULL){
            cout << p->getInfo() << " ";
            p = p->getAnt();
        }
        cout << "]";
        cout << endl;
    }
    else{
        cout << "ERRO: LISTA VAZIA" << endl;
    }
}

void ListaDupla::removeValor(int val){
    NoDuplo* p = primeiro;
    while(p!=NULL){
        if(p->getInfo()==val){
            //se for o primeiro nó
            if(p->getAnt()==NULL){
                this->removeInicio();
            }
            //se for o ultimo nó
            else if(p->getProx() == NULL){
                this->removeFinal();
            }
            //se for intermediário
            else{
                NoDuplo* aux = p;
                p = p->getAnt();
                p->setProx(p->getProx()->getProx());
                p->getProx()->setAnt(p);
                delete aux;
                n--;


                /*NoDuplo* aux = p;
                //p->setInfo(p->getProx()->getInfo());
                p->setProx(p->getProx()->getProx());
                p->setAnt(p->getAnt()->getAnt());
                p = p->getAnt();
                delete aux;
                n--;*/

                /*
                NoDuplo *aux = p->getAnt();
                aux->setProx(p->getProx());

                aux = p->getProx();
                aux->setAnt(p->getAnt());
                
                p = p->getAnt();
                n--;
                */
            }
        }
        p = p->getProx();
    }
}

void ListaDupla::inserek(int k, int val){
    if(k < 0 || k > n) {
        cout << "Índice Inválido!"<< endl;
    }
    else if(k == 0){
        insereInicio(val);
    }
    else if(k == n){//possibilidade
        insereFinal(val);
    }
    else{
        NoDuplo* novo = new NoDuplo();
        novo->setInfo(val);
        int i = 0;
        for(NoDuplo* p = primeiro; p!=NULL; p = p->getProx()){
            if(i == k){
                NoDuplo* ant = p->getAnt();
                novo->setProx(p);
                novo->setAnt(ant);
                p->setAnt(novo);
                ant->setProx(novo);
                n++;
            }
            i++;
        }
    }
}

void ListaDupla::removek(int k){
    int i = 0;
    NoDuplo* p;
    for(p = primeiro;p != NULL;p = p->getProx()){
        NoDuplo* aux = p;
        if(i == k){
            p = p->getAnt();
            p->setProx(p->getProx()->getProx());
            p->getProx()->setAnt(p);
            delete aux;
            n--;
        }
        aux = aux->getProx();
        i++;
    }
}

ListaDupla* ListaDupla::concatena(ListaDupla *l2){
    ListaDupla* listaNova = new ListaDupla();
    
    //insere elementos da primeira lista
    NoDuplo* p = primeiro;
    while(p!=NULL){
        listaNova->insereFinal(p->getInfo());
        p = p->getProx();
    }

    //insere elementos da segunda lista
    p = l2->primeiro;
    while(p != NULL){
        listaNova->insereFinal(p->getInfo());
        p = p->getProx();
    }

    return listaNova;
}

ListaDupla* ListaDupla::partir(int x){
    ListaDupla* listaNova = new ListaDupla();
    NoDuplo* p = ultimo;
    while(p!=NULL && (p->getInfo()!=x)){
        listaNova->insereInicio(p->getInfo());
        p = p->getAnt();
        this->removeFinal();
    }
    return listaNova;
}

void ListaDupla::removeDepoisMaior(){
    NoDuplo* p = primeiro;
    NoDuplo* aux = primeiro;
    int i = 0, j = 0;
    while(p!=NULL){
        if(aux->getInfo() < p->getInfo()){
            aux = p;
            j = i;
        }
        p = p->getProx();
        i++;
    }
    removek(j+1);
}

ListaDupla* ListaDupla::criaListaMenorMaior(){
    ListaDupla* novaLista = new ListaDupla();
    if(n<2){
        exit(1);
    }
    NoDuplo* p = primeiro;
    NoDuplo* auxMaior;
    NoDuplo* auxMenor;
    int indexMaior, indexMenor;
    //coloca valores para os 2 primeiros elementos sendo maior e menor
    if(primeiro->getInfo() > primeiro->getProx()->getInfo()){
        auxMaior = primeiro;
        auxMenor = primeiro->getProx();
        indexMaior = 0;
        indexMenor = 1;
    }
    else{
        auxMaior = primeiro->getProx();
        auxMenor = primeiro;
        indexMaior = 1;
        indexMenor = 0;
    }
    p = p->getProx()->getProx();
    while(p!=NULL){
        int i=2;
        //maior
        if(auxMaior->getInfo() < p->getInfo()){
            auxMaior = p;
            indexMaior = i;
        }

        //menor
        else if(auxMenor->getInfo() > p->getInfo()){
            auxMenor = p;
            indexMenor = i;
        }
        i++;
        p = p->getProx();
    }
    novaLista->insereFinal(auxMenor->getInfo());
    novaLista->insereFinal(auxMaior->getInfo());
    removek(indexMenor);
    removek(indexMaior);
    return novaLista;
}

void ListaDupla::insereDepoisMenor(int val){
    if(primeiro != NULL){
        NoDuplo* menor = primeiro;
        for(NoDuplo* p = primeiro->getProx(); p!=NULL;p = p->getProx()){
            if(p->getInfo()<menor->getInfo()){
                menor = p;
            }
        NoDuplo* q = menor->getProx();
        NoDuplo* novo = new NoDuplo();
        novo->setInfo(val);
        novo->setAnt(menor);
        novo->setProx(q);
        menor->setProx(novo);
        if(q == NULL){
            ultimo = novo;
        }
        else{
            q->setAnt(novo);
        }
        n++;
        }
    }
    else{
        cout << "Lista Vazia";
    }
}

void ListaDupla::reduz_n(int n1){
    if(n1>=0 && n1 < n){
        NoDuplo* p = primeiro;
        for(int cont = 1; cont<=n1; cont++){
            ultimo = p;
            p = p->getProx();
        }
        while(p!=NULL){
            NoDuplo* t = p;
            p = p->getProx();
            delete t;
        }
        if(n1==0){
            primeiro = NULL;
            ultimo = NULL;
        }
        else{
            ultimo->setProx(NULL);
        }
        n=n1;
    }
    else{
        cout << "Valor inválido" << endl;
        exit(1);
    }
}

void ListaDupla::removeEntre(NoDuplo* p, NoDuplo* q){
    NoDuplo* m = primeiro;
    while(m!=NULL){
        //intermediário
        if(m->getAnt()==p && m->getProx()==q){
            p->setProx(p->getProx()->getProx());
            delete m;
            q->setAnt(p);
            n--;
        }
        //q na segunda posição
        else if(p==NULL && m->getProx()->getProx()==q){
            primeiro = q;
            delete m;
            m = primeiro;
            n--;
        }
        //q fora da lista e p na penultima posição
        else if(q == NULL && m->getProx()==NULL && m->getAnt() == p){
            ultimo = p;
            delete m;
            m = ultimo;
            n--;
        }
        m = m->getProx();
    }
}

void ListaDupla::remove1Ocorrencia(int val){
    NoDuplo* m = primeiro;
    NoDuplo* p = NULL;
    //ultima posição
    NoDuplo* ult = NULL;
    //primeiro nó
    if(m->getProx()->getInfo()==val && m->getAnt()==p){
        ult = primeiro;
        //pega o segundo nó para comparar
        ult = ult->getProx();
        removeEntre(p,ult);
    }
    int i=0;

    while(p!=NULL || i!=1){
        if(p->getInfo()==val && p!=NULL){
            //intermediário
            removeEntre(p,ult);
            i++;
        }
        p = p->getProx();
        ult = ult->getProx()->getProx();
    }

    while(p!=NULL && i!=1){
        // só pra ter certeza que voltou a NULL
        ult = NULL;
        if(p->getInfo() == val && p->getProx() == NULL){
            removeEntre(p,ult);
            i++;
        }
        p = p->getProx();
    }
}