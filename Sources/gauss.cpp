#include "../Headers/gauss.h"

#ifdef DEBUG
#include <cstdio>
#endif

Gauss::Gauss(double a1, double b1, double a2, double b2, double c1, double c2)
{
    A = {
        {a1, b1},
        {a2, b2}
        };
    B = {c1, c2};

    #ifdef DEBUG
    printMatr();
    #endif
}

#ifdef DEBUG
void Gauss::printMatr()
{
    printf("Matrix =============\n");
    int n = B.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.3f ", A[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%.3f ", B[i]);
    printf("\nMatrix =============\n\n");
}
#endif