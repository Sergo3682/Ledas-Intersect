#include "../Headers/matrix.h"
#include <stdexcept>
#include <utility>

#ifdef DEBUG
#include <cstdio>
#endif

Matrix::Matrix(double a1, double b1, double a2, double b2, double c1, double c2)
{
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
    #ifdef DEBUG
    printf("t = %f, s = %f\n", ans[0], ans[1]);
    #endif
    return ans[0];
}

void Matrix::rowSwap()
{
    if ( ((A[0][0] == 0) || (A[1][1] == 0)) && ((A[0][1] != 0) && (A[1][0] != 0)) )
    {
        std::swap(A[0], A[1]);
        std::swap(B[0], B[1]);
        #ifdef DEBUG
        printMatr();
        printf("swapped\n");
        #endif
    }
    else if ( ((A[0][0] == 0) || (A[1][1] == 0)) && ((A[0][1] == 0) || (A[1][0] == 0)) )
    {
        #ifdef DEBUG
        printf("Can't solve this matrix! A[i][i] == 0 btw :(\n");
        #endif
        throw std::runtime_error("Can't solve this matrix! A[i][i] == 0 btw :(");
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

void Matrix::setNewAttributes(double a1, double b1, double a2, double b2, double c1, double c2)
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