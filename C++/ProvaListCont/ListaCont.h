#ifndef LISTACONT_H
#define LISTACONT_H


class ListaCont
{
    private:
        int max, n, inicio;
        int *vet;

        ///indice do �ltimo n�
        int ultimo() {return inicio + n - 1;}

        ///verifica se k � um �ndice v�lido
        int valido(int k){return k>=inicio && k<=ultimo();}

        void realoca(); //realoca o número de nós
    public:
        ListaCont(int tam);
        ~ListaCont();

        int get(int k); //retorna o valor na posição k
        void set(int k, int val);  ///altera valor na posicao k

        void insereFinal(int val);
        void insereK(int k, int val); //insere o nó no índice k
        void insereInicio(int val);

        void removeFinal();
        void removek(int k); //remove o nó no índice k
        void removeInicio();
        void insereValores(int tam, int v[]); //insere nós no início da lista
        void intercala(ListaCont *la, ListaCont *lb); //intercala 2 listas
        void imprime(); // imprime a lista
        ListaCont* copiar(int val); // cria uma nova lista que copia os nós a partir do nó que possui o valor declarado

        //meus testes
        bool troca (int posicao1 , int posicao2 ); // inverte a posição dos nós
        bool aumentaCapacidade (int novoMax ); // aumenta a capacidade do max
        int numNos(); // retorna o número de nós
        void limpar(); // limpa a lista *n=0*
        int buscaMaior(int val); //procura um valor maior na lista
        void removeMultiplos(int val);
};

#endif // LISTACONT_H