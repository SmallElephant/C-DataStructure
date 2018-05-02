//
//  GraphStruct.h
//  1-Graph
//
//  Created by FlyElephant on 2018/4/24.
//  Copyright © 2018年 rrd. All rights reserved.
//

#ifndef GraphStruct_h
#define GraphStruct_h

#include <stdio.h>

#define MaxSize 10

//邻接表（Adjacency List）

typedef struct ArcNode {
    int adjvex; // 与顶点链接的节点的编号
    struct ArcNode *nextarc; // 与顶点链接的下一个节点的指针
    int info;// 节点的其他信息，如权重
} ArcNode;

typedef struct VNode {
    char data; // 顶点的定义
    ArcNode *firstarc; //顶点的指针
} VNode;

typedef struct AGraph {
    int n; // 整个图的节点总数
    int e; // 边数
    VNode adjlist[MaxSize]; // 顶点数组
} AGraph;

typedef struct VertexType {
    int no;
    char info;
} VertexType;

typedef struct MGraph {
    int n; // 顶点数
    int e; // 边数
    VertexType vertex[MaxSize]; // 存储每个顶点的值
    int edges[MaxSize][MaxSize]; // 存储顶点与顶点之间的关系
} MGraph;

typedef struct MEdge {
    int a;
    int b;
    int w;
} MEdge;

#endif /* GraphStruct_h */
