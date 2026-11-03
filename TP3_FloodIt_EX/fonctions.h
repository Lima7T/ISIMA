#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*#define COULEUR 5
#define TAILLE 15
#define NBESSAIS 25*/
#define DEL "\x1b[2J\x1b[H"
#define ANSI "\033["
#define ANSI_STOP "\033[0m"

int Initialiser(int **input_grille, int input_taille, int input_nb_couleur);

int Afficher(int **input_grille, int input_nb_essais, int input_taille,
             int input_nb_couleur, int input_nb_essais_max);

int Remplir(int **input_grille, int input_couleur_actuelle,
            int input_choix_couleur, int input_col, int input_lin,
            int input_taille);

int fin(int **input_grille, int input_taille);

#endif // FONCTIONS_H_INCLUDED
