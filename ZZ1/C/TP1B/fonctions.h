#ifndef FONCTIONS_HEADER
#define FONCTIONS_HEADER

#define N 9
#define CASES_A_ENLEVER 1
#define VERT "\x1b[32m"
#define ROUGE "\x1b[31m"
#define JAUNE "\x1b[33m"
#define STOP "\x1b[39m"
#define DEL "\x1b[2J\x1b[H"

int InitialiserGrille(int input_grille[N][N],
                      int input_co_cases_enlenvees[3][CASES_A_ENLEVER]);

int AfficherGrille(int input_grille[N][N], const char INPUT_WORDART[6][39]);

int Saisir(int input_grille[N][N],
           int input_co_cases_enlenvees[3][CASES_A_ENLEVER],
           const char INPUT_WORDART[6][39], int *input_nb_cases_a_remplir);

int VerifLinCol(int input_grille[N][N], int input_choix_lincol,
                int numero_lincol);

int VerifZone(int input_grille[N][N], int input_colZone, int input_linZone);

int VerifGrille(int input_grille[N][N],
                int input_co_cases_enlenvees[3][CASES_A_ENLEVER],
                int *input_nb_val_a_corriger);

#endif