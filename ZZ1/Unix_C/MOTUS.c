#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COLOR_RED "\033[1;31m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_STOP "\033[0m"

int RandomNuberGenerator(int input_min, int input_max) {

  int output_valeur_generee = -1;
  if (input_max >= input_min)
    output_valeur_generee = (rand() % (input_max + 1)) + input_min;
  else
    output_valeur_generee = (rand() % (input_min + 1)) + input_max;

  return output_valeur_generee;
}


int CheckWord(char input_mot_adeviner[], char input_mot_saisi[],
              int taille,
              int input_comptage_lettres[][taille]) {
  int local_flag_worddiscovered = 1;
  int local_incrementation = 0;
  int local_tableau_comptage_lettre[26];

  for (int i = 0; i < 26; i++)
  {
      local_tableau_comptage_lettre[i] = input_comptage_lettres[1][i];
  }

  while (input_mot_saisi[local_incrementation] != '\0')
  {
      if (input_mot_adeviner[local_incrementation] == toupper(input_mot_saisi[local_incrementation]))
      {

          printf("%s%c%s", COLOR_RED, input_mot_adeviner[local_incrementation], COLOR_STOP);
          local_tableau_comptage_lettre[toupper(input_mot_saisi[local_incrementation])]--;
      }
      else if (local_tableau_comptage_lettre[toupper(input_mot_saisi[local_incrementation]) - 'A'] > 0)
      {


          printf("%s%c%s", COLOR_YELLOW, input_mot_saisi[local_incrementation], COLOR_STOP);
          local_tableau_comptage_lettre[toupper(input_mot_saisi[local_incrementation])]--;
          local_flag_worddiscovered = 0;

      }
      else
      {
          printf("%c", input_mot_saisi[local_incrementation]);
          local_flag_worddiscovered = 0;
      }
    local_incrementation++;
  }



  return local_flag_worddiscovered;
}


int CountWord(char input_mot_saisi[], int taille,
              int input_comptage_lettres[][taille], int choix_mot) {
  for (int i = 0; input_mot_saisi[i] != '\0'; i++) {
    if (isalpha(input_mot_saisi[i])) {

      input_comptage_lettres[choix_mot][toupper(input_mot_saisi[i]) - 'A']++;
    }
  }
  return 0;
}

int main() {

  srand(time(NULL));

  // char tableau_ref_lettres[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

  int tableau_compteur_lettres[2][26] = {{0}, {0}};
  int flag_word_discovered = 0;

  char liste_mots[16][6] = {
      "AGENT", "AGILE", "AIDER", "BADGE", "BIERE", "CABLE", "CACHE", "CACAO",
      "CARTE", "CLEFS", "ECRAN", "GEEEK", "ISIMA", "MULOT", "PUCES", "VIDEO"};

  char mot_saisi[6] = {0};
  char mot_adeviner[6];

  strncpy(mot_adeviner, liste_mots[RandomNuberGenerator(0, 15)], 5);

  printf("%s\n", mot_adeviner);
  CountWord(mot_adeviner, 26, tableau_compteur_lettres,0);

  while (flag_word_discovered == 0)
  {
      printf("\nSaisissez un mot \n");
      scanf("%s", mot_saisi);

      CountWord(mot_saisi, 26, tableau_compteur_lettres, 1);

      flag_word_discovered = CheckWord(mot_adeviner, mot_saisi,26,tableau_compteur_lettres);

  }




  return 0;
}
