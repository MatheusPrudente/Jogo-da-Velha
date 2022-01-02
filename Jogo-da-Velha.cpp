#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <ctype.h>
using namespace std;

// mostra as regras do jogo
void mostrarRegra (){
	cout << endl << endl;
	cout << " \t--------- REGRAS DO JOGO  ------------" << endl << endl;
	cout << "    1. O tabuleiro eh uma mapa de 3 linhas por 3 colunas ." << endl << endl;
	cout << "    2. O jogo eh iniciado pelo xis (X) e depois o circulo (O) . " << endl << endl;
	cout << "    3. Informe apenas numeros para as coordenadas ." << endl << endl;
	cout << "    4. Informe a coordenada para a linha ." << endl << endl;
	cout << "    5. Pressione Enter para confirmar a acao ." << endl << endl;
	cout << "    6. Informe a coordenada para a coluna ." << endl << endl;
	cout << "    7. Pressione Enter para confirmar a acao ." << endl << endl;
	cout << "    8. Os jogadores jogam alternadamente, preenchendo as casas que estejam vazias . " << endl << endl;
	cout << "    9. O objetivo eh conseguir tres circulos ou tres xis em linha,\n      quer horizontal, vertical ou diagonal,e ao mesmo tempo,quando\n      possivel, impedir o adversario de ganhar na proxima jogada ." << endl << endl;
	cout << "    10. Quando um jogador conquista o objetivo, o jogo acaba . " << endl << endl;
	cout << "    11. Caso todas as casas estejam preenchidas e nenhum jogador ganhe, o jogo acaba como velha. " << endl << endl;
	cout << "    Pressione qualquer tecla para continuar . . ." << endl;
    getchar();

	system("cls");
}

//cria o mapa
void criarMapa(char mapa[3][3]){
	int linha,coluna;
	
	for( linha = 0; linha < 3; linha++){
	    for (coluna = 0; coluna < 3; coluna++ ){
	    	mapa[linha][coluna] = ' ';
	    }
    }
}

//mostra o mapa
void mostrarMapa(char mapa[3][3]){
	int cont = 1;
	int linha,coluna;
	
	system("cls");
	cout << endl << endl <<"     --------- JOGO DA VELHA ------------" << endl << endl << endl;
	cout << "             1   2   3 " << endl;
	
	for (linha = 0; linha < 3; linha++){
		cout << "           -------------" << endl;
		cout << "         " << cont << " |";
		
		for(coluna = 0;coluna < 3; coluna++){
	    	cout <<" "<< mapa[linha][coluna] << " |";
		}
		cout<<endl;
		cont++;
	}
	cout << "           -------------" << endl;
}

//verifica o vencedor
int verificarVencedor(char mapa[3][3],char jogadorAtual,int vencedor){
	int a = 0;
 	int b = 0;
 	
	//linhas
	if (mapa[a][b] == jogadorAtual && mapa[a][b+1] == jogadorAtual && mapa[a][b+2] == jogadorAtual||
		mapa[a+1][b] == jogadorAtual && mapa[a+1][b+1] == jogadorAtual && mapa[a+1][b+2] == jogadorAtual ||
		mapa[a+2][b] == jogadorAtual && mapa[a+2][b+1] == jogadorAtual && mapa[a+2][b+2] == jogadorAtual){
			    
		cout << endl <<"         O JOGADOR '" << jogadorAtual << "' VENCEU !!! " << endl;
		vencedor++;
	}
	
	//colunas	
	if (mapa[a][b] == jogadorAtual && mapa[a+1][b] == jogadorAtual && mapa[a+2][b] == jogadorAtual ||
	    mapa[a][b+1] == jogadorAtual && mapa[a+1][b+1] == jogadorAtual && mapa[a+2][b+1] == jogadorAtual||
	    mapa[a][b+2] == jogadorAtual && mapa[a+1][b+2] == jogadorAtual && mapa[a+2][b+2] == jogadorAtual ){
	    	
		cout<<endl<<"         O JOGADOR '" << jogadorAtual << "' VENCEU !!! "<<endl;
		vencedor++;
	}
	
	//diagonais
	if (mapa[a][b] == jogadorAtual &&  mapa[a+1][b+1 ]== jogadorAtual &&  mapa[a+2][b+2] == jogadorAtual ||
		mapa[a][b+2] == jogadorAtual &&  mapa[a+1][b+1] == jogadorAtual &&  mapa[a+2][b] == jogadorAtual ){
			
		cout<<endl<<"         O JOGADOR '" << jogadorAtual << "' VENCEU !!! "<<endl;
		vencedor++;
	}
	
	return vencedor;
}

//efetua a jogada no mapa
int efetuarJogada(char mapa[3][3], char jogadorAtual, int jogada){
	int movimento = 0;
	char charLinha,charColuna;	
	
	while(movimento < 1){
		cout << endl << "         Eh a vez do jogador " << jogadorAtual << endl;

        do{
	    	cout << endl << "         Informe coordenada da LINHA: ";
        	cin >> charLinha;
			if(isdigit(charLinha) != 1){
				cout << endl <<"         A jogada invalida, tente novamente  " << endl << endl;
			}
		}while(isdigit(charLinha) != 1);
		
		int linha = (int)charLinha - 48;
		
		do{
			cout << endl << "         Informe coordenada da COLUNA: ";
        	cin>>charColuna;
			if(isdigit(charColuna) != 1){
				cout << endl << "         A jogada invalida, tente novamente  "<< endl << endl;
			}
		}while(isdigit(charColuna) != 1);
		
		int coluna = (int)charColuna - 48;
 		
		if (linha>3 || coluna>3){
			cout << endl <<"         A jogada invalida, tente novamente  " << endl << endl;
 		}else if(mapa[linha-1][coluna-1] == ' ' ){
			mapa[linha-1][coluna-1] = jogadorAtual;
		 	movimento++;
			jogada++;
			mostrarMapa(mapa);
		}else{
			cout << endl <<"         A jogada invalida, tente novamente  " << endl;
		}
	}
	
	return jogada;
}

int main (){
	char jogador[2] = {'X','O'};
	char mapa [3][3];
	int jogada = 0;
	int vencedor = 0;
	
	mostrarRegra();
	criarMapa(mapa);
	mostrarMapa(mapa);
	
	while(jogada < 9 ){
   		if (vencedor == 0){
     		jogada = efetuarJogada(mapa, jogador[0], jogada);
     		vencedor = verificarVencedor(mapa, jogador[0],vencedor);
   		}
   		
   		if (vencedor == 0){	
			if(jogada < 9){
				jogada = efetuarJogada(mapa, jogador[1], jogada);
				vencedor = verificarVencedor(mapa, jogador[1], vencedor);
			}
   		}
		
		if(vencedor == 1){
   	 		break;
   		}
 	}
 	
 	if (jogada == 9 && vencedor == 0){
 		cout << endl << "         O JOGO DEU VELHA !!!" << endl << endl;
 	}
 	
	return 0;
}


