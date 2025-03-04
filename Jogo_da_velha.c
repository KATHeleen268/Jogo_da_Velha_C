#include <stdio.h>

//função que vai ser usada para retornar o tabuleiro vazio
void tabuleiroJogo(char JV[3][3]){
    for(int i = 0; i < 3; i++) {
       for(int j = 0; j < 3; j++) {
          printf("%c", JV[i][j]);//JV = jogo da velha
          if (j < 2) printf("  |"); 
          
       }
    printf("\n");
    if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int validandoEscolhaJogador(int escolhalinha, int escolhacoluna, char jogo_da_velha[3][3]){
       if( escolhalinha >= 0 && escolhalinha < 3 && escolhacoluna >= 0 && escolhacoluna < 3 && jogo_da_velha[escolhalinha][escolhacoluna] == ' '){
           return 1;
    } else {
      printf("resultado inválido!\n");
      return 0;
    }//função que vai validar se pode jogar na linha e coluna se estiver vazia 
    }

int Vencedor(char escolha, char jogo_da_velha[3][3]){ //função para saber o vencendor se acontecer de vencer em linha, coluna ou diagonal
for (int i = 0; i < 3; i++) {
        if (jogo_da_velha[i][0] == escolha &&
            jogo_da_velha[i][1] == escolha &&
            jogo_da_velha[i][2] == escolha) {
            return 1; //Testando veriificação de Linhas
        }
    }
    for (int j = 0; j < 3; j++) {
        if (jogo_da_velha[0][j] == escolha &&
            jogo_da_velha[1][j] == escolha &&
            jogo_da_velha[2][j] == escolha) {
            return 1; // verificando colunas
        }
    }
    if (jogo_da_velha[0][0] == escolha &&
        jogo_da_velha[1][1] == escolha &&
        jogo_da_velha[2][2] == escolha) {
        return 1; // diagonal principal
    }
    if (jogo_da_velha[0][2] == escolha &&
        jogo_da_velha[1][1] == escolha &&
        jogo_da_velha[2][0] == escolha) {
        return 1; //diaginal secundaria
    }
    return 0;
} 

int main()
{
    printf("Olá, Vamos começar nosso jogo\n");
    
    int i,j, escolhalinha, escolhacoluna, jogadas = 0;
    char escolha;
    char jogadores[2] = {'X','O'};//vetor que vai armazenar os valores do jogo_da_velha
    char jogo_da_velha[3][3]; // matriz do jogo
    
    for(i = 0; i < 3; i++){ 
        for(j = 0; j < 3; j++){
            jogo_da_velha[i][j] = ' '; //fazendo o for da matriz para que tenha linhas e colunas e seja bonitinha e vazia
        }
    }
    
    printf("Escolha se você que ser X ou O:");
    scanf(" %c", &escolha); //deixando o jogador/usuário escolher o que vai ser
    
    if(escolha == 'X'){
        printf("Jogador %c, vamos começar!\n", escolha);
        tabuleiroJogo(jogo_da_velha); //função sendo testada
    } else if (escolha == 'O') {
        printf("Jogador %c, vamos começar!\n", escolha);
        tabuleiroJogo(jogo_da_velha); //função sendo testada
    } else {
        printf("Escolha inválida, por favor escolha entre 'X' ou 'O'.");
    }

    do{
        
    printf("Jogador %c, digite a linha e a coluna (0, 1 ou 2):\n",  escolha); //pede a escolha do jogador para colocar no local
    scanf("%d %d", &escolhalinha, &escolhacoluna);//jogador vai digitar sua escolha
    
   if (validandoEscolhaJogador(escolhalinha, escolhacoluna, jogo_da_velha)) {
            jogo_da_velha[escolhalinha][escolhacoluna] = escolha; // testando se funciona 
            tabuleiroJogo(jogo_da_velha);
            jogadas++;//incrementando as jogadas para que o máximo seja 9
   } else {
       printf("Inválido,tente novamente\n");
   }
    
    if(Vencedor(escolha, jogo_da_velha)){
        printf("Parabéns, jogador %c! Você venceu!", escolha); //testando função de ganhar
     break;
    }
    
    if(jogadas == 9){
        printf("A velha ganhou e vocês empataram!"); //empate
    }
    
    if(escolha == 'X'){ //alterna os jogadores
    escolha = 'O';
    } else {
    escolha = 'X';
    }
    
    }while(jogadas < 9);
    
    return 0;
}
