#include "mes_fonctions.h"
#include <stdlib.h>

int RandomIntegerGenerator(int input_min, int input_max) {

  int output_valeur_generee = -1;
  if (input_max >= input_min)
    output_valeur_generee =
        (rand() % ((input_max + 1) - input_min)) + input_min;
  else
    output_valeur_generee =
        (rand() % ((input_min + 1) - input_max)) + input_max;

  return output_valeur_generee;
}