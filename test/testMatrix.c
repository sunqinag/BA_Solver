
#include "Matrix.h"

int main()
{
    // float data[3][3] = {{55, 25, 15},
    //                     {30, 44, 2},
    //                     {11, 45, 77}};
    // Matrix3f matrix = CreateMatrix3f(data);

    // printMatrix(matrix);

    // float deterine = determinant(matrix);
    // printf("determine %f",deterine);

    // Matrix3f inv_matrix = inverse(matrix);
    // printf("inv matrix\n");
    // printMatrix(inv_matrix);

    float data[3] ={1,2,3};
    Vector3f* vector = CreateVector3f(data);
    printVector(vector);

    Vector3f *add_result = Vector3fAddVector3f(&vector,&vector);
    printf("add vector, cols %d, rows %d\n",vector->cols,vector->rows);
    printVector(add_result);

    Vector3f *vector_T = Vector3fTransform(&vector);
    printf("transform vector, cols %d, rows %d\n",vector_T->cols,vector_T->rows);

    float data1[3][3] = {{55, 25, 15},
                        {30, 44, 2},
                        {11, 45, 77}};
    Matrix3f *matrix = CreateMatrix3f(data1);

    printf("========== Matrix3fMultiplyMatrix3f =============\n");
    Matrix3f *multiply_matrix = Matrix3fMultiplyMatrix3f(&matrix,&matrix);
    printMatrix(matrix);

    printf("========== transpose matrix =============\n");
    Matrix3f *matrix_T = Matrix3fTranspose(&matrix);
    printMatrix(matrix_T);
}
