#include <stdio.h>
void vetCont(int fiv[5], int nin[9], int four[14]){
    int i, fi, ni, fo, j;
    j=0;
    while(fi<5 && fi>=0){
        scanf("%i", &fiv[j]);
        fi++;
    }
    while(ni<9 && ni>=0){
        scanf("%i", &nin[j]);
        ni++;
    }
    while(fo<14 && fo>=0){
        scanf("%i", &fo[j]);
        fo++;
    }
    for(j=5;j>0;j--){
        for(i=0;i<fiv[j];i++){
            printf("Inversão do primeiro vetor");
            printf("\nv[%i] = %i", i, fiv[5]);
        }
    }
    for(j=0;j>0;j--){
        for(i=0;i<nin[j];i++){
            printf("Inversão do primeiro vetor");
            printf("\nv[%i] = %i", i, nin[9]);
        }
    }
    for(j=0;j>0;j--){
        for(i=0;i<nin[14];i++){
            printf("Inversão do primeiro vetor");
            printf("\nv[%i] = %i", i, fiv[14]);
        }
    }
}
main(){
    int fiv[5], nin[9], four[14];
    vetCont(fiv[5], nin[9], four[14]);
}