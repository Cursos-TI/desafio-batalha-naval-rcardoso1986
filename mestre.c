#include <stdio.h>

#define ROWS 10
#define COLS 10

// Função para inicializar o tabuleiro com água (0)
void initializeBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;  // Água
        }
    }
}

// Função para imprimir o tabuleiro
void printBoard(int board[ROWS][COLS]) {
    printf("    ");
    for (char c = 'A'; c < 'A' + COLS; c++) {
        printf(" %c", c);  // Cabeçalhos das colunas A~J
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%2d ", i + 1);  // Cabeçalhos das linhas 1~10
        for (int j = 0; j < COLS; j++) {
            printf(" %d", board[i][j]);  // Valores no tabuleiro
        }
        printf("\n");
    }
}

// Função para aplicar o cone no tabuleiro
void applyCone(int board[ROWS][COLS], int x, int y) {
    // Formato do Cone
    int cone[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };

    // Verificando se a forma pode ser aplicada sem ultrapassar os limites
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int row = x + i;
            int col = y + j - 2;  // Ajustando as colunas para a posição correta
            if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
                // Só aplica se a célula estiver vazia (0)
                if (board[row][col] == 0) {
                    board[row][col] = cone[i][j];  // Aplica o valor 1 para o cone
                }
            }
        }
    }
}

// Função para aplicar o octaedro no tabuleiro
void applyOctahedron(int board[ROWS][COLS], int x, int y) {
    // Formato do Octaedro
    int octahedron[5][7] = {
        {0, 0, 0, 2, 0, 0, 0},
        {0, 0, 2, 2, 2, 0, 0},
        {0, 2, 2, 2, 2, 2, 0},
        {0, 0, 2, 2, 2, 0, 0},
        {0, 0, 0, 2, 0, 0, 0}
    };

    // Verificando se a forma pode ser aplicada sem ultrapassar os limites
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            int row = x + i;
            int col = y + j - 3;  // Ajustando as colunas para a posição correta
            if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
                // Só aplica se a célula estiver vazia (0)
                if (board[row][col] == 0) {
                    board[row][col] = octahedron[i][j];  // Aplica o valor 2 para o octaedro
                }
            }
        }
    }
}

// Função para aplicar a cruz no tabuleiro
void applyCross(int board[ROWS][COLS], int x, int y) {
    // Formato da Cruz
    int cross[5][5] = {
        {0, 0, 3, 0, 0},
        {0, 0, 3, 0, 0},
        {3, 3, 3, 3, 3},
        {0, 0, 3, 0, 0},
        {0, 0, 3, 0, 0}
    };

    // Verificando se a forma pode ser aplicada sem ultrapassar os limites
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int row = x + i;
            int col = y + j - 2;  // Ajustando as colunas para a posição correta
            if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
                // Só aplica se a célula estiver vazia (0)
                if (board[row][col] == 0) {
                    board[row][col] = cross[i][j];  // Aplica o valor 3 para a cruz
                }
            }
        }
    }
}

// Função principal
int main() {
    int board[ROWS][COLS];

    // Inicializa o tabuleiro
    initializeBoard(board);

    // Aplica o cone na posição (3, D) -> no índice (2, 3)
    applyCone(board, 6, 7);

    // Aplica o octaedro na posição (1, E) -> no índice (0, 4)
    applyOctahedron(board, 0, 4);

    // Aplica a cruz na posição (6, B) -> no índice (5, 1)
    applyCross(board, 5, 2);

    // Exibe o tabuleiro
    printBoard(board);

    return 0;
}


