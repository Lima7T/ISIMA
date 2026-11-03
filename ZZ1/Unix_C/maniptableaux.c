#include <stdio.h>
#define TAILLE 50
#define VALEUR_INIT 100

void InitTableaux(int input_tableau[], const int input_taille_tableau,
                  const int input_valeur) {
  for (int i = 0; i < input_taille_tableau; i++) {
    input_tableau[i] = input_valeur;
  }
}

void PrintTableau(int input_tableau[], const int input_taille_tableau) {
  for (int i = 0; i < input_taille_tableau; i++) {
    printf("%d \r\n", input_tableau[i]);
  }
}

int MaxTableau(int input_tableau[], const int input_taille_tableau) {
  int local_val_return = -1;
  for (int i = 0; i < input_taille_tableau; i++) {
    if (input_tableau[i] >= local_val_return)
      local_val_return = input_tableau[i];
  }

  return local_val_return;
}

int MinTableau(int input_tableau[], const int input_taille_tableau) {
  int local_val_return = 6969;
  for (int i = 0; i < input_taille_tableau; i++) {
    if (input_tableau[i] <= local_val_return)
      local_val_return = input_tableau[i];
  }

  return local_val_return;
}

int MoyenneTableau(int input_tableau[], const int input_taille_tableau) {
  int local_val_return = 0;
  for (int i = 0; i < input_taille_tableau; i++)
    local_val_return += input_tableau[i];

  local_val_return = local_val_return / TAILLE;
  return local_val_return;
}

int main(void) {

  int tableau_dentiers[50] = {0};
  InitTableaux(tableau_dentiers, TAILLE, VALEUR_INIT);

  for (int i = 0; i < TAILLE; i++) {
    if (i % 2 == 0)
      tableau_dentiers[i] = tableau_dentiers[i] + i;
    else
      tableau_dentiers[i] = tableau_dentiers[i] - i;
  }

  PrintTableau(tableau_dentiers, TAILLE);
  printf("Valeur max du tableau : %d \r\n Valeur min du tableau : %d \r\n "
         "Valeur moyenne des valeurs du tableau : %d \r\n",
         MaxTableau(tableau_dentiers, TAILLE),
         MinTableau(tableau_dentiers, TAILLE),
         MoyenneTableau(tableau_dentiers, TAILLE));
  return 0;
}