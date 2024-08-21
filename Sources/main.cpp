#include "../Headers/vector3d.h"
#include <stdio.h>

int main()
{
    Vector3D testVec(12131, 4, -0.24);
    printf("X = %f, Y = %f, Z=%f\n", testVec.X, testVec.Y, testVec.Z);

    return 0;
}