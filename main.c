#include <stdio.h>
#include "Matrix.h"


int main()
{
    float mat[] = {4.0, 7.0, 2.0, 
                    6.0, 5.0, 2.0, 
                    4.0, 3.0, 3.0};

    CREATE_MATRIX_ONSTACK(3, 3, A, NULL);
    zerosMatrix(&A);
    printMatrix(A);
    struct easyMatrix A_inv;
    invMatrix(&A,&A);
    printMatrix(A) ;
    return 0;
}