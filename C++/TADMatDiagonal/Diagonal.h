#ifndef DIAGONAL_H
#define DIAGONAL_H


class Diagonal
{
    private:
        int n;
        float *vet;
        bool verifica(int i, int j);
        int detInd(int i, int j);
    public:
        Diagonal(int nn);
        ~Diagonal();

        float get(int i, int j);
        void set(int i, int j, float valor);
        void imprime();
};

#endif // DIAGONAL_H
