#include "fonctions.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int InitialiserGrille(int input_grille[N][N],
                      int input_co_cases_enlenvees[3][CASES_A_ENLEVER]) {
  int local_nombre_veleurs_enlevees = -1;
  int i, j, k = 0, l;
  int local_flag_val_already_exists = 0;

  int local_buffer[2] = {0};

  for (j = 0; j < 9; ++j) {
    for (i = 0; i < 9; ++i)
      input_grille[j][i] = (i + j * 3 + j / 3) % 9 + 1;
  }

  for (i = 0; i < CASES_A_ENLEVER; i++) {
    input_co_cases_enlenvees[0][k] = -1;
    input_co_cases_enlenvees[1][k] = -1;
    printf("%d %d\n", input_co_cases_enlenvees[0][k],
           input_co_cases_enlenvees[1][k]);
  }

  while (k < CASES_A_ENLEVER) {

    local_buffer[0] = rand() % 9;
    local_buffer[1] = rand() % 9;

    for (l = 0; l < CASES_A_ENLEVER; l++) {
      if (local_buffer[0] ==
              input_co_cases_enlenvees[0][(l + 1) % CASES_A_ENLEVER] &&
          local_buffer[1] ==
              input_co_cases_enlenvees[1][(l + 1) % CASES_A_ENLEVER])
        local_flag_val_already_exists = 1;
    }

    if (!local_flag_val_already_exists) {
      input_co_cases_enlenvees[0][k] = local_buffer[0];
      input_co_cases_enlenvees[1][k] = local_buffer[1];

      printf("%d %d\n", input_co_cases_enlenvees[0][k] + 1,
             input_co_cases_enlenvees[1][k] + 1);

      input_grille[input_co_cases_enlenvees[0][k]]
                  [input_co_cases_enlenvees[1][k]] = 0;
      k++;
    }

    local_flag_val_already_exists = 0;
  }

  local_nombre_veleurs_enlevees = k;
  return local_nombre_veleurs_enlevees;
}

int AfficherGrille(int input_grille[N][N], const char INPUT_WORDART[6][39]) {

  printf("\x1b[2J\x1b[H%s%s%s%s%s%s", INPUT_WORDART[0], INPUT_WORDART[1],
         INPUT_WORDART[2], INPUT_WORDART[3], INPUT_WORDART[4],
         INPUT_WORDART[5]);

  for (int i = 0; i < N; i++) {
    printf("-------------------------------------\n|");
    for (int j = 0; j < N; j++)
      if (input_grille[i][j] == 0)
        printf(" %s%d%s |", JAUNE, input_grille[i][j], STOP);
      else
        printf(" %d |", input_grille[i][j]);
    printf("\n");
  }
  printf("-------------------------------------\n");
  return 0;
}

int Saisir(int input_grille[N][N],
           int input_co_cases_enlenvees[3][CASES_A_ENLEVER],
           const char INPUT_WORDART[6][39], int *input_nb_cases_a_remplir) {
  int local_flag_success = -1;
  int local_col = -1;
  int local_lin = -1;
  int local_val = -1;

  do {

    AfficherGrille(input_grille, INPUT_WORDART);

    printf("Cases restantes � remplir : %d\nSaisissez le num�ro de la ligne et "
           "de la colonne de la case � remplir ainsi que sa valeur\n\nLigne : ",
           *input_nb_cases_a_remplir);

    scanf("%d", &local_lin);
    printf("Colonne : ");
    scanf("%d", &local_col);
    printf("Valeur : ");
    scanf("%d", &local_val);
    printf("\n\n");

    if (local_lin > 9 || local_lin < 1 || local_col > 9 || local_col < 1)
      printf("Les coordonn�es que vous avez saisi sont en dehors de la "
             "grille\n\n");
    else if (input_grille[local_lin - 1][local_col - 1] != 0)
      printf("La case dont vous avez saisi les coordonn�es n'est pas vide\n\n");
    else if (!(local_val <= 9 && local_val >= 1))
      printf("La valeur � ajouter que vous avez saisi n'est pas comprise entre "
             "0 et 9\n\n");
    else {
      input_grille[local_lin - 1][local_col - 1] = local_val;
      printf(
          "La case de coordonn�es (%d;%d) � �t� remplie avec la valeur %d\n\n",
          local_lin, local_col, local_val);
      (*input_nb_cases_a_remplir)--;
      local_flag_success = 0;
    }

  } while (local_flag_success != 0);
  return local_flag_success;
}

int VerifLinCol(int input_grille[N][N], int input_choix_lincol,
                int numero_lincol) {

  int local_flag_success = -1;
  int tableau_verif[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

  switch (input_choix_lincol) {
  case 0: // lignes
    for (int i = 0; i < 9; i++)
      tableau_verif[input_grille[numero_lincol][i] - 1] -= 1;
    break;

  case 1: // colonnes
    for (int i = 0; i < 9; i++)
      tableau_verif[input_grille[i][numero_lincol] - 1] -= 1;
    break;

  default:
    break;
  }

  for (int j = 0; j < 9; j++) {
    if (tableau_verif[j] != 0) {
      local_flag_success = numero_lincol;
      printf("Erreur de saisie sur la ligne/colonne %d\n", numero_lincol + 1);
    }
  }

  return local_flag_success;
}

int VerifZone(int input_grille[N][N], int input_colZone, int input_linZone) {
  int local_flag_success = 0;
  int local_valeurs = 45;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      local_valeurs =
          local_valeurs -
          input_grille[input_linZone * 3 + j][input_colZone * 3 + i];
    }
  }

  if (local_valeurs == 0)
    local_flag_success = 1;
  else
    printf("Erreur de saisie dans la zone (%d;%d)\n", input_linZone,
           input_colZone);

  return local_flag_success;
}

int VerifGrille(int input_grille[N][N],
                int input_co_cases_enlenvees[3][CASES_A_ENLEVER],
                int *input_nb_val_a_corriger) {
  int local_flag_success = 0;
  int co_a_corriger[2] = {-1, -1};

  for (int i = 0; i < 9; i++) {
    if (VerifLinCol(input_grille, 0, i) != -1)
      co_a_corriger[0] = VerifLinCol(input_grille, 0, i) + 1;

    for (int j = 0; j < 9; j++) {
      if (VerifLinCol(input_grille, 1, i) + 1)
        co_a_corriger[1] = VerifLinCol(input_grille, 1, i) + 1;
      printf("%d ", co_a_corriger[0]);
      printf("%d\n", co_a_corriger[1]);

      for (int m = 0; m < CASES_A_ENLEVER; m++) {
        if (input_co_cases_enlenvees[0][m] == co_a_corriger[0] - 1 &&
            input_co_cases_enlenvees[1][m] == co_a_corriger[1] - 1) {
          input_grille[co_a_corriger[0] - 1][co_a_corriger[1] - 1] = 0;
          (*input_nb_val_a_corriger)++;
          printf("deeznuts");
        }
      }
    }
  }

  for (int k = 0; k < 3; k++) {
    for (int l = 0; l < 3; l++) {
      printf("%d", VerifZone(input_grille, l, k));
    }
  }

  if (*input_nb_val_a_corriger == 0)
    local_flag_success = 1;
  else
    printf("Il y a %d erreurs dans les valeurs saisies",
           *input_nb_val_a_corriger);

  return local_flag_success;
}
