#include "Vertex.h"

unsigned long global_vertex_id = 0;


void InitVertex3f(Vertex3f *vertex, int local_dimension)
{

    Vector3f vector3f = ZeroVector3f();
    vertex->parameters_ = vector3f;
    printVector(vertex->parameters_);
    vertex->dimension = 3;
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

void SetVertex3f(Vertex3f *vertex, float params[])
{
    
    vertex->parameters_.element[0] = params[0];
    vertex->parameters_.element[1] = params[1];
    vertex->parameters_.element[2] = params[2];
    // copyMatrix(&A,&vertex->parameters_);
    printVector(vertex->parameters_);
}

void BackUpParameters(Vertex3f *vertex)
{
    Vector3f tmp_parameters;
    tmp_parameters = vertex->parameters_;
    vertex->parameters_backup_ = tmp_parameters;
}

void RollBackParameters(Vertex3f *vertex)
{
    Vector3f tmp_parameters;
    tmp_parameters = vertex->parameters_backup_;
    vertex->parameters_ = tmp_parameters;
}

// void Plus(Vertex3f *vertex, Vector3f *delta)
// {
//     printf("========= before add ==========\n");
//     printVector(vertex->parameters_);
//     addMatrix(&vertex->parameters_, &delta, &vertex->parameters_);
//     printf("========= after add ==========\n");
//     printVector(vertex->parameters_);
// }