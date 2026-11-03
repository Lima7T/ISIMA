#include "fonctions.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// #define CASES_A_ENLEVER 1

// printf("deeznuts");

int main() {
  srand(time(NULL));

  int nb_cases_a_remplir = CASES_A_ENLEVER;
  int grille[N][N];
  int co_cases[3][CASES_A_ENLEVER] = {{0}, {0}, {0}};
  int flag_grid_full = 0;
  const char WORDART[6][39] = {
      " _____           _       _          \n",
      "/  ___|         | |     | |         \n",
      "\\ `--. _   _  __| | ___ | | ___   _ \n",
      " `--. \\ | | |/ _` |/ _ \\| |/ / | | |\n",
      "/\\__/ / |_| | (_| | (_) |   <| |_| |\n",
      "\\____/ \\__,_|\\__,_|\\___/|_|\\_\\\\__,_|\n\n"};

  // printf("%s%s%s%s%s%s",WORDART[0], WORDART[1], WORDART[2], WORDART[3],
  // WORDART[4], WORDART[5] );
  printf("%d\n", InitialiserGrille(grille, co_cases));
  AfficherGrille(grille, WORDART);
  while (flag_grid_full != 1) {

    do {
      Saisir(grille, co_cases, WORDART, &nb_cases_a_remplir);
    } while (nb_cases_a_remplir > 0);

    flag_grid_full = VerifGrille(grille, co_cases, &nb_cases_a_remplir);
  }

  return 0;
}
