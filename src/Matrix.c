#include "Matrix.h"

void printVector(Vector3f matrix)
{
    for (size_t i = 0; i < 3; i++)
    {
        printf("[%f]\n", matrix.element[i]);
    }
}

void printMatrix(Matrix3f matrix)
{
    for (size_t i = 0; i < 3; i++)
    {
        printf("[%f,%f,%f]\n", matrix.element[i][0], matrix.element[i][1], matrix.element[i][2]);
    }
}

Vector3f ZeroVector3f()
{
    Vector3f vector3f;
    vector3f.cols = 1;
    vector3f.rows = 3;
    for (size_t i = 0; i < 3; i++)
    {
        vector3f.element[i] = 0.0;
    }
    return vector3f;
}

Matrix3f ZeroMatrix3f()
{
    Matrix3f matrix;
    matrix.cols = 3;
    matrix.rows = 3;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            matrix.element[i][j] = 0.0;
        }
    }
    return matrix;
}
Matrix3f CreateMatrix3f(float data[3][3])
{
    Matrix3f matrix;
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

Vector3f CreateVector3f(float data[3])
{
    Vector3f Vector3f;
    Vector3f.rows = 3;
    Vector3f.cols = 1;
    for (size_t i = 0; i < 3; i++)
    {
        Vector3f.element[i] = data[i];
    }
    return Vector3f;
}

float determinant(Matrix3f *matrix)
{
    return matrix->element[0][0] * (matrix->element[1][1] * matrix->element[2][2] - matrix->element[1][2] * matrix->element[2][1]) - matrix->element[0][1] * (matrix->element[1][0] * matrix->element[2][2] - matrix->element[1][2] * matrix->element[2][0]) + matrix->element[0][2] * (matrix->element[1][0] * matrix->element[2][1] - matrix->element[1][1] * matrix->element[2][0]);
}

Matrix3f inverse(Matrix3f *matrix)
{
    Matrix3f inverseMatrix;
    float det = determinant(matrix);

    if (det == 0)
    {
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

Vector3f Vector3fAddVector3f(Vector3f *vector1, Vector3f *vector2)
{
    Vector3f vector = *vector1;
    for (size_t i = 0; i < 3; i++)
    {
        vector.element[i] = vector1->element[i] + vector2->element[i];
    }
    return vector;
}

Vector3f SubtractVector3f(Vector3f *vector1, Vector3f *vector2)
{
    Vector3f vector = *vector1;
    for (size_t i = 0; i < 3; i++)
    {
        vector.element[i] = vector1->element[i] - vector2->element[i];
    }
    return vector;
}

Vector3f Vector3fTransform(Vector3f *vector)
{
    vector->cols = 3;
    vector->rows = 1;
    return *vector;
}

Matrix3f Matrix3fMultiplyMatrix3f(Matrix3f *m1, Matrix3f *m2)
{
    Matrix3f result = ZeroMatrix3f();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result.element[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                result.element[i][j] += m1->element[i][k] * m2->element[k][j];
            }
        }
    }
    return result;
}

// 矩阵转置
Matrix3f Matrix3fTranspose(Matrix3f *matrix)
{
    Matrix3f transposedMatrix = ZeroMatrix3f();
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            transposedMatrix.element[j][i] = matrix->element[i][j];
        }
    }
    return transposedMatrix;
}