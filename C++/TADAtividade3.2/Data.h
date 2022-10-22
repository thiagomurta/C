#ifndef DATA_H_
#define DATA_H_

class Data{
    private:
        int dia;
        int mes;
        int ano;

    public:
        Data(int d,int m,int a);
        ~Data();
        void setDiaMesAno(int d, int m, int a);
        void imprime();
        Data* somaAnos(int nAnos);
};
#endif // DATA_H_