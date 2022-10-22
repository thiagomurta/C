#include <stdio.h>
#include <string.h>

void cifraCesar(int k, char s[]){
    
    char aux;
    for(int j = 0; s[j] != '\0'; j++){
        aux = s[j];
        if(aux >= 'a' && aux <= 'z'){
            aux = aux + k;
            if(aux > 'z'){
                aux = aux - 'z' + 'a' - 1;
            }
        }
        
        else if(aux >= 'A' && aux <= 'Z'){
            aux = aux + k;
            if(aux > 'Z'){
                aux = aux - 'Z' + 'A' - 1;
            }
        }
        s[j] = aux;
    }
}

int main() {
    int i, n, k = 2;
    char s[1000];
    printf("Número de vezes que irá criptografar: ");
    scanf("%i", &n);
    for(i=0;i<n;i++){
        scanf("%*c");
        printf("%iª frase que será criptografada: ", i+1);
        scanf("%999[^\n]c%*c", s);
        cifraCesar(k,s);
        printf("Produto da Criptografia: ");
        printf("%s", s);
        printf("\n");
    }
    return 0;
}