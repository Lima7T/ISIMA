#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_BUFFER 100

/*int main() {
  char vide[] = "";
  char un[] = "un";
  char deux[40] = "deux\0trois";
  char quoi[30];

  printf("Chaine 1 : #%s#\n", vide);
  printf("Chaine 2 : #%s#\n", un);
  printf("Chaine 3 : #%s#\n", deux);
  printf("Chaine 4 : #%s#\n", quoi);

  printf("longueur de la chaine 1: %lu\n", strlen(vide));
  printf("longueur de la chaine 2: %lu\n", strlen(un));
  printf("longueur de la chaine 3: %lu\n", strlen(deux));
  printf("longueur de la chaine 4: %lu\n", strlen(quoi));

  return 0;
}*/

void InitTableaux(char input_tableau[], const int input_taille_tableau,
                  const char input_valeur) {
  for (int i = 0; i < input_taille_tableau; i++) {
    input_tableau[i] = input_valeur;
  }
}

int main() {

  char *nom;
  char *prenom;
  char *cat_prenom_nom;
  char buffer[TAILLE_BUFFER];
  int nombre;
  int size_prenom;
  int size_nom;
  int incrementation = 0;
  InitTableaux(buffer, TAILLE_BUFFER, '\0');

  while (!(scanf("%s", buffer) >= 0)) {
  }

  size_prenom = strlen(buffer);
  prenom = malloc(sizeof(char) * size_prenom);
  strncpy(prenom, buffer, size_prenom);

  InitTableaux(buffer, TAILLE_BUFFER, '\0');
  while (!(scanf("%s", buffer) >= 0)) {
  }

  size_nom = strlen(buffer);
  nom = malloc(sizeof(char) * size_nom);
  strncpy(nom, buffer, size_nom);

  scanf("%d\n", &nombre);

  printf("%s\n", prenom);

  cat_prenom_nom = malloc(sizeof(char) * (size_nom + size_prenom + 1));

  strcat(cat_prenom_nom, prenom);
  strcat(cat_prenom_nom, " \0");
  strcat(cat_prenom_nom, nom);

  while (cat_prenom_nom[incrementation] != '\0') {

    if (cat_prenom_nom[incrementation] != ' ')
      cat_prenom_nom[incrementation] -= 32;

    incrementation++;
  }

  while (nombre > 0) {
    printf("Merci %s \n", cat_prenom_nom);
    nombre--;
  }

  free(prenom);
  free(nom);
  free(cat_prenom_nom);

  return 0;
}