#include <stdio.h>
main(){
    int n, cont, k;
    cont = 0;
    scanf("%i", &n);
    for(k= n;k>=1;k--){
        if(n%k==0){
            cont++;
        }
            cont++;
    }
    if(cont>2){
        printf("Não primo.");
    }
    else{
        printf("Primo.");
    }
}