#ifndef SEGMENT3D_H
#define SEGMENT3D_H

#include "../Headers/vector3d.h"

class Segment3D
{
public:
    Segment3D(Vector3D start, Vector3D end);
    ~Segment3D();
private:
    Vector3D start;
    Vector3D end;
    Vector3D segmentVect;
};
#endif // SEGMENT3D_H