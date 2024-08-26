#include "../Headers/vector3d.h"
#include "../Headers/segment3d.h"
#include "../Headers/worker.h"

int main()
{
    //test
    Vector3D a1(1, 2, 4), a2(1, -2, 3), b1(5, 3, 1), b2(1, -2, 3);
    Segment3D a1a2(a1, a2), b1b2(b1, b2);
    Worker tester(&a1a2, &b1b2);
    tester.isIntersect();
    return 0;
}