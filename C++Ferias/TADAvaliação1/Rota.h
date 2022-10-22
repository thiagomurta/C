#ifndef ROTA_H_INCLUDED
#define ROTA_H_INCLUDED

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
#endif // ROTA_H_INCLUDED