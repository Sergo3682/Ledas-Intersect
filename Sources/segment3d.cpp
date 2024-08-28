#include "../Headers/segment3d.h"

#ifdef DEBUG
#include <cstdio>
#endif

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

    #ifdef DEBUG
    printf("Segment3D(start(%.2f, %.2f, %.2f), end(%.2f, %.2f, %.2f))\t\tDirectVect(%.2f, %.2f, %.2f)\n",
           start.getX(), start.getY(), start.getZ(), end.getX(), end.getY(), end.getZ(), DirectVect.getX(), DirectVect.getY(), DirectVect.getZ());
    #endif
}

Vector3D Segment3D::getDirectVect()
{
    return DirectVect;
}

Vector3D Segment3D::getStartVect()
{
    return start;
}

void Segment3D::setNewAttributes(Vector3D* start, Vector3D* end)
{
    this->start = *start;
    this->end = *end;
    setDirectVect();
}