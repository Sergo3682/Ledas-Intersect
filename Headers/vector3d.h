#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D
{
public:
    Vector3D();
    Vector3D(double X, double Y, double Z);
    double getX();
    double getY();
    double getZ();
private:
    double X;
    double Y;
    double Z;
};
#endif // VECTOR3D_H
