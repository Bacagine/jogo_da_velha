/**************************************************************************
 * jogo_da_velha.c: Cria um jogo da velha                                 *
 *                                                                        *
 * Programa criado por Gustavo Bacagine <gustavo.bacagine@protonmail.com> *
 *                                                                        *
 * Data: 01/05/2019                                                       *
 * Data2: 26/12/2019                                                      *
 * Data da ultima modificação: 05/10/2020                                 *
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void mostrar_tabuleiro(char tabuleiro[3][3]);
void jogar(char tabuleiro[3][3]);
int verifica_vencedor(char tabuleiro[3][3]);
int verifica_jogada(char simbolo);

char tabuleiro[3][3] = {
                    {'-', '-', '-'},
                    {'-', '-', '-'},
                    {'-', '-', '-'} };

int main(void){
    system("clear || cls");
    
    mostrar_tabuleiro(tabuleiro);
    
    for(int jogadas = 0; jogadas < 9; jogadas++){
        jogar(tabuleiro);
        mostrar_tabuleiro(tabuleiro);
    }
    
    return 0;
}

void mostrar_tabuleiro(char tabuleiro[3][3]){
    printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    
    /*
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i < 2 && (j == 0 || j == 2)){
                printf(" %c |", tabuleiro[i][j]);
                printf("----|");
            }
            else if((i == 0 && j == 2) || (i == 2 && j == 2) || (i == 1 && j ==1)){
                printf(" %c \n", tabuleiro[i][j]);
            }
            else{
                printf(" %c |", tabuleiro[i][j]);
            }
        }
        putchar('\n');
    }
    */
}

void jogar(char tabuleiro[3][3]){
    int i = 0, j = 0;
    char simbolo;
    
    printf("\nDigite as cordenadas de onde e o simbolo (X ou O) para jogar: ");
    scanf("%d %d %c", &i, &j, &simbolo);
    
    while(verifica_jogada(simbolo)){
        fprintf(stderr, "Erro: Jogada invalida!\nUse apenas X ou O\n");
        printf("Por favor digite o simbolo desejado novamente: ");
        scanf("%c", &simbolo);
    }
    
    tabuleiro[i][j] = simbolo;
}

int verifica_vencedor(char tabuleiro[3][3]){
    /* Verifica as linhas para X */
    if((toupper(tabuleiro[0][0]) == 'X' && toupper(tabuleiro[0][1]) == 'X' && toupper(tabuleiro[0][2]) == 'X')
      || (toupper(tabuleiro[1][0]) == 'X' && toupper(tabuleiro[1][1]) == 'X' && toupper(tabuleiro[1][2]) == 'X')
      || (toupper(tabuleiro[2][0]) == 'X' && toupper(tabuleiro[2][1]) == 'X' && toupper(tabuleiro[2][2]) == 'X')){
        return 1;
    }
    /* Verifica as colunas para X */
    else if((toupper(tabuleiro[0][0]) == 'X' && toupper(tabuleiro[0][1]) == 'X' && toupper(tabuleiro[0][2]) == 'X')
            || (toupper(tabuleiro[1][0]) == 'X' && toupper(tabuleiro[1][1]) == 'X' && toupper(tabuleiro[1][2]) == 'X')
            || (toupper(tabuleiro[2][0]) == 'X' && toupper(tabuleiro[2][1]) == 'X' && toupper(tabuleiro[2][2]) == 'X')){
        return 1;
    }
    /* Verifica as diagonais */
    else if(){
        
    }
    else if(){
        return -1;
    }
    return 0;
}


int verifica_jogada(char simbolo){
    if(toupper(simbolo) != 'X' || toupper(simbolo) != 'O'){
        return 1;
    }
    return 0;
}
