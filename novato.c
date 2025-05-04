#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10      // Número de linhas (Y: 1 a 10)
#define COLS 10      // Número de colunas (X: A a J)
#define SHIP_SIZE 3  // Tamanho de cada navio
#define SHIP_COUNT 2 // Quantidade de navios

// Inicializa o tabuleiro com água (0)
void initializeBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0; // água
        }
    }
}

// Verifica se é possível posicionar o navio na posição (x, y)
int canPlaceShip(int board[ROWS][COLS], int x, int y, int horizontal) {
    if (horizontal) {
        if (y + SHIP_SIZE > COLS) return 0; // fora dos limites
        for (int i = 0; i < SHIP_SIZE; i++) {
            if (board[x][y + i] != 0) return 0; // já ocupado
        }
    } else {
        if (x + SHIP_SIZE > ROWS) return 0; // fora dos limites
        for (int i = 0; i < SHIP_SIZE; i++) {
            if (board[x + i][y] != 0) return 0; // já ocupado
        }
    }
    return 1; // pode posicionar
}

// Posiciona um navio aleatoriamente no tabuleiro
void placeShip(int board[ROWS][COLS]) {
    int x, y, horizontal, placed = 0;

    while (!placed) {
        x = rand() % ROWS;
        y = rand() % COLS;
        horizontal = rand() % 2; // 0 = vertical, 1 = horizontal

        if (canPlaceShip(board, x, y, horizontal)) {
            for (int i = 0; i < SHIP_SIZE; i++) {
                if (horizontal) {
                    board[x][y + i] = 3; // marca navio
                } else {
                    board[x + i][y] = 3; // marca navio
                }
            }
            placed = 1;
        }
    }
}

// Exibe o tabuleiro na tela
void printBoard(int board[ROWS][COLS]) {
    printf("   ");
    for (char c = 'A'; c < 'A' + COLS; c++) {
        printf(" %c", c); // cabeçalho com letras A a J
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%2d ", i + 1); // número da linha
        for (int j = 0; j < COLS; j++) {
            printf(" %d", board[i][j]); // valor da célula (0 = água, 3 = navio)
        }
        printf("\n");
    }
}

int main() {
    int board[ROWS][COLS];

    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    initializeBoard(board); // Preenche com água

    for (int i = 0; i < SHIP_COUNT; i++) {
        placeShip(board); // Coloca navios
    }

    printBoard(board); // Mostra o tabuleiro completo

    return 0;
}