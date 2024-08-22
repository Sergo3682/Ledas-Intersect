#include "../Headers/worker.h"

Worker::Worker(Segment3D Segm1, Segment3D Segm2)
{
    this->Segm1 = Segm1;
    this->Segm2 = Segm2;
}

bool Worker::isNotParallel()
{
    Vector3D DirectVect1 = Segm1.getDirectVect();
    Vector3D DirectVect2 = Segm2.getDirectVect();

    double tmpX, tmpY, tmpZ;
    tmpX = DirectVect1.getX() / DirectVect2.getX();
    tmpY = DirectVect1.getY() / DirectVect2.getY();
    tmpZ = DirectVect1.getZ() / DirectVect2.getZ();

    if(tmpX != tmpY && tmpY != tmpZ && tmpX != tmpZ)
        return true;
    else
        return false;
}