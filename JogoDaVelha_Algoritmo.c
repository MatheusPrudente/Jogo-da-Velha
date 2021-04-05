#include "stdio.h"
#include "stdlib.h"

// cria o tabuleiro todo vazio
void mostrarRegra (){
	
	int comeca = 10;

	printf("\n");
	printf("\n");
	printf(" \t========= REGRAS DO JOGO  ============");
	printf("\n");
	printf("\n");	

	printf("    1. O tabuleiro eh uma matriz de 3 linhas por 3 colunas .");
	printf("\n");
	printf("\n");

	printf("    2. Informe apenas numeros para as coordenadas .");
	printf("\n");
	printf("\n");
	
	printf("    3. O jogo eh iniciado pelo xis (X) e depois o circulo (O) . " );
	printf("\n");
	printf("\n");

	printf("    4. Os jogadores jogam alternadamente, uma marcacao por\n     vez, numa lacuna que esteja vazia . ");
	printf("\n");
	printf("\n");

	printf("    5. O objectivo eh conseguir tres circulos ou tres xis em linha,\n      quer horizontal, vertical ou diagonal,e ao mesmo tempo,quando\n      possivel, impedir o adversario de ganhar na proxima jogada .");
	printf("\n");
	printf("\n");

	printf("    6. Quando um jogador conquista o objetivo, o jogo acaba . ");
	printf("\n");
	printf("\n");

	while ( comeca != 0){	

		printf("\n");
		printf("    Digite 0 para comecar : ");
		scanf("%d",&comeca);
	}
	
	system("cls");


}

void criarTabuleiro(char tabuleiro[3][3]){
	int i;
	int j;
 	for ( i = 0 ;i < 3; i++){
  		for( j = 0; j < 3;j++){
   			tabuleiro[i][j] = ' ';
  		}
  	}
  	
}



// mostrar o tabuleiro atualizado na tela
void mostrarTabuleiro(char tabuleiro[3][3]){

	int cont = 1;
	int i;
	int j;
	printf("\n\n\n");
	printf("     ========= JOGO DA VELHA ============");
	printf("\n\n\n");
	printf("             1   2   3 \n");
	for ( i = 0; i<3 ;i++ ){
 		printf("           -------------\n");
 		printf("         %d |",cont);
   			for( j = 0;j < 3;j++){
   				printf(" %c |",tabuleiro[i][j]);

		  }
		printf("\n");
		cont++;
	}
	printf("           -------------");
}

// mostrar o tabuleiro e a vez do jogador
int jogarTabuleiro(char tabuleiro[3][3],char jogadorAtual, int jogada ){

	int linha = 0;
	int coluna = 0;
	int movimento = 0;

	while (movimento < 1){
	
	    printf("\n\n       Jogador %c :\n",jogadorAtual);
	    printf("\n       Informe coordenada da LINHA: ");
	    scanf("%d",&linha);
	    printf("\n       Informe coordenada da COLUNA: ");
	    scanf("%d",&coluna);
	
	      if (linha>3 || coluna>3){
	        printf("\n       Jogada invalida, tente novamente\n");
	      }
	
	        else if(tabuleiro[linha-1][coluna-1]== ' ' ){
	
	            tabuleiro[linha-1][coluna-1] = jogadorAtual;
	            movimento++;
	            jogada++;
	
	            system("cls");
	            mostrarTabuleiro(tabuleiro);
	
	
	        }
	
	        else {   printf("\n       Jogada invalida, tente novamente\n");
	
	
	        }
	}

	return jogada;
}

//verificar se alguem ganhou
int verificarTabuleiro(char tabuleiro[3][3],int vencedor,char jogadorAtual){
//linhas
 	int i = 0;
 	int j = 0;


  	if ((tabuleiro[i][j]== jogadorAtual && tabuleiro[i][j+1] == jogadorAtual&& tabuleiro[i][j+2] == jogadorAtual)||
	(tabuleiro[i + 1][j] == jogadorAtual&& tabuleiro[i+1][j+1] == jogadorAtual && tabuleiro[i+1][j+2] == jogadorAtual)||
	(tabuleiro[i+2][j] == jogadorAtual && tabuleiro[i+2][j+1] == jogadorAtual && tabuleiro[i+2][j+2] == jogadorAtual)){
		
    		printf("\n\n       O JOGADOR %c VENCEU !!!\n",jogadorAtual);
    		vencedor++;
	}

	//colunas
	if ((tabuleiro[i][j]== jogadorAtual && tabuleiro[i+1][j]==jogadorAtual && tabuleiro[i+2][j]==jogadorAtual) ||
	(tabuleiro[i][j+1]==jogadorAtual && tabuleiro[i+1][j+1]==jogadorAtual && tabuleiro[i+2][j+1]==jogadorAtual)||
	(tabuleiro[i][j+2]==jogadorAtual && tabuleiro[i+1][j+2]==jogadorAtual && tabuleiro[i+2][j+2]==jogadorAtual)){
		
	    	printf("\n\n       O JOGADOR %c VENCEU !!!\n",jogadorAtual);
    	  	vencedor++;
	}


	//diagonais
	if ((tabuleiro[i][j]==jogadorAtual &&  tabuleiro[i+1][j+1]==jogadorAtual &&  tabuleiro[i+2][j+2]==jogadorAtual) ||
		(tabuleiro[i][j+2]==jogadorAtual &&  tabuleiro[i+1][j+1] == jogadorAtual &&  tabuleiro[i+2][j]==jogadorAtual) ){
			
 			printf("\n\n       O JOGADOR %c VENCEU !!!\n",jogadorAtual);
     		vencedor++;
	}

  	return vencedor;
}


void jogar(){
	
	int jogada = 0;
	char tabuleiro[3][3];

	mostrarRegra();
    criarTabuleiro(tabuleiro);
	mostrarTabuleiro(tabuleiro);

	char jogador[2] = {'X','O'};

	int jogadorAtual = 0;
	int vencedor = 0;

 	while(jogada < 9 ){

   		if (vencedor == 0){
     		jogada = jogarTabuleiro(tabuleiro,jogador[jogadorAtual],jogada);
     		vencedor = verificarTabuleiro(tabuleiro, vencedor,  jogador[jogadorAtual]);
   		}

   		if (vencedor == 0){
   			
     		if(jogada < 9){
     			
     		jogada = jogarTabuleiro(tabuleiro,jogador[jogadorAtual+1],jogada);
     		vencedor = verificarTabuleiro(tabuleiro, vencedor,  jogador[jogadorAtual+1]);
     		
			}
   		}
 	}


 	if (jogada == 9 && vencedor == 0){
 		printf("\n\n       O JOGO DEU VELHA !!! \n");
 	}
}


void main(){
	jogar();
	
}
