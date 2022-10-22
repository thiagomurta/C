#ifndef MATRIZESPECIAL_H_
#define MATRIZESPECIAL_H_

class MatrizEspecial{
    private:
        int *vet, n;
        bool verifica(int indice);
    public:
        MatrizEspecial(int nn);
        ~MatrizEspecial();
        int get(int i, int j);
        void set(int i, int j, float val);
        int getInd(int i, int j);
};
#endif // MATRIZESPECIAL_H_