#include <stdio.h>

#define NAVIO 3

int main() {
  char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  int tabuleiro[10][10];

  // Inicializa o tabuleiro com 0
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tabuleiro[i][j] = 0;
    }
  }

  // Coordernadas iniciais
  int linha1 = 1, coluna1 = 2;
  int linha2 = 3, coluna2 = 4;
  int linha3 = 5, coluna3 = 7;
  int linha4 = 6, coluna4 = 3;

  // Verifica se os navios estão na mesma posição
  if (((linha1 == linha2) && (coluna1 == coluna2)) ||
      ((linha3 == linha4) && (coluna3 == coluna4))) {
    printf(
        "Valores invalidos. Os dois navios nao podem ficar na mesma posicao "
        "(linhas "
        "e colunas iguais). Por favor, tente novamente\n\n");
    return 0;
  };

  // Verifica se as posições dos navios estão dentro dos limites do tabuleiro
  if (linha1 < 0 || linha1 > 9 || linha2 < 0 || linha2 > 9 || linha3 < 0 ||
      linha3 > 9 || linha4 < 0 || linha4 > 9 || coluna1 < 0 || coluna1 > 9 ||
      coluna2 < 0 || coluna2 > 9 || coluna3 < 0 || coluna3 > 9 || coluna4 < 0 ||
      coluna4 > 9) {
    printf(
        "Valores invalidos. Posicoes fora dos limites da tabuleiro (10 linhas "
        "e "
        "10 colunas). Por favor, tente novamente\n\n");
    return 0;
  };

  // Navio 1 (horizontal)

  // Verifica se o navio horizontal cabe no tabuleiro
  if (coluna1 + 2 > 9) {
    printf("Navio horizontal nao cabe!\n");
    return 0;
  };

  for (int i = 0; i < 3; i++) {
    if (tabuleiro[linha1][coluna1 + i] == 3) {
      printf("Sobreposicao de navios!\n");
      return 0;
    }
  }

  // Preencha navio na horizontal
  for (int i = 0; i < 3; i++) {
    tabuleiro[linha1][coluna1 + i] = NAVIO;
  }

  // Navio 2 (vertical)

  // Verifica se o navio vertical cabe no tabuleiro
  if (linha2 + 2 > 9) {
    printf("Navio vertical nao cabe!\n");
    return 0;
  }

  for (int i = 0; i < 3; i++) {
    if (tabuleiro[linha2 + i][coluna2] == 3) {
      printf("Sobreposicao de navios!\n");
      return 0;
    }
  }

  // Preencha navio na vertical
  for (int i = 0; i < 3; i++) {
    tabuleiro[linha2 + i][coluna2] = NAVIO;
  }

  // Navio 3 (diagonal principal)

  // Verifica se o navio diagonal cabe no tabuleiro
  if (linha3 + 2 > 9 || coluna3 + 2 > 9) {
    printf("Navio diagonal nao cabe!\n");
    return 0;
  }

  for (int i = 0; i < 3; i++) {
    if (tabuleiro[linha3 + i][coluna3 + i] == 3) {
      printf("Sobreposicao de navios!\n");
      return 0;
    }
  }

  // Preencha navio na diagonal
  for (int i = 0; i < 3; i++) {
    tabuleiro[linha3 + i][coluna3 + i] = NAVIO;
  }

  // Navio 4 (diagonal secundária)

  // Verifica se o navio diagonal cabe no tabuleiro
  if (linha4 + 2 > 9 || coluna4 - 2 < 0) {
    printf("Navio diagonal nao cabe!\n");
    return 0;
  }

  for (int i = 0; i < 3; i++) {
    if (tabuleiro[linha4 + i][coluna4 - i] == 3) {
      printf("Sobreposicao de navios!\n");
      return 0;
    }
  }

  // Preencha navio na diagonal
  for (int i = 0; i < 3; i++) {
    tabuleiro[linha4 + i][coluna4 - i] = NAVIO;
  }

  // Exibe o cabeçalho das colunas
  printf("   ");
  for (int i = 0; i < 10; i++) {
    printf("%c ", colunas[i]);
  }
  printf("\n");

  // Exibe cada linha com o número
  for (int i = 0; i < 10; i++) {
    printf("%d| ", i);
    for (int j = 0; j < 10; j++) {
      printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
  }

  return 0;
}
