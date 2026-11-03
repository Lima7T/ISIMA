#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// IMPORTANT : FAIRE EN SORTE QUE LES MACROS "MIN" ET "MAX" SOIENT TOUJOURS
// INDIQUEES COMME MIN<=MAX
#define MAX 100
#define MIN 0

int RandomNuberGenerator(int *output_valeur_generee, int input_min,
                         int input_max) {

  if (input_max >= input_min)
    *output_valeur_generee = (rand() % (input_max + 1)) + input_min;
  else
    *output_valeur_generee = (rand() % (input_min + 1)) + input_max;

  return 0;
}

int main() {

  int valeur_a_trouver = -1;
  int entree_utilisateur;
  int nb_tentatives = -1;
  srand(time(NULL));

  while (nb_tentatives < 1) {
    printf("Utilisateur, saisis le nombre (positif non nul) d'essais que tu "
           "veux avoir \n");
    scanf("%d", &nb_tentatives);
  }

  if (RandomNuberGenerator(&valeur_a_trouver, MIN, MAX) == 0) {
    printf("Une valeur aléatoire entre %d et %d a été générée \n\n", MIN, MAX);
    do {
      entree_utilisateur = -1;
      printf("Utilisateur, saisis une valeur entre 0 et 100 (les deux bornes "
             "incluses)\n");
      while (!(entree_utilisateur >= MIN && entree_utilisateur <= MAX)) {
        scanf("%d", &entree_utilisateur);

        if (!(entree_utilisateur >= 0 && entree_utilisateur <= 100))
          printf("Sérieux ? J'ai dis entre 0 et 100, c'est trop dur à "
                 "comprendre ? \n ");
      }

      if (entree_utilisateur > valeur_a_trouver) {
        printf("Raté, la valeur à trouver est plus petite que celle que tu as "
               "saisi\n");
        nb_tentatives--;
        printf("Il te reste %d essais", nb_tentatives);
      } else if (entree_utilisateur < valeur_a_trouver) {
        printf("Raté, la valeur à trouver est plus grande que celle que tu as "
               "saisi\n");
        nb_tentatives--;
        printf("Il te reste %d essais \n", nb_tentatives);
      }

      printf("%d\n", valeur_a_trouver);

    } while (nb_tentatives > 0 && entree_utilisateur != valeur_a_trouver);

    if (nb_tentatives == 0) {
      printf("Perdu utilisateur, mais tu peux réessayer \n");
    } else if (entree_utilisateur == valeur_a_trouver) {
      printf("Bravo utilisateur, tu a trouvé que la valeur cachée était %d \n",
             valeur_a_trouver);
    }
  }

  return 0;
}