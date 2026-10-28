#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define N 9

int InitialiserGrille(int A, int B, int input_grille[A][B], int input_val)
{
    /**
    for(int i = 0; i<N;i++)
    {
        for(int j = 0; j<N;j++)
            input_grille[i][j] = input_val;
    }
    return 0;**/

        int i, j, k;

    for(j=0;j<9; ++j)
    {
      for(i=0; i<9; ++i)
          input_grille[j][i] = (i + j*3 +j /3) %9 +1 ;
    }

    /**for(i=0;i<9; ++i)
    {
      for(j=0; j<9; ++j)
        printf("%d ", tab[i][j]);
      printf("\n");
    }**/
}

int AfficherGrille(int A, int B, int input_grille[A][B])
{
    for(int i = 0; i<N;i++)
    {
        printf("-------------------------------------\n|");
        for(int j = 0; j<N;j++)
            printf(" %d |", input_grille[i][j]);
        printf("\n");
    }
    printf("-------------------------------------\n");
    return 0;
}

int main()
{
    int grille[N][N];

    InitialiserGrille(N, N, grille, 0);
    AfficherGrille(N, N, grille);
    return 0;
}
