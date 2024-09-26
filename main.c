#include <stdio.h>
#include "Matrix3d.h"



int main(int argc, char *argv[]){
    printf("Hello, from BA_Solver!\n");
    Matrix3d value;
    double data[3][3] = {
        {1.0,2.0,3.0},
        {4.0,5.0,6.0},
        {7.0,8.0,9.0}
    };
    setValue(data,&value);
    printData(&value);
    return 0;
}
