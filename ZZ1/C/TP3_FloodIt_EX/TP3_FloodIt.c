#include "fonctions.h"

int main() {

  srand(time(NULL));

  int **grille;
  int val_couleur;
  int essais = 0;

  int essais_max;
  int nb_couleur;
  int taille;

  do {
    printf("saisissez le nombre de couleurs de la grille (entre 1 et 8 "
           "couleurs)\n");
    scanf("%d", &nb_couleur);

    if (nb_couleur <= 0)
      printf("ça ne marchera pas si il y n'y a aucune couleur\n\n");
    else if (nb_couleur > 8)
      printf("vous avez sélectionné trop de couleurs \n\n");
    else
      nb_couleur--;

  } while (nb_couleur <= 0 || nb_couleur > 8);

  do {
    printf("saisissez la taille de la grille\n");
    scanf("%d", &taille);

    if (taille <= 0)
      printf("une grille avec une taille nulle ou négative n'existe pas \n\n");
  } while (taille <= 0);

  do {
    printf("saisissez le nombre d'essais que vous voulez \n");
    scanf("%d", &essais_max);

    if (essais_max <= 0)
      printf("vous n'y arriverez pas sans essais\n\n");
  } while (essais_max <= 0);

  grille = (int **)malloc(taille * sizeof(int *));
  if (grille == NULL) {
    perror("erreur d'allocation de la grille");
    return -1;
  }

  for (int i = 0; i < taille; i++) {
    grille[i] = (int *)malloc(taille * sizeof(int));
    if (grille[i] == NULL) {
      for (int j = 0; j < i; j++)
        free(grille[j]);
      free(grille);
      perror("erreur d'allocation de la grille");
      return -1;
    }
  }

  Initialiser(grille, taille, nb_couleur);

  Afficher(grille, essais, taille, nb_couleur, essais_max);

  do {

    do {
      scanf("%d", &val_couleur);
      if (val_couleur < 0 || val_couleur > nb_couleur)
        printf("la valeur que vous avez saisi ne correspond pas � une "
               "couleur\n\n");
    } while (val_couleur < 0 || val_couleur > nb_couleur);

    if (grille[0][0] != val_couleur) {
      Remplir(grille, grille[0][0], val_couleur, 0, 0, taille);
      essais++;
    }

    Afficher(grille, essais, taille, nb_couleur, essais_max);

  } while (fin(grille, taille) == 0 && essais <= essais_max);

  if (essais > essais_max)
    printf("\nVous avez d�pass� la limite d'essais pour remplir la grille\n\n");
  else
    printf("\nBravo, vous avez rempli la grille en moins de %d essais\n\n",
           essais_max);

  for (int i = 0; i < taille; i++)
    free(grille[i]);

  free(grille);

  return 0;
}
