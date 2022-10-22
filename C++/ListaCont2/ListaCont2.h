#ifndef LISTACONT2_H
#define LISTACONT2_H


class ListaCont2
{
    private:
        int max, n, inicio;
        int *vet;

        ///indice do �ltimo n�
        int ultimo() {return inicio + n - 1;}

        ///verifica se k � um �ndice v�lido
        int valido(int k){return k>=inicio && k<=ultimo();}

        void realoca();
    public:
        ListaCont2(int tam);
        ~ListaCont2();

        int get(int k);
        void set(int k, int val);  ///altera valor na posicao k

        void insereFinal(int val);
        void insereK(int k, int val);
        void insereInicio(int val);

        void removeFinal();
        void removek(int k);
        void removeInicio();
        void inserirVet(int tam, int v[]);
        void intercala(ListaCont2 *la, ListaCont2 *lb);

        void imprime();
        ListaCont2* copiar(int val);
        bool troca (int posicao1 , int posicao2 );
        bool aumentaCapacidade (int novoMax );
        //meus testes
        int numNos();
        void limpar();
        int buscaMaior(int val);
};

#endif // LISTACONT2_H
