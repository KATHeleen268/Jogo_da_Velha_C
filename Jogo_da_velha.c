#include <stdio.h>

void tabuleiroJogo(char JV[3][3]){
    for(int i = 0; i < 3; i++) {
       for(int j = 0; j < 3; j++) {
          printf("%c", JV[i][j]);
          if (j < 2) printf("  |"); 
          
       }
    printf("\n");
    if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int main()
{
    printf("Olá, Vamos começar nosso jogo\n");
    
    int i,j;
    char escolha;
    char jogadores[2] = {'X','O'};
    char jogo_da_velha[3][3];
    
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            jogo_da_velha[i][j] = ' ';
        }
    }
    
    printf("Escolha se você que ser X ou O:");
    scanf(" %c", &escolha);
    
    if(escolha == 'X'){
        printf("Jogador %c, vamos começar!\n", escolha);
        tabuleiroJogo(jogo_da_velha);
    } else {
        printf("Jogador %c, vamos começar!\n", escolha);
        tabuleiroJogo(jogo_da_velha);
    }
    
    return 0;
}
