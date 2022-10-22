#ifndef ROTA_H_
#define ROTA_H_

class Rota{
    private:
        int n;
        float *tempos;
    public:
        Rota(int nn);
        ~Rota();
        void leTempos();
        float tempoTotal();
};
#endif // ROTA_H_