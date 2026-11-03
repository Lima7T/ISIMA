#include "fonctions.h"
#include "../mes_fonctions.h"

/*int RandomIntegerGenerator(int input_min, int input_max) {
  int local_return_value = -1;

  local_return_value = (rand() % input_max) + input_min;

  return local_return_value;
}*/

int Initialiser(int **input_grille, int input_taille, int input_nb_couleur) {

  for (int i = 0; i < input_taille; i++) {
    for (int j = 0; j < input_taille; j++)
      input_grille[i][j] = RandomIntegerGenerator(0, input_nb_couleur);
  }

  return 0;
}

int Afficher(int **input_grille, int input_nb_essais, int input_taille,
             int input_nb_couleur, int input_nb_essais_max) {

  static const char WORDART[6][42] = {
      {"______ _                 _ _____ _     \n\0"},
      {"|  ___| |               | |_   _| |    \n\0"},
      {"| |_  | | ___   ___   __| | | | | |_   \n\0"},
      {"|  _| | |/ _ \\ / _ \\ / _` | | | | __|  \n\0"},
      {"| |   | | (_) | (_) | (_| |_| |_| |_ _ \n\0"},
      {"\\_|   |_|\\___/ \\___/ \\__,_|\\___/ \\__(_)\n\0"}};

  printf("%s%s%s%s%s%s%s\n\n", DEL, WORDART[0], WORDART[1], WORDART[2],
         WORDART[3], WORDART[4], WORDART[5]);

  /*printf("012345\n%s40m %s41m %s42m %s43m %s44m %s45m %s\n\n\n Essais utilis�s
  "
         ": %d/%d\n\n\n",
         ANSI, ANSI, ANSI, ANSI, ANSI, ANSI, ANSI_STOP, input_nb_essais,
         NBESSAIS + 1);

  for (int i = 0; i < TAILLE; i++) {
    for (int k = 0; k < 2; k++) {
      for (int j = 0; j < TAILLE; j++)
        printf("%s%dm   ", ANSI, input_grille[i][j] + 40);

      printf("%s\n", ANSI_STOP);
    }
  }*/

  for (int i = 0; i <= input_nb_couleur; i++)
    printf("%d", i);
  printf("\n");
  for (int i = 0; i <= input_nb_couleur; i++)
    printf("%s%dm ", ANSI, 40 + i);
  printf("%s\n\n\nEssais utilisés : %d/%d\n\n\n", ANSI_STOP, input_nb_essais,
         input_nb_essais_max);

  for (int i = 0; i < input_taille; i++) {
    for (int k = 0; k < 2; k++) {
      for (int j = 0; j < input_taille; j++)
        printf("%s%dm   ", ANSI, input_grille[i][j] + 40);

      printf("%s\n", ANSI_STOP);
    }
  }

  return 0;
}

int Remplir(int **input_grille, int input_couleur_actuelle,
            int input_choix_couleur, int input_col, int input_lin,
            int input_taille) {
  int local_case_adj[4][2] = {{input_lin - 1, input_col + 0},
                              {input_lin + 0, input_col + 1},
                              {input_lin + 1, input_col + 0},
                              {input_lin + 0, input_col - 1}};

  if (input_grille[input_lin][input_col] == input_couleur_actuelle &&
      input_choix_couleur != input_couleur_actuelle) {
    input_grille[input_lin][input_col] = input_choix_couleur;

    for (int i = 0; i < 4; i++) {
      if (local_case_adj[i][0] >= 0 &&
          local_case_adj[i][0] <= input_taille - 1 &&
          local_case_adj[i][1] >= 0 &&
          local_case_adj[i][1] <= input_taille - 1) {
        Remplir(input_grille, input_couleur_actuelle, input_choix_couleur,
                local_case_adj[i][1], local_case_adj[i][0], input_taille);
      }
    }
  }
  return 0;
}

int fin(int **input_grille, int input_taille) {
  int local_flag_success = 1;

  for (int i = 0; i < input_taille; i++) {
    for (int j = 0; j < input_taille; j++) {
      if (input_grille[i][j] != input_grille[0][0])
        local_flag_success = 0;
    }
  }
  return local_flag_success;
}
