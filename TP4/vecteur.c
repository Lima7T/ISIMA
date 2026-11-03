#include<stdlib.h>
#include "vecteur.h"

// definition des fonctions declarees dans vecteur.h


void vecteurToFile(FILE * input_file, int input_ordre, float * input_valeurs)
{
    if(input_file != NULL)
    {
        fprintf(input_file,"%d\n",input_ordre);
        for(int i = 0; i < input_ordre; i++)
        {
            fprintf(input_file,"%f ", *(input_valeurs+i));
        }
        fprintf(input_file,"\n");
    }
}


/*
float * vecteurFromFileByName()
{
	float * retour = NULL;

	return retour;
}
*/

/*
float   produitScalaire()
{
	float retour;

    return retour;
}
*/
