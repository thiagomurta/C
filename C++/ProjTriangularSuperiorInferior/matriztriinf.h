#ifndef MATRIZTRIINF_H
#define MATRIZTRIINF_H


class MatrizTriInf
{
    public:
        MatrizTriInf(int ordem);
        ~MatrizTriInf();
        float get(int i, int j);
        void set(int i, int j, float valor);
    private:
        int n;
        float *vet;

        bool verifica(int i, int j);
};

#endif // MATRIZTRIINF_H
