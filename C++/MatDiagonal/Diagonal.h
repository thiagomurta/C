#ifndef DIAGONAL_H_INCLUDED
#define DIAGONAL_H_INCLUDED


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

        float getInd(int i, int j);
        void set(int i, int j, float valor);
        void imprime();
};

#endif // DIAGONAL_H_INCLUDED
