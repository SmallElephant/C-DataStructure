//
//  Graph.h
//  1-Graph
//
//  Created by FlyElephant on 2018/4/24.
//  Copyright © 2018年 rrd. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <stdio.h>
#include "GraphStruct.h"

#endif /* Graph_h */

void prime(MGraph *graph, int v);
void primeTest(void);

// 克鲁斯卡尔算法实现
int getKruskalRoot(int vertexs[], int a);
void kruskal(MGraph graph,MEdge edges[]);
void kruskalTest(void);
