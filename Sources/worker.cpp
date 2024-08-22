#include "../Headers/worker.h"

Worker::Worker(Segment3D Segm1, Segment3D Segm2)
{
    this->Segm1 = Segm1;
    this->Segm2 = Segm2;
    this->DirectVect1 = Segm1.getDirectVect();
    this->DirectVect2 = Segm2.getDirectVect();
}

bool Worker::isNotParallel()
{
    double tmpX, tmpY, tmpZ;
    tmpX = DirectVect1.getX() / DirectVect2.getX();
    tmpY = DirectVect1.getY() / DirectVect2.getY();
    tmpZ = DirectVect1.getZ() / DirectVect2.getZ();

    if(tmpX != tmpY && tmpY != tmpZ && tmpX != tmpZ)
        return true;
    else
        return false;
}

bool Worker::isCoplanar()
{
    Segment3D start1start2Segm(Segm1.getStartVect(), Segm2.getStartVect());
    Vector3D s1s2Vect = start1start2Segm.getDirectVect();
    if(ThirdOrderDet(s1s2Vect, DirectVect1, DirectVect2) == 0.0)
        return true;
    else
        return false;
}

double Worker::ThirdOrderDet(Vector3D s1s2Vect, Vector3D DirectVect1, Vector3D DirectVect2)
{
    double res;
    res = (s1s2Vect.getX() * (DirectVect1.getY() * DirectVect2.getZ() - DirectVect1.getZ() * DirectVect2.getY())) - 
          (s1s2Vect.getY() * (DirectVect1.getX() * DirectVect2.getZ() - DirectVect1.getZ() * DirectVect2.getX())) + 
          (s1s2Vect.getZ() * (DirectVect1.getX() * DirectVect2.getY() - DirectVect1.getY() * DirectVect2.getX()));
    return res;
}

bool Worker::isIntersect()
{
    return isNotParallel() && isCoplanar();
}