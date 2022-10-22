#ifndef MATRIZTRIANGSUP_H
#define MATRIZTRIANGSUP_H


class MatrizTriangSup
{
    private:
        int n;
        float *vet;
        bool verifica(int i, int j);
        int detInd(int i, int j);
    public:
        ///interface
        MatrizTriangSup(int ordem);
        ~MatrizTriangSup();
        float get(int i, int j);
        void set(int i, int j, float valor);
};

#endif // MATRIZTRIANGSUP_H
