#include <stdio.h>
#include "Matrix.h"

void printMatrix(struct easyMatrix mat) {
    for (size_t i = 0; i < mat.rows; i++) {
        for (size_t j = 0; j < mat.cols; j++) {
            printf("%f ", mat.element[i * mat.cols + j]); // 假设 DATA_TYPE 是 double
        }
        printf("\n");
    }
}

int main()
{
    float mat[] = {4.0, 7.0, 2.0, 
                    6.0, 5.0, 2.0, 
                    4.0, 3.0, 3.0};

    CREATE_MATRIX_ONSTACK(3, 3, A, mat);
    printMatrix(A);
    struct easyMatrix A_inv;
    invMatrix(&A,&A);
    printMatrix(A) ;
    return 0;
}