#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "code.h"


// un petit commentaire ?
void afficherDonnee(FILE * file, donnee_t d) {
   // TO DO
   
   fprintf(file, "%s : %s avec %d\n", d.jeu, d.alias, d.score);
}

/*
// un petit commentaire ?
void saisirDonnee(FILE *file, donnee_t * p){
   // TO DO
}
*/
