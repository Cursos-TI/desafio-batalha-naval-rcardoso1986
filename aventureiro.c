#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10
#define SHIP_SIZE 3

// Inicializa o tabuleiro com água
void initializeBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            board[i][j] = 0;
}

// Verifica se pode colocar navio horizontal
int canPlaceHorizontal(int board[ROWS][COLS], int x, int y) {
    if (y + SHIP_SIZE > COLS) return 0;
    for (int i = 0; i < SHIP_SIZE; i++)
        if (board[x][y + i] != 0) return 0;
    return 1;
}

// Verifica se pode colocar navio vertical
int canPlaceVertical(int board[ROWS][COLS], int x, int y) {
    if (x + SHIP_SIZE > ROWS) return 0;
    for (int i = 0; i < SHIP_SIZE; i++)
        if (board[x + i][y] != 0) return 0;
    return 1;
}

// Verifica se pode colocar navio diagonal ↘️
int canPlaceDiagonalMain(int board[ROWS][COLS], int x, int y) {
    if (x + SHIP_SIZE > ROWS || y + SHIP_SIZE > COLS) return 0;
    for (int i = 0; i < SHIP_SIZE; i++)
        if (board[x + i][y + i] != 0) return 0;
    return 1;
}

// Verifica se pode colocar navio diagonal ↙️
int canPlaceDiagonalAnti(int board[ROWS][COLS], int x, int y) {
    if (x + SHIP_SIZE > ROWS || y - SHIP_SIZE + 1 < 0) return 0;
    for (int i = 0; i < SHIP_SIZE; i++)
        if (board[x + i][y - i] != 0) return 0;
    return 1;
}

// Coloca navio horizontal
void placeHorizontalShipAt(int board[ROWS][COLS], int x, int y) {
    if (canPlaceHorizontal(board, x, y)) {
        for (int i = 0; i < SHIP_SIZE; i++)
            board[x][y + i] = 3;
    } else {
        printf("Erro ao posicionar navio horizontal em (%d,%d)\n", x, y);
    }
}

// Coloca navio vertical
void placeVerticalShipAt(int board[ROWS][COLS], int x, int y) {
    if (canPlaceVertical(board, x, y)) {
        for (int i = 0; i < SHIP_SIZE; i++)
            board[x + i][y] = 3;
    } else {
        printf("Erro ao posicionar navio vertical em (%d,%d)\n", x, y);
    }
}

// Coloca navio diagonal ↘️
void placeDiagonalMainAt(int board[ROWS][COLS], int x, int y) {
    if (canPlaceDiagonalMain(board, x, y)) {
        for (int i = 0; i < SHIP_SIZE; i++)
            board[x + i][y + i] = 3;
    } else {
        printf("Erro ao posicionar navio diagonal ↘️ em (%d,%d)\n", x, y);
    }
}

// Coloca navio diagonal ↙️
void placeDiagonalAntiAt(int board[ROWS][COLS], int x, int y) {
    if (canPlaceDiagonalAnti(board, x, y)) {
        for (int i = 0; i < SHIP_SIZE; i++)
            board[x + i][y - i] = 3;
    } else {
        printf("Erro ao posicionar navio diagonal ↙️ em (%d,%d)\n", x, y);
    }
}

// Imprime o tabuleiro
void printBoard(int board[ROWS][COLS]) {
    printf("   ");
    for (char c = 'A'; c < 'A' + COLS; c++) {
        printf(" %c", c);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf(" %d", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[ROWS][COLS];
    initializeBoard(board);

    // Coloca navio horizontal na linha 1, coluna A (0,0)
    placeHorizontalShipAt(board, 0, 0);

    // Coloca navio vertical na linha 3, coluna D (2,3)
    placeVerticalShipAt(board, 2, 3);

    // Coloca navio diagonal ↘️ na linha 5, coluna E (4,4)
    placeDiagonalMainAt(board, 4, 4);

    // Coloca navio diagonal ↙️ na linha 2, coluna H (1,7)
    placeDiagonalAntiAt(board, 2, 8);

    printBoard(board);

    return 0;
}
