#include "../Headers/vector3d.h"
#include "../Headers/segment3d.h"
#include "../Headers/worker.h"

#include <iostream>
#include <vector>

std::vector<std::vector<double>> coords
{
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

void readInput()
{
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            std::cout << "Enter coordinates X Y Z of Point #" << j + 1 << " of Line #"<< i + 1<< "\n";
            std::cin >> coords[2*i + j][0] >> coords[2*i + j][1] >> coords[2*i + j][2];
        }
    }
}

void initVect3D(Vector3D* vec)
{
    vec->setCoords(coords[0][0], coords[0][1], coords[0][2]);
    coords.erase(coords.begin());
}

void initSegm3D(Segment3D* segm, Vector3D* s, Vector3D* e)
{
    segm->setNewAttributes(s, e);
}

void solveProblem(Segment3D* a1a2, Segment3D* b1b2)
{
    Worker Solver(a1a2, b1b2);

    if (Solver.isIntersect())
    {
        Vector3D Answer = Solver.Intersect();
        std::cout << "Answer: " << Answer.toString().c_str() << "\n";
    }
    else
    {
        std::cout << "Line1 and line2 have no point of intersection" << "\n";
    }
}

int main()
{
    Vector3D a1, a2, b1, b2;
    Segment3D a1a2, b1b2;
    readInput();

    initVect3D(&a1);
    initVect3D(&a2);
    initVect3D(&b1);
    initVect3D(&b2);

    initSegm3D(&a1a2, &a1, &a2);
    initSegm3D(&b1b2, &b1, &b2);

    solveProblem(&a1a2, &b1b2);

    return 0;
}