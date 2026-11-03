#include <math.h>
#include <stdio.h>

int main() {
  int a = 3;
  int b = 2;
  int c = -1;

  float x0, x1, x2;

  int delta = pow(b, 2) - 4 * a * c;

  if (delta < 0)
    printf("le polynome du 2nd degré %dx² + %dx + %d ne possède pas de racines "
           "réelles\n",
           a, b, c);
  else if (delta == 0) {
    x0 = ((-1) * b / 2.0 * a);
    printf("le polynome du 2nd degré %dx² + %dx + %d possède une racine réelle "
           "double qui est x0 = %f \n",
           a, b, c, x0);
  } else {
    x1 = (((-1) * b + sqrt(delta)) / (2.0 * a));
    x2 = (((-1) * b - sqrt(delta)) / (2.0 * a));

    printf("le polynome du 2nd degré %dx² + %dx + %d possède deux racines "
           "réelles qui sont x1 = %f et x2 = %f \n",
           a, b, c, x1, x2);
  }
}