#include "../Headers/vector3d.h"
#include "../Headers/segment3d.h"
#include "../Headers/worker.h"
#include "../Headers/gauss.h"

int main()
{
    //test
    Vector3D a1(1, 2, 4), a2(1, -2, 3), b1(5, 3, 1), b2(1, -2, 3);
    Segment3D a1a2(a1, a2), b1b2(b1, b2);
    Worker tester(&a1a2, &b1b2);
    tester.isIntersect();
    Gauss GG(0, 4, -4, 5, 5-1, 3-2);

    return 0;
}