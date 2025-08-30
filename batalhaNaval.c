#include <stdio.h>
#include <stdlib.h>

#define NAVIO 3
#define HABILIDADE 5

int main() {
  char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  int tabuleiro[10][10];

  // Coordernadas dos navios
  int linha1 = 1, coluna1 = 2;
  int linha2 = 3, coluna2 = 4;
  int linha3 = 5, coluna3 = 7;
  int linha4 = 6, coluna4 = 3;

  // Coordernadas das habilidades
  int linha_habilidade_cone = 5, coluna_habilidade_cone = 8;
  int linha_habilidade_cruz = 7, coluna_habilidade_cruz = 3;
  int linha_habilidade_octaedro = 2, coluna_habilidade_octaedro = 4;

  // Inicializa o tabuleiro
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) tabuleiro[i][j] = 0;
  }

  // --- VERIFICAÇÕES DE LIMITES E SOBREPOSIÇÃO DE NAVIOS ---
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

  if (((linha1 == linha2) && (coluna1 == coluna2)) ||
      ((linha3 == linha4) && (coluna3 == coluna4))) {
    printf(
        "Valores invalidos. Os dois navios nao podem ficar na mesma posicao "
        "(linhas "
        "e colunas iguais). Por favor, tente novamente\n\n");
    return 0;
  };

  // --- Coloca navio 1 (horizontal) ---

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

  for (int i = 0; i < 3; i++) tabuleiro[linha1][coluna1 + i] = NAVIO;

  // --- Coloca navio 2 (vertical) ---

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

  for (int i = 0; i < 3; i++) tabuleiro[linha2 + i][coluna2] = NAVIO;

  // --- Coloca navio 3 (diagonal principal) ---

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

  for (int i = 0; i < 3; i++) tabuleiro[linha3 + i][coluna3 + i] = NAVIO;

  // --- Coloca navio 4 (diagonal secundária) ---

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

  for (int i = 0; i < 3; i++) tabuleiro[linha4 + i][coluna4 - i] = NAVIO;

  // --- CRIANDO HABILIDADE CONE (5x5) ---

  int cone[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (j >= 2 - i && j <= 2 + i) {
        cone[i][j] = 1;  // área de efeito
      } else {
        cone[i][j] = 0;  // não afeta
      };
    }
  }

  // Aplica habilidade cone
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int x = linha_habilidade_cone + i - 2;
      int y = coluna_habilidade_cone + j - 2;
      if (x >= 0 && x < 10 && y >= 0 && y < 10) {
        if (cone[i][j] == 1 && tabuleiro[x][y] != NAVIO) {
          tabuleiro[x][y] = HABILIDADE;
        }
      };
    }
  }
  // --- CRIANDO HABILIDADE CRUZ (5x5) ---
  int cruz[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i == 2 || j == 2) {
        cruz[i][j] = 1;
      } else {
        cruz[i][j] = 0;
      }
    }
  }

  // Aplica habilidade cruz
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int x = linha_habilidade_cruz + i - 2;
      int y = coluna_habilidade_cruz + j - 2;
      if (x >= 0 && x < 10 && y >= 0 && y < 10) {
        if (cruz[i][j] == 1 && tabuleiro[x][y] != NAVIO)
          tabuleiro[x][y] = HABILIDADE;
      }
    }
  }

  // --- CRIANDO HABILIDADE OCTAEDRO (5x5) ---
  int octaedro[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (abs(i - 2) + abs(j - 2) <= 2) {
        octaedro[i][j] = 1;
      } else {
        octaedro[i][j] = 0;
      };
    }
  }
  // Aplica habilidade octaedro
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int x = linha_habilidade_octaedro + i - 2;
      int y = coluna_habilidade_octaedro + j - 2;
      if (x >= 0 && x < 10 && y >= 0 && y < 10) {
        if (octaedro[i][j] == 1 && tabuleiro[x][y] != NAVIO)
          tabuleiro[x][y] = HABILIDADE;
      }
    }
  }
  // --- EXIBE TABULEIRO ---
  printf("   ");
  for (int i = 0; i < 10; i++) {
    printf("%c ", colunas[i]);
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    printf("%d| ", i);
    for (int j = 0; j < 10; j++) {
      char simbolo;
      if (tabuleiro[i][j] == 0)
        simbolo = '~';  // água
      else if (tabuleiro[i][j] == NAVIO)
        simbolo = '#';  // navio
      else if (tabuleiro[i][j] == HABILIDADE)
        simbolo = '*';  // habilidade
      printf("%c ", simbolo);
    }
    printf("\n");
  }

  return 0;
}
