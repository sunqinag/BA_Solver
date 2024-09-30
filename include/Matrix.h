#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int cols;
    int rows;
    float element[3][3];
} Matrix3f;

typedef struct
{
    int cols;
    int rows;
    float element[3];
} Vector3f;


void printMatrix(Matrix3f* matrix);

void printVector(Vector3f* matrix);


Vector3f* ZeroVector3f();

Matrix3f* ZeroMatrix3f();

Matrix3f* CreateMatrix3f(float data[3][3]);

Vector3f* CreateVector3f(float data[3]);

float determinant(Matrix3f *matrix);

Matrix3f* inverse(Matrix3f *matrix);

Vector3f* Vector3fAddVector3f(Vector3f *vector1,Vector3f *vector2);

Vector3f* SubtractVector3f(Vector3f *vector1,Vector3f *vector2);

Vector3f* Vector3fTransform(Vector3f *vector);

Matrix3f* Matrix3fMultiplyMatrix3f(Matrix3f *m1, Matrix3f *m2);

Matrix3f* Matrix3fTranspose(Matrix3f *matrix);


#endif // MATRIX_H