#ifndef WORKER_H
#define WORKER_H

#include "../Headers/segment3d.h"
#include "vector3d.h"

class Worker
{
public:
    Worker(Segment3D Segm1, Segment3D Segm2);
    bool isIntersect();
//private:
    Segment3D Segm1;
    Segment3D Segm2;
    Vector3D DirectVect1;
    Vector3D DirectVect2;
    bool isNotParallel();
    bool isCoplanar();
    double ThirdOrderDet(Vector3D s1s2Vect, Vector3D DirectVect1, Vector3D DirectVect2);
};

#endif // WORKER_H