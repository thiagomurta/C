#ifndef VETOR_H_INCLUDED
#define VETOR_H_INCLUDED
class Vetor
{
private:
    int n; // tamanho do vetor
    float *vet; // array que armazena n floats
    bool verifica(int indice);

public:
    Vetor(int tam);
    ~Vetor();
    float get(int indice);
    void set(int indice, float valor);
};

#endif // VETOR_H_INCLUDED
