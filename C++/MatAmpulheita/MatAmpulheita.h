#ifndef MATAMPULHEITA_H_INCLUDED
#define MATAMPULHEITA_H_INCLUDED

class MatrizAmpulheita
{
    private:
        int n;
        float *l1, *dp;
        bool verifica(int i, int j);

    public:
        ///interface
        MatrizAmpulheita(int ordem);
        ~MatrizAmpulheita();
        float get(int i, int j);
        void set(int i, int j, float valor);
};

#endif // MATAMPULHEITA_H_INCLUDED
