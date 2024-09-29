#ifndef VERTEX_H
#define VERTEX_H

#include "Matrix.h"


typedef struct
{
    int id;
    int dimension;
    int local_dimension;
    Vector3f parameters_;        // 实际储存的变量值
    Vector3f parameters_backup_; // 备份参数，用于回滚
} Vertex3f;

void InitVertex3f(Vertex3f *vertex, int local_dimension);

void SetVertex3f(Vertex3f *vertex, float params[3]);

// 备份和回滚参数，用于丢弃一些迭代过程中不好的估计
void BackUpParameters(Vertex3f *vertex);
void RollBackParameters(Vertex3f *vertex);

void Plus(Vertex3f *vertex, Vector3f* delta);


#endif // VERTEX_H