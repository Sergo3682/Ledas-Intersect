#ifndef WORKER_H
#define WORKER_H

#include "../Headers/segment3d.h"

class Worker
{
public:
    Worker(Segment3D Segm1, Segment3D Segm2);
    bool isIntersect();
private:
    Segment3D Segm1;
    Segment3D Segm2;
    bool isNotParallel();
    bool isCoplanar();
};

#endif // WORKER_H