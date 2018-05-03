//
//  Floyd.c
//  1-Graph
//
//  Created by FlyElephant on 2018/5/2.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include "Floyd.h"

#define FLOYDINF 9999
#define FLOYDMAX 4

void testFloyd() {
    VertexType aVertex = {0,'A'};
    int max = FLOYDINF;
    MGraph graph = {4,12,{aVertex},{{0,5,max,7},{max,0,4,2},{3,3,0,2},{max,max,1,0}}};
    floyd(graph);
}

void printFloydPath(int (*path)[FLOYDMAX], int i, int j,int max) {
    if (path[i][j] == -1) {
        printf("%d--->%d之间没有中间节点\n",i,j);
    } else {
        int stack[max];
        // i k j
        int start = i;
        int index = 0;
        stack[index++] = i;
        while (path[start][j] != -1) {
            stack[index++] = path[start][j];
            start = path[start][j];
        }
        stack[index] = j;
        for (int j = 0; j <= index; j++) {
            printf("%d-->",stack[j]);
        }
        printf("\n");
    }
}

void floyd(MGraph graph) {
    int maxSize = graph.n;
    int dist[maxSize][maxSize];
    int path[maxSize][maxSize];
    for (int i = 0; i < maxSize; i++) {
        for (int j = 0; j < maxSize; j++) {
            dist[i][j] = graph.edges[i][j]; //顶点i到顶点j之间的距离是i到j之间的权值
            path[i][j] = -1; // 顶点i到顶点j最短路径是不经过其他任何顶点
        }
    }
    //计算最短路径
    for (int k = 0; k < maxSize; k++) {
        for (int i = 0; i < maxSize; i++) {
            for (int j = 0; j < maxSize; j++) {
                int newDis = dist[i][k] + dist[k][j]; // i 通过 k 到达j的距离 k是中间媒介
                if (newDis < dist[i][j]) {
                    dist[i][j] = newDis;
                    path[i][j] = k;
                }
            }
        }
    }
    
    printf("floyd distance:\n");
    for (int i = 0; i < maxSize; i++) {
        for (int j = 0; j < maxSize; j++) {
            printf("%d\t",dist[i][j]);
        }
        printf("\n");
    }
    printf("floyd path:\n");
    for (int i = 0; i < maxSize; i++) {
        for (int j = 0; j < maxSize; j++) {
            printf("%d\t",path[i][j]);
        }
        printf("\n");
    }
    printFloydPath(path, 1, 0, maxSize * maxSize);
}
