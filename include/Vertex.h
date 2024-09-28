#ifndef VERTEX_H
#define VERTEX_H

#include "Matrix.h"

void printMatrix(struct easyMatrix* mat);

typedef struct
{
    int id;
    int dimension;
    int local_dimension;
    struct easyMatrix parameters_;        // 实际储存的变量值
    struct easyMatrix parameters_backup_; // 备份参数，用于回滚
} Vertex3d;

void InitVertex3d(Vertex3d *vertex, int local_dimension);

void SetVertex3d(Vertex3d *vertex, float params[]);

// 备份和回滚参数，用于丢弃一些迭代过程中不好的估计
void BackUpParameters(Vertex3d *vertex);
void RollBackParameters(Vertex3d *vertex);

void Plus(Vertex3d *vertex, struct easyMatrix* delta);


#endif // VERTEX_H