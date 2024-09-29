#include <stdio.h>
#include "Matrix.h"
#include "Vertex.h"

int main()
{

    printf("========  test vertex ==============\n");

    printf("=========== vertex ============\n");
    Vertex3f vertex3f;
    InitVertex3f(&vertex3f, -1);
    printf("id: %d\n", vertex3f.id);
    printf("dimension: %d\n", vertex3f.dimension);
    printf("local_dimension: %d\n", vertex3f.local_dimension);
    printf("parameters_\n");
    printVector(vertex3f.parameters_);

    float param2[3] = {1.1, 2.1, 3.1};
    SetVertex3f(&vertex3f, param2);
    printf("set parameters\n");
    printVector(vertex3f.parameters_);

    // printf("test\n");
    // Plus(&vertex3d_2,&param2);
    return 0;
}
