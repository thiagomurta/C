#include <stdio.h>
#include <string.h>

#define TAM 10
void imprimeTamanho(int mat[TAM][TAM]){
  int i, j;
  
  printf("\e[1;1H\e[2J");
  for(i=0;i<TAM;i++){
    for(j=0;j<TAM;j++){
        switch(mat[i][j]){
            case 0: printf ("     "); 
                    break;
            case 1: printf ("  (> o_o)>  "); 
                    break;
            case 2: printf ("  ( ͡° ͜ʖ ͡°)  "); 
                    break;        
        }
        if(j != TAM-1){
          printf("|");
        }
    }
    printf("\n");
    if (i != TAM-1)
      printf("-----------------\n");
  }
}
//inicializa a matriz:)
void inicializaMat(int mat[TAM][TAM]){
  int i,j;
  for(i=0;i<TAM;i++){
    for(j=0;j<TAM;j++){
      mat[i][j] = 0;
    }
  }
  return;
}
void marcaPosicao(int tabuleiro[TAM][TAM], int jogador){
	
  int linha, coluna;

  printf("Insira a linha e coluna:");

  scanf("%d", &linha);
  scanf("%d", &coluna);

  if(jogador==1)
      {
        tabuleiro[linha][coluna]=1;
      }
  else 
      if (jogador==2)
          {
            tabuleiro[linha][coluna]=2;
          }
}


// Verifica se o carinha ainda é bom e está vivo ou se morreu ;-; (F)
int ganhouDiagonal(int tabuleiro[TAM][TAM]){

	int resposta = -1;	// FALSO, NÃO GANHOU

	// Diagonal principal:
	if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
		resposta = tabuleiro[1][1];	// GANHOU E diz que quem está com a marcação em tabuleiro[1][1] ganhou;
	}

	// Diagonal secundária:
	if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
		resposta = tabuleiro[1][1];	// GANHOU E diz que quem está com a marcação em tabuleiro[1][1] ganhou;
	}

	return resposta;
}
int quemGanhou(int mat[3][3]){

}



// Todo mundo:
int main() {
  int jogo[TAM][TAM];
  
  inicializaMat(jogo);
  imprimeTaamanho(jogo);

  int terminou = 0;
  int jogador = 1;

  while (terminou == 0){
    marcaPosicao(jogo, jogador);
    imprimeTamanho(jogo);

    terminou = quemGanhou(jogo);

    jogador ++;
    if (jogador == 3){
      jogador = 1;
    }
  }
  
	switch(terminou){
    case -1: printf ("Deu Velha!!!\n"); 
           break;
    case 1: printf ("Passou de fase Velhão!!!!"); 
          break;
    case 2: printf ("Choremos ;-; (F)!!!!"); 
          break;        
  }

  return 0;
}