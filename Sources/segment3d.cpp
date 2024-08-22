#include "../Headers/segment3d.h"

Segment3D::Segment3D()
{
    this->start = Vector3D();
    this->end = Vector3D();
    setDirectVect();
}

Segment3D::Segment3D(Vector3D start, Vector3D end)
{
    this->start = start;
    this->end = end;
    setDirectVect();
}

void Segment3D::setDirectVect()
{
    double X, Y, Z;
    X = end.getX() - start.getX();
    Y = end.getY() - start.getY();
    Z = end.getZ() - start.getZ();
    this->DirectVect = Vector3D(X, Y, Z);
}

Vector3D Segment3D::getDirectVect()
{
    return DirectVect;
}

Vector3D Segment3D::getStartVect()
{
    return start;
}