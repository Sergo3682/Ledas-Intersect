#include "../Headers/vector3d.h"
#include "../Headers/segment3d.h"
#include "../Headers/worker.h"

#include <cstdio>

int main()
{
    //scanf(const char *__restrict format, ...)
    //test
    //Vector3D a1(1, 2, 4), a2(1, -2, 3), b1(5, 3, 1), b2(1, -2, 3);
    Vector3D a1(0, 0, 0), a2(0, 2, -3), b1(0, -2, -2), b2(0, -1, 2);
    Segment3D a1a2(a1, a2), b1b2(b1, b2);
    Worker Solver(&a1a2, &b1b2);
    if (Solver.isIntersect())
    {
        Vector3D Answer = Solver.Intersect();
        printf("Answer: %s\n", Answer.toString().c_str());
    }
    else
    {
        printf("Line1(%s, %s) and Line2(%s, %s) do not intersect!\n", a1.toString().c_str(), a2.toString().c_str(),
               b1.toString().c_str(), b2.toString().c_str()
              );
    }


    return 0;
}