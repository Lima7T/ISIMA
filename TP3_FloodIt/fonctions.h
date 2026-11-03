#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COULEUR 5
#define TAILLE 15
#define NBESSAIS 25
#define DEL "\x1b[2J\x1b[H"
#define ANSI "\033["
#define ANSI_STOP "\033[0m"

int Initialiser(int input_grille[TAILLE][TAILLE]);

int Afficher(int input_grille[TAILLE][TAILLE], int input_nb_essais);

int Remplir(int input_grille[TAILLE][TAILLE], int input_couleur_actuelle,
            int input_choix_couleur, int input_col, int input_lin);

int fin(int input_grille[TAILLE][TAILLE]);

#endif // FONCTIONS_H_INCLUDED
