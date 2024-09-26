#include <stdio.h>

typedef struct
{
    double data[3][3];
} Matrix3d;

void setValue(double value[3][3], Matrix3d *matrix3d){
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            matrix3d->data[i][j] = value[i][j];
        }
        
    }
    
}
void setZero(Matrix3d *matrix)
{
    matrix->data[0][0] = 0.0;
    matrix->data[0][1] = 0.0;
    matrix->data[0][2] = 0.0;

    matrix->data[1][0] = 0.0;
    matrix->data[1][1] = 0.0;
    matrix->data[1][2] = 0.0;

    matrix->data[2][0] = 0.0;
    matrix->data[2][1] = 0.0;
    matrix->data[2][2] = 0.0;
}

void setIdentity(Matrix3d *matrix)
{
    matrix->data[0][0] = 1.0;
    matrix->data[0][1] = 0.0;
    matrix->data[0][2] = 0.0;

    matrix->data[1][0] = 0.0;
    matrix->data[1][1] = 1.0;
    matrix->data[1][2] = 0.0;

    matrix->data[2][0] = 0.0;
    matrix->data[2][1] = 0.0;
    matrix->data[2][2] = 1.0;
}

void printData(Matrix3d *matrix)
{
    for (size_t i = 0.0; i < 3; i++)
    {
        printf("[%f,%f,%f]\n", matrix->data[i][0], matrix->data[i][1], matrix->data[i][2]);
    }
}
