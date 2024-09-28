#include "Vertex.h"

unsigned long global_vertex_id = 0;

void printMatrix(struct easyMatrix* mat)
{
    for (size_t i = 0; i < mat->rows; i++)
    {
        for (size_t j = 0; j < mat->cols; j++)
        {
            printf("%f ", mat->element[i * mat->cols + j]); // 假设 DATA_TYPE 是 double
        }
        printf("\n");
    }
}

void InitVertex3d(Vertex3d *vertex, int local_dimension)
{

    CREATE_MATRIX_ONSTACK(3, 1, A, NULL);
    CREATE_MATRIX_ONSTACK(3, 1, B, NULL);
    // zerosMatrix(&A);
    A.element[0]=1.7;
    A.element[1]=1.7;
    A.element[2]=1.7;
    vertex->parameters_ = B;
    for (int i = 0; i < 3; i++) {
        vertex->parameters_.element[i] = A.element[i];
    }
    printMatrix(&vertex->parameters_);
    vertex->dimension = A.rows;
    if (local_dimension > 0)
    {
        vertex->local_dimension = local_dimension;
    }
    else
    {
        vertex->local_dimension = 3;
    }
    vertex->id = global_vertex_id;
    global_vertex_id++;
}

void SetVertex3d(Vertex3d *vertex, float params[])
{
    CREATE_MATRIX_ONSTACK(3, 1, A, params);
    vertex->parameters_.element[0] = A.element[0];
    vertex->parameters_.element[1] = A.element[1];
    vertex->parameters_.element[2] = A.element[2];
    // copyMatrix(&A,&vertex->parameters_);
    printMatrix(&vertex->parameters_);
}

void BackUpParameters(Vertex3d *vertex)
{
    struct easyMatrix tmp_parameters;
    tmp_parameters = vertex->parameters_;
    vertex->parameters_backup_ = tmp_parameters;
}

void RollBackParameters(Vertex3d *vertex)
{
    struct easyMatrix tmp_parameters;
    tmp_parameters = vertex->parameters_backup_;
    vertex->parameters_ = tmp_parameters;
}

void Plus(Vertex3d *vertex, struct easyMatrix *delta)
{
    printf("========= before add ==========\n");
    printMatrix(&vertex->parameters_);
    addMatrix(&vertex->parameters_, &delta, &vertex->parameters_);
    printf("========= after add ==========\n");
    printMatrix(&vertex->parameters_);
}