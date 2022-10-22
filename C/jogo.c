#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

//matriz jogo--> matriz que imprime e organiza a posição dos robozinhos
//jogador--> 
//localizacao--> matriz da posição de cada jogada
//



//vai sortear uma posição para o nosso nobre guerreiro
void posicao(int jogo[TAM][TAM]){
  int i,j;
  i=rand()%10;
  j=rand()%10;
  jogo[i][j];
}

//inicializa a matriz:)
void inicializamatrizinha(int jogo[TAM][TAM]){
  int i,j;
  for(i=0;i<TAM;i++){
    for(j=0;j<TAM;j++){
      jogo[i][j] = 0;
    }
  }
  return;
}

//imprime o tamanho do jogo (da matriz)
void imprimeTamanho(int jogo[TAM][TAM]){
  int i, j;
  
  printf("\e[1;1H\e[2J");
  for(i=0;i<TAM;i++){
    for(j=0;j<TAM;j++){
        switch(jogo[i][j]){
            case 0: printf ("         "); 
                    break;
            case 1: printf ("   😀    "); 
                    break;
            case 2: printf ("   🤖    "); 
                    break;
            case 3: printf ("  🕳️  ");
                    break;         
        }
        if(j != TAM-1){
          printf("|");
        }
    }
    printf("\n");
    if (i != TAM){
      printf("---------------------------------------------------------------------------------------------------\n");
    }
  }
}

//os robozinhos vão olhar a posição do nosso nobre guerreiro e ver a distância (não sei se vai precisar)
/*void matrizinha(int A[][TAM],int B[][TAM]){
    int i, j, bonecoLin, bonecoCol;

    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            if(A[i][j]==1){
                bonecoLin = i;
                bonecoCol = j;
            }
        }
    }
    for(i = 0; i<TAM; i++){
        for(j = 0; j<TAM; j++){
            B[i][j] = abs(i - bonecoLin) + abs(j - bonecoCol);
        }
    }
}*/

//marca a posição do jogador
void marcaPosicao(int jogo[TAM][TAM]){
  int linha, coluna,i,j;
  printf("Insira a linha: ");
  scanf("%i", &linha);
  printf("Insira a coluna: ");
  scanf("%i", &coluna);
  for(i = 0; i<TAM; i++){
        for(j = 0; j<TAM; j++){
            jogo[i][j] = abs(i - linha) + abs(j - coluna);
            if(jogo<=1){
              jogo[linha][coluna]=1;
            }
        }
    }
}

//os robozinhos vão decidir para onde vão(tirar dúvida com Luciana)------------
/*void decisao(int B[][TAM]){
  int i,j,k,mat[TAM][TAM];
  k=9;
  for(i=0;i<TAM;i++){
    for(j=0;j<TAM;j++){
      if(mat[i][j]<=k){
        B[i][j]=mat[i][j];
      }
    }
  }
}*/

// teletransporte seguro pra ficar relax(obs.: nesse caso o jogador poderá escolher a posição onde ficará)
void teletransporte(int jogo[TAM][TAM]){
  int linha, coluna;
  printf("Insira uma linha segura( ͡° ͜ʖ ͡°): ");
  scanf("%i", &linha);
  printf("Insira uma coluna segura( ͡° ͜ʖ ͡°): ");
  scanf("%i", &coluna);
  jogo[linha][coluna]=1;
}
int main() {
/*
  int jogo[TAM][TAM];
  inicializamatrizinha(jogo);
  imprimeTamanho(jogo,n);

  int comecou = 0;
  int jogador = 1;

  while (comecou == 0){
    marcaPosicao(jogo);
    posicao(jogo);
    imprimeTamanho(jogo,n);

    /*comecou = decisao(jogo);

    jogador ++;
    if (jogador == 3){
      jogador = 1;
    }
  }*/
	/*switch(comecou){
    case -1: printf ("Vamo dar uma de super saya-jin  agora kkk!!!\n"); 
           break;
    case 1: printf ("Passou de fase Velhão!!!!"); 
          break;
    case 2: printf ("Choremos ;-; (F)!!!!"); 
          break;        
  }*/
  return 0;
  //}
}