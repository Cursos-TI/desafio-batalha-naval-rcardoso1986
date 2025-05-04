#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {

    int choice;

    // Exibe as opções para o usuário escolher qual arquivo rodar
    printf("Escolha o nivel que você deseja rodar:\n");
    printf("1. Novato\n");
    printf("2. Aventureiro\n");
    printf("3. Mestre\n");
    printf("4. Sair\n");
    printf("Digite o número da opção: ");
    scanf("%d", &choice);

     // Verifica a escolha do usuário e executa o arquivo correspondente
     switch (choice) {
        case 1:
            // Nível Novato - Posicionamento dos Navios
            // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
            // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
            // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
            printf("Executando o nivel novato...\n");
            system("gcc novato.c -o novato && ./novato");
            break;
        case 2:
            // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
            // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
            // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
            // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

            printf("Executando o nivel aventureiro...\n");
            system("gcc aventureiro.c -o aventureiro && ./aventureiro");
            break;
        case 3:

            // Nível Mestre - Habilidades Especiais com Matrizes
            // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
            // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
            // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

            printf("Executando o nivel mestre...\n");
            system("gcc mestre.c -o mestre && ./mestre");
            break;
        case 4:
            printf("Fim \n");
            return 0;
        default:
            printf("Opção inválida! Por favor, tente novamente.\n");  // Caso a escolha não seja válida
    }

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    printf("========================================\n");

    main();
    return 0;
}
