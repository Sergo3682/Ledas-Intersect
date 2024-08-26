#ifndef GAUSS_H
#define GAUSS_H

#include <vector>

class Gauss
{
public:
    Gauss(double a1, double b1, double a2, double b2, double c1, double c2);
private:
    void rowSwap();
    void printMatr();
    std::vector<std::vector<double>> A;
    std::vector<double> B;
};
#endif //GAUSS_H