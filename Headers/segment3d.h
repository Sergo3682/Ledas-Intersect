#ifndef SEGMENT3D_H
#define SEGMENT3D_H

#include "../Headers/vector3d.h"

class Segment3D
{
public:
    Segment3D();
    Segment3D(Vector3D start, Vector3D end);
    Vector3D getDirectVect();
private:
    Vector3D start;
    Vector3D end;
    Vector3D DirectVect;

    void setDirectVect();
};
#endif // SEGMENT3D_H