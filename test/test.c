#include <stdio.h>
#include "Matrix.h"
#include "Vertex.h"

int main()
{

    printf("========  test vertex ==============\n");

    // printf("=========== vertex1 ============\n");
    // Vertex3d vertex3d_1;
    // InitVertex3d(&vertex3d_1, -1);
    // float param1[] = {1, 2, 3};
    // SetVertex3d(&vertex3d_1, &param1);
    printf("=========== vertex2 ============\n");
    Vertex3d vertex3d_2;
    InitVertex3d(&vertex3d_2, -1);
    printf("id: %d\n", vertex3d_2.id);
    printf("dimension: %d\n", vertex3d_2.dimension);
    printf("local_dimension: %d\n", vertex3d_2.local_dimension);
    printf("parameters_\n");
    printMatrix(&vertex3d_2.parameters_);

    // float param2[] = {1.1, 2.1, 3.1};
    // SetVertex3d(&vertex3d_2, &param2);
    // printf("set parameters\n");
    // printf("%f",vertex3d_2.parameters_.element[0]);
    // printf("%f",vertex3d_2.parameters_.element[1]);
    // printf("%f",vertex3d_2.parameters_.element[2]);
    // printMatrix(&vertex3d_2->parameters_);

    // printf("test\n");
    // Plus(&vertex3d_2,&param2);
    return 0;
}
