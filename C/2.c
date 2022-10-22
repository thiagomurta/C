#include <stdio.h>
void PREENCHE(int ORIGEM[], int DESTINO[], int n){
    int VAL, j;
    DESTINO[0] = 100;
    j=1;
    printf("%i ", DESTINO[0]);
    VAL=n;
    while(ORIGEM[15]>=VAL){
        DESTINO[n] = ORIGEM[n+1];
        printf("%i ", DESTINO[n]);
        n++;
        VAL++;
    }
    while(ORIGEM[j]<VAL){
        DESTINO[n] = ORIGEM[j];
        printf("%i ", DESTINO[j]);
        j++;
        VAL--;
    }
}
int main(){
    int ORIGEM[15], DESTINO[15], n;
    for(n=0;n<15;n++){
        ORIGEM[n] = n;
    }
    scanf("%i", &n);
    PREENCHE(ORIGEM, DESTINO, n);
}