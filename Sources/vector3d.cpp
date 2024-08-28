#include "../Headers/vector3d.h"

Vector3D::Vector3D()
{
    this->X = 0;
    this->Y = 0;
    this->Z = 0;
}

Vector3D::Vector3D(double X, double Y, double Z)
{
    this->X = X;
    this->Y = Y;
    this->Z = Z;
}

double Vector3D::getX()
{
    return this->X;
}

double Vector3D::getY()
{
    return this->Y;
}

double Vector3D::getZ()
{
    return this->Z;
}

void Vector3D::setCoords(double X, double Y, double Z)
{
    this->X = X;
    this->Y = Y;
    this->Z = Z;
}

std::string Vector3D::toString()
{
    std::string str = "Vector3D(" + std::to_string(X) + ", " + std::to_string(Y) + ", " + std::to_string(Z) +")";
    return str;
}