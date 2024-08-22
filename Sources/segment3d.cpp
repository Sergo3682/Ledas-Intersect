#include "../Headers/segment3d.h"

Segment3D::Segment3D()
{
    this->start = Vector3D();
    this->end = Vector3D();
    setSegmentVect();
}

Segment3D::Segment3D(Vector3D start, Vector3D end)
{
    this->start = start;
    this->end = end;
    setSegmentVect();
}

void Segment3D::setSegmentVect()
{
    double X, Y, Z;
    X = end.getX() - start.getX();
    Y = end.getY() - start.getY();
    Z = end.getZ() - start.getZ();
    this->SegmentVect = Vector3D(X, Y, Z);
}