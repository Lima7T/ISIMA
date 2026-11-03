#include "fonctions.h"

int main() {

  srand(time(NULL));

  int grille[TAILLE][TAILLE];
  int val_couleur;
  int essais = 0;
  Initialiser(grille);

  Afficher(grille, essais);

  do {

    do {
      scanf("%d", &val_couleur);
      if (val_couleur < 0 || val_couleur > COULEUR)
        printf("la valeur que vous avez saisi ne correspond pas � une "
               "couleur\n\n");
    } while (val_couleur < 0 || val_couleur > COULEUR);

    Remplir(grille, grille[0][0], val_couleur, 0, 0);
    essais++;
    Afficher(grille, essais);

  } while (fin(grille) == 0 && essais <= NBESSAIS);

  if (essais > NBESSAIS)
    printf("\nVous avez d�pass� la limite d'essais pour remplir la grille\n\n");
  else
    printf("\nBravo, vous avez rempli la grille en moins de %d essais\n\n",
           NBESSAIS);

  return 0;
}
