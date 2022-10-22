#ifndef MATALTERNADA_H_INCLUDED
#define MATALTERNADA_H_INCLUDED

class MatAlternada
{
    private:
        int n;
        float *vet;
        bool verifica(int i, int j);

    public:
        ///interface
        MatAlternada(int ordem);
        ~MatAlternada();
        float get(int i, int j);
        void set(int i, int j, float valor);
};

#endif // MATALTERNADA_H_INCLUDED
