/*
Alunos: Enzo de Andrade Dorigheto e Arthur Fiório da Cunha.
Disciplina:  Programação I.
Ojetivo: Criamos um programa que gera uma matriz de 10/10 para simular um Caça Palavras, nele o usuário informa
         uma seed e aleatoriamente ele gera uma matriz, em seguida pede para o usuário dizer a palavra que ele
         encontrar e o  programa diz se a palavra está ou não no Caça palavras, além de informar as coordenadas.
*/

// Adicionamos algumas bibliotecas para facilitar na construção do trabalho.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos TAM para ser equivalente ao valor 10.
#define TAM 10

// Declaramos algumas funções que utilizamos no programa.
void PRINTmatriz(char mapa[TAM][TAM]);

int vert(char mapa[TAM][TAM], char* palavra, int y, int x);

int hori(char mapa[TAM][TAM], char* palavra, int y, int x);

int diag(char mapa[TAM][TAM], char* palavra, int y, int x);

void CompararPalavra(char mapa[TAM][TAM], char* palavra);

// Começamos a escrever a função principal, ela  praticamente só chama as demais funções e define uma seed.
int main(void) {
    int seed;
    char palavra[TAM+1];

    printf("escolha uma seed\n");

    // Obtemos a seed desejada pelo usuário e randomizamos os valores.
    scanf("%d", &seed);
    system("cls");
    srand(seed);

    char matriz[TAM][TAM];

    // Chamamos a Função para printar o Caça palavras na tela do usuário.
    PRINTmatriz(matriz);

    // Damos algumas informações de funcionamento para o usuário.
    printf("\nUse somente letras maiusculas (Chave de parada: '.')\n");
    printf("\nEscreva qual sera a palavra a ser encontrada:\n");

    scanf("%s", palavra);

    // Looping para testar as palavras encontradas e manter o programa funcionando, caso deseje parar só é necessário apertar '.'.
    while (palavra[0] != '.') {
        CompararPalavra(matriz, palavra);
        scanf("%s", palavra);
    }

    return 0;
}

// Criamos uma função especialmente para fazer a base do Caça palavras.
void PRINTmatriz(char mapa[TAM][TAM]) {
    int i, j;

    printf("MATRIZ:\n");

    // loopings para criar uma matriz de duas dimensões além de randomizar os seus valores e em seguida printar para o usuário.
    for (i=0; i<TAM; i++)
        for (j=0; j<TAM; j++)
            mapa[i][j] = (rand() % (90 - 65 + 1)) + 65;


    for(i=0; i< TAM; i++) {
        for(j=0; j< TAM; j++) {
        printf("%c ", mapa[i][j]);
        }
    printf("\n");
}
}

// Função para definir se a palavra desejada pelo usuário é encontrada na vertical.
int vert(char mapa[TAM][TAM], char* palavra, int y, int x) {
    int i, k = 1;

    if (y > (TAM - strlen(palavra))) return 0;

    // Looping para rodar todas as casas na vertical e testar se a palavra está presente, caso não o looping para.
    for (i = y+1; i < TAM; i++) {
        if (mapa[i][x] == palavra[k]) {
            k++;
        }
        else if (!palavra[k]) break;
        else return 0;
    }
    return 1;
}

// Função para definir se a palavra desejada pelo usuário é encontrada na horizontal.
int hori(char mapa[TAM][TAM], char* palavra, int y, int x) {
    int i, k = 1;

    if (x > (TAM - strlen(palavra))) return 0;

    // Looping para rodar todas as casas na horizontal e testar se a palavra está presente, caso não o looping para.
    for (i = x+1; i < TAM; i++) {
        if (mapa[y][i] == palavra[k]) {
            k++;
        }
        else if (!palavra[k]) break;
        else return 0;
    }
    return 1;
}

// Função para definir se a palavra desejada pelo usuário é encontrada na diagonal.
int diag(char mapa[TAM][TAM], char* palavra, int y, int x) {
    int i, j, k = 1;

    if (x > (TAM - strlen(palavra))) return 0;
    if (y > (TAM - strlen(palavra))) return 0;

    // Looping para rodar todas as casas na diagonal e testar se a palavra está presente, caso não o looping para.
    for (i = y+1, j = x+1; i < TAM && j < TAM; i++, j++) {
        if (mapa[i][j] == palavra[k]) {
            k++;
        }
        else if (!palavra[k]) break;
        else return 0;
    }
    return 1;
}

// Função para comparar as palavras encontradas e dizer suas posições caso existam.
void CompararPalavra(char mapa[TAM][TAM], char* palavra) {
    int i, j, achou = 0;

    // Loopins dentro de loopins, o objetivo é testar e informar todas as posições que a palavra pode estar e informar as coordenadas.
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            if (mapa[i][j] == palavra[0]) {
                if (vert(mapa, palavra, i, j)) {
                    printf("Palavra encontrada NA VERTICAL em %d %d.\n", i, j);
                    achou = 1;
                }
                if (hori(mapa, palavra, i, j)) {
                    printf("Palavra encontrada NA HORIZONTAL em %d %d.\n", i, j);
                    achou = 1;
                }
                if (diag(mapa, palavra, i, j)) {
                    printf("Palavra encontrada NA DIAGONAL em %d %d.\n", i, j);
                    achou = 1;
                }
            }
        }
    }

    // Caso o programa não ache a palavra ele informa que ela não existe na matriz.
    if (!achou) {
        printf("Palavra nao encontrada!\n");
    }
}
