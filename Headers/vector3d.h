#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <string>
class Vector3D
{
public:
    Vector3D();
    Vector3D(double X, double Y, double Z);
    double getX();
    double getY();
    double getZ();
    void setCoords(double X, double Y, double Z);
    std::string toString();
private:
    double X;
    double Y;
    double Z;
};
#endif // VECTOR3D_H
