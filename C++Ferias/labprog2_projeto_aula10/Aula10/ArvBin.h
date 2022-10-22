#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"

class ArvBin
{
  public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void cria(int x, ArvBin *sae, ArvBin *sad);
    void anulaRaiz();
    bool vazia(); // verifica se a �rvore est� vazia
    bool busca(int x);
    void preOrdem();
    void montaArvore();
    void insere(int x);
    //teste
    void imprime();
    int contaNos();
    int contaNosFolhas();
    int altura();
    int contaImpar();
    void imprimeNivel(int k);
    float mediaNivel(int k);
    int min();
    void contaElegante();
    bool ehFolha(NoArv *p);
    void contagens(int k);
    void contagens2(int val, int k);
    int difMaxMinFolha();
    int* criaVetFolhas(int k, int *n);
    int impares();
    int soma();
    float media();
    float mediaPares();
    int maiorVal();
    int menorVal();
    int maiores(int val);
    void imprimirNivel(int nivel);
    void impressao();
    int sucessor(int val);
    bool eCompleta();

  private:
    NoArv *raiz; // ponteiro para o No raiz da �rvore

    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int x);
    void auxPreOrdem(NoArv *p);
    NoArv* auxMontaArvore();
    void auxImpNivel(NoArv *p, int atual, int k);
    void auxInverte(NoArv * p);
    NoArv* auxInsere(NoArv *p, int x);
    //teste
    void auxImprime(NoArv *p);
    int auxContaNos(NoArv *p);
    int auxContaNosFolhas(NoArv *p);
    int auxAltura(NoArv *p);
    int auxContaImpar(NoArv *p);
    void auxImpNivel(NoArv *p, int k);
    void auxMediaNivel(NoArv *p,int k, int *soma, int *cont);
    void auxMin(NoArv *p, int *menor);
    void auxContaElegante(NoArv *p, int *cont1, int *cont2);
    void auxContagens(NoArv *p, int atual, int k, int *cont1, int *cont2);
    void auxContagens2(NoArv *p, int val, int atual, int k, int *cont1, int *cont2);
    int auxDifMaxMinFolha(NoArv *p, int *min, int *max, bool *primeiraFolha);
    void auxCriaVetFolhas(NoArv *p, int k, int atual, int vet[], int* pos);
    int auxImpares(NoArv *p);
    int auxSoma(NoArv *p);
    float auxMedia(NoArv *p, float* soma,int* cont);
    float auxMediaPares(NoArv *p, float* soma,int* cont);
    int auxMaiorVal(NoArv *p);
    int auxMenorVal(NoArv *p);
    int auxMaiores(NoArv *p, int val);
    void auxMediaNivel2(NoArv *p, int k, int *soma, int *cont);
    void auxImprimirNivelPO(NoArv *p, int nivel);
    void auxImprimirNivelIO(NoArv *p, int nivel);
    void auxImprimirNivelPreO(NoArv *p, int nivel);
    void auxImpressao(NoArv *p);
    void auxImprimirPreO(NoArv *p);
    void auxImprimirPO(NoArv *p);
    void auxImprimirIO(NoArv *p);
    void auxSucessor(NoArv *p, int val, int *Nmaior, int *Nmenor, int *menor);
    bool auxECompleta(NoArv *p);
};

#endif // ARVBIN_H_INCLUDED