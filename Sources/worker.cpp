#include "../Headers/worker.h"

#ifdef DEBUG
#include <cstdio>
#endif

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
    {
        #ifdef DEBUG
        printf("\t\tNot Parallel!!!\n");
        #endif
        return true;
    }
    else
    {
        #ifdef DEBUG
        printf("\t\tParallel :(\n");
        #endif
        return false;
    }
}

bool Worker::isCoplanar()
{
    Segment3D start1start2Segm(Segm1.getStartVect(), Segm2.getStartVect());
    Vector3D s1s2Vect = start1start2Segm.getDirectVect();
    if(ThirdOrderDet(s1s2Vect, DirectVect1, DirectVect2) == 0.0)
    {
        #ifdef DEBUG
        printf("\t\tCoplanar!!!\n");
        #endif
        return true;
    }
    else
    {
        #ifdef DEBUG
        printf("\t\tNot Coplanar :(\n");
        #endif
        return false;
    }
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
    bool ans = isNotParallel() && isCoplanar();
    #ifdef DEBUG
    printf("Is Intersect?\t\t%d\n", ans);
    #endif
    return ans;
}