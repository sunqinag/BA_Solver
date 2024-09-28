#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int cols;
    int rows;
    float element[3][3];
} Matrix3d;

typedef struct
{
    int cols;
    int rows;
    float element[3];
} Vector3d;

void printMatrix(Matrix3d matrix)
{
    for (size_t i = 0; i < 3; i++)
    {
        printf("[%f,%f,%f]\n", matrix.element[i][0], matrix.element[i][1], matrix.element[i][2]);
    }
}

void printVector(Vector3d matrix)
{
    for (size_t i = 0; i < 3; i++)
    {
        printf("[%f]\n", matrix.element[i]);
    }
}


Matrix3d CreateMatrix3d(float data[3][3])
{
    Matrix3d matrix;
    matrix.cols = 3;
    matrix.rows = 3;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            matrix.element[i][j] = data[i][j];
        }
    }
    return matrix;
}

Vector3d CreateVector3d(float data[3]){
    Vector3d vector3d;
    vector3d.rows = 3;
    vector3d.cols = 1;
    for (size_t i = 0; i < 3; i++)
    {
        vector3d.element[i] = data[i];
    }
    return vector3d;
}
float determinant(Matrix3d *matrix)
{
    return matrix->element[0][0] * (matrix->element[1][1] * matrix->element[2][2] - matrix->element[1][2] * matrix->element[2][1]) - matrix->element[0][1] * (matrix->element[1][0] * matrix->element[2][2] - matrix->element[1][2] * matrix->element[2][0]) + matrix->element[0][2] * (matrix->element[1][0] * matrix->element[2][1] - matrix->element[1][1] * matrix->element[2][0]);
}


Matrix3d inverse(Matrix3d *matrix) {
    Matrix3d inverseMatrix;
    float det = determinant(matrix);

    if (det == 0) {
        printf("Matrix is not invertible.\n");
        exit(1);
    }

    inverseMatrix.element[0][0] = (matrix->element[1][1] * matrix->element[2][2] - matrix->element[1][2] * matrix->element[2][1]) / det;
    inverseMatrix.element[0][1] = -(matrix->element[0][1] * matrix->element[2][2] - matrix->element[0][2] * matrix->element[2][1]) / det;
    inverseMatrix.element[0][2] = (matrix->element[0][1] * matrix->element[1][2] - matrix->element[0][2] * matrix->element[1][1]) / det;
    inverseMatrix.element[1][0] = -(matrix->element[1][0] * matrix->element[2][2] - matrix->element[1][2] * matrix->element[2][0]) / det;
    inverseMatrix.element[1][1] = (matrix->element[0][0] * matrix->element[2][2] - matrix->element[0][2] * matrix->element[2][0]) / det;
    inverseMatrix.element[1][2] = -(matrix->element[0][0] * matrix->element[1][2] - matrix->element[0][2] * matrix->element[1][0]) / det;
    inverseMatrix.element[2][0] = (matrix->element[1][0] * matrix->element[2][1] - matrix->element[1][1] * matrix->element[2][0]) / det;
    inverseMatrix.element[2][1] = -(matrix->element[0][0] * matrix->element[2][1] - matrix->element[0][1] * matrix->element[2][0]) / det;
    inverseMatrix.element[2][2] = (matrix->element[0][0] * matrix->element[1][1] - matrix->element[0][1] * matrix->element[1][0]) / det;

    return inverseMatrix;
}




#endif // MATRIX_H