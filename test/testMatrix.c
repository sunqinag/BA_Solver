
#include "Matrix.h"

int main()
{
    // float data[3][3] = {{55, 25, 15},
    //                     {30, 44, 2},
    //                     {11, 45, 77}};
    // Matrix3d matrix = CreateMatrix3d(data);

    // printMatrix(matrix);

    // float deterine = determinant(matrix);
    // printf("determine %f",deterine);

    // Matrix3d inv_matrix = inverse(matrix);
    // printf("inv matrix\n");
    // printMatrix(inv_matrix);

    float data[3] ={1,2,3};
    Vector3d vector3d = CreateVector3d(data);
    printVector(vector3d);
}
