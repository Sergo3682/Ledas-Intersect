#include "../Headers/matrix.h"
#include <utility>
#include <vector>

#ifdef DEBUG
#include <cstdio>
#endif

Matrix::Matrix(double a1, double b1, double a2, double b2, double c1, double c2)
{
    swapped = false;

    A = {
        {a1, b1},
        {a2, b2}
        };
    B = {c1, c2};

    #ifdef DEBUG
    printMatr();
    printf("Created!\n");
    #endif
}

double Matrix::gaussianElimination()
{
    rowSwap();
    rowMult();
    std::vector<double> ans = getAns();
    /*returns t parametr*/
    return swapped ? ans[1] : ans[0];
}

void Matrix::rowSwap()
{
    int n = B.size();

    for (int i = 0; i < n; i++)
    {
        if (A[i][i] == 0)
        {
            swapped = false;
            for (int j = i + 1; j < n; j++)
            {
                if (A[j][i] != 0)
                {
                    std::swap(A[i], A[j]);
                    std::swap(B[i], B[j]);
                    swapped = true;
                    #ifdef DEBUG
                    printMatr();
                    printf("swaped\n");
                    #endif
                    break;
                }
            }
            #ifdef DEBUG
            if (!swapped)
            {
                printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!cant solve\n");
            }
            #endif
        }
    }
}

std::vector<double> Matrix::getAns()
{
    int n = B.size();
    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = B[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
    return x;
}

void Matrix::rowMult()
{
    int n = B.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i +1; j < n; j++)
        {
            double fact = A[j][i] / A[i][i];
            for (int k = i; k < n; k++)
            {
                A[j][k] -= fact * A[i][k];
            }
            B[j] -= fact * B[i];
        }
    }
    #ifdef DEBUG
    printMatr();
    #endif
}

#ifdef DEBUG
void Matrix::printMatr()
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