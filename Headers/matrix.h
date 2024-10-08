#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix
{
public:
    Matrix(double a1, double b1, double a2, double b2, double c1, double c2);
    double gaussianElimination();
    void setNewAttributes(double a1, double b1, double a2, double b2, double c1, double c2);
private:
    void rowSwap();
    void rowMult();
    std::vector<double> getAns();
    #ifdef DEBUG
    void printMatr();
    #endif
    std::vector<std::vector<double>> A;
    std::vector<double> B;
};
#endif //MATRIX_H