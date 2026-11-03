#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_DOUBLE 1000000

/// 2.1
/*#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>


int main()
{

    printf("Taille en octets de 'char' : %d\n", sizeof(char));
    printf("Taille en octets de 'short int' : %d\n", sizeof(short int));
    printf("Taille en octets de 'long' : %d\n", sizeof(long));
    printf("Taille en octets de 'long int' : %d\n", sizeof(long int));
    printf("Taille en octets de 'float' : %d\n", sizeof(float));
    printf("Taille en octets de 'double' : %d\n", sizeof(double));
    printf("Taille en octets de 'bool' : %d\n", sizeof(bool));




    return 0;
}
*/

/// 2.2
/*
#include <stdio.h>
#include <stdlib.h>

void afficher(int tab[]) {
   printf("taille memoire afficher() : %lu\n", sizeof(tab));
   // il y a desormais un avertissement pour cet usage
}

int main()
{

  double tab[20];

  printf("taille memoire main(): %lu\n", sizeof(tab));
  printf("nb elements : %lu\n", sizeof(tab)/sizeof(tab[0]));

  afficher(tab);

   return 0;
}
*/

/// 2.3
/*#include <stdio.h>
int main()
{
    int tab[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    printf("%d %d %d %d", tab[0][0], tab[1][1],tab[3][4],tab[0][5]);
///tab[1][1] == tab[0][5] return 0;
}
*/

/// 3
/*
   printf("%d", *((int*)p2));
   printf("%d", *(p1+6));

   p1 = NULL;
   //printf("%d", *p1);

   return 0;
}*/

/*
int compter1(char * chaine)
{
  int i = 0;

  while (*(chaine+i) != '\0')
     ++i;

  return i;
}

int compter2(char * chaine)
{
  char * s = chaine;

  while (*chaine != '\0')
     ++chaine;

  return chaine - s;
}

int compter3(char * chaine)
{
  char * s = chaine;

  while (*(s++) != '\0');

  return s - chaine;
}

int main()
{
    char chaine[] = "DeezNuts!";
    char chaine2[] = "DeezNuts!";

    printf("%d ", compter3(chaine));
    printf("%d", strcmp(chaine, chaine2));

    return 0;
}
*/
/*
int main() {
   char * s1 = "loic";
   *s1 = 'L';          // 1
   printf("%s", s1);
   printf("%c", *s1);
   printf("%s", s1+2);    // 2
   // printf("%s", ++s1); // 3


  char s2[] = "isima";
  s2[0] = 'I';
  printf("%s", s2);
  printf("%s", ++s2);  // 4

 return 0;
}
*/

/// 6
/*
void saisir(char * s)
{
  printf("Saisir une chaine\n");
  scanf("%s", s);
}

int main()
{
  char s[15];

  printf("Entrer votre prenom. ");
  saisir(s);
  printf("Bonjour %s!\n", s);

  if (strcmp(s,"ddd")) printf("bizarre \n");

  return 0;
}
*/

int main() {
  double *tab = NULL;

  // tab = malloc(TAILLE_DOUBLE * sizeof(double));
  if (tab == NULL) {
    perror("Erreur d'allocation");
    return -1;
  }

  for (int i = 0; i < TAILLE_DOUBLE; i++) {
    tab[i] = i * i;
    printf("%lf   ", tab[i]);
  }
  free(tab);

  return 0;
}
