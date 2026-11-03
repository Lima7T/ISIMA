#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "code.h"

//typedef struct donnee donnee_t;

typedef struct donnee {
	int score;
	char jeu[100];
	char alias[40];
}donnee_t;

int main(void) {
	//printf("codez ce que vous voulez pour utiliser le tableau\n");
	
	donnee_t essai;
	essai.score = 69;
	strcpy(essai.jeu, "Team Fortress 2");
	strcpy(essai.alias, "Francis");
	
	donnee_t * p = &essai;
	
	printf("%d\n%s\n%s\n", p->score, p->jeu, p->alias);
	
	printf("\n%ld\n%ld\n%ld\n", sizeof(int), sizeof(char[40]), sizeof(donnee_t));
	
 	return 0;
 	
}
