#include <stdio.h>

int main() {
  char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  int tabuleiro[10][10];
  int navio1[3] = {3, 3, 3};
  int navio2[3] = {3, 3, 3};

  // Inicializa o tabuleiro com 0
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tabuleiro[i][j] = 0;
    }
  }

  int linha1 = 1;
  int coluna1 = 2;

  int linha2 = 3;
  int coluna2 = 4;

  // Verifica se os navios estão na mesma posição
  if ((linha1 == linha2) && (coluna1 == coluna2)) {
    printf(
        "Valores invalidos. Os dois navios nao podem ficar na mesma posicao "
        "(linhas "
        "e colunas iguais). Por favor, tente novamente\n\n");
    return 0;
  };

  // Verifica se as posições dos navios estão dentro dos limites do tabuleiro
  if (linha1 < 0 || linha1 > 9 || linha2 < 0 || linha2 > 9 || coluna1 < 0 ||
      coluna1 > 9 || coluna2 < 0 || coluna2 > 9) {
    printf(
        "Valores invalidos. Posicoes fora dos limites da tabuleiro (10 linhas "
        "e "
        "10 colunas). Por favor, tente novamente\n\n");
    return 0;
  };

  // Verifica se o navio horizontal cabe no tabuleiro
  if (coluna1 + 2 > 9) {
    printf("Navio horizontal nao cabe!\n");
    return 0;
  };

  // Preencha navio na horizontal
  for (int i = 0; i < 3; i++) {
    tabuleiro[linha1][coluna1 + i] = navio1[i];
  }

  // Verifica se o navio vertical cabe no tabuleiro
  if (linha2 + 2 > 9) {
    printf("Navio vertical nao cabe!\n");
    return 0;
  }

  // Preencha navio na vertical
  for (int i = 0; i < 3; i++) {
    tabuleiro[linha2 + i][coluna2] = navio2[i];
  }

  // Exibe o cabeçalho das colunas
  printf("    ");
  for (int i = 0; i < 10; i++) {
    printf("%c ", colunas[i]);
  }
  printf("\n");

  // Exibe cada linha com o número
  for (int i = 0; i < 10; i++) {
    printf("%d | ", i);
    for (int j = 0; j < 10; j++) {
      printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
  }

  return 0;
}
