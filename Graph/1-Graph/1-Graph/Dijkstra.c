//
//  Dijkstra.c
//  1-Graph
//
//  Created by FlyElephant on 2018/5/2.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include "Dijkstra.h"

#define DIJKSTRAINF 9999

void testDijkstra() {
    VertexType aVertex = {0,'A'};
    int max = DIJKSTRAINF;
    MGraph graph = {7,12,{aVertex},{{max,4,6,6,max,max,max},{max,max,1,max,7,max,max},{max,max,max,max,6,4,max},{max,max,2,max,max,5,max},{max,max,max,max,max,max,6},{max,max,max,max,1,max,8},{max,max,max,max,max,max,max}}};
    dijkstra(graph, 0);
}

void printData(int data[],int v) {
    for (int i = 0; i < v; i++) {
        printf("%d\t",data[i]);
    }
    printf("\n");
}

void printPath(int path[],int max,int destination) {
    int stack[max];
    int i = 0;
    int index = destination;
    while (path[index] != -1) {
        stack[i++] = index;
        index = path[index];
    }
    stack[i] = index;
    for (int k = i; k >= 0; k--) {
        printf("%d--->",stack[k]);
    }
    printf("\n");
}

void dijkstra(MGraph graph,int v) {
    int maxsize = graph.n;
    int dist[maxsize]; // save v to other node distance
    int path[maxsize]; // save v to other node path
    int set[maxsize]; // whether node is added
    for (int i = 0; i < maxsize; i++) {
        dist[i] = graph.edges[v][i];
        set[i] = 0; //
        if (graph.edges[v][i] < DIJKSTRAINF) { // 如果顶点v到顶点i之间的距离小于INF
            path[i] = v;
        } else {
            path[i] = -1; // -1表示顶点v与i之间没有连通的边
        }
    }
    set[v] = 1; // 1为集合S 0为集合U
    path[v] = -1;
    for (int i = 0; i < maxsize - 1; i++) {
        int min = DIJKSTRAINF;
        int m = 0; // 距离已加入集合的U中最近的顶点
        for (int j = 0; j < maxsize; j++) {
            if (set[j] == 0 && dist[j] < min) {
                min = dist[j];
                m = j;
            }
        }
        set[m] = 1;
        // 以新加入的顶点作为媒介，判断到j的距离是否比原来小，如果更小则更新距离
        for (int k = 0; k < maxsize; k++) {
            int newDis = dist[m] + graph.edges[m][k];
            if (set[k] == 0 && newDis < dist[k]) {
                dist[k] = newDis;
                path[k] = m; // 修改k的上一层结点为m
            }
        }
    }
    printPath(path, maxsize, 6);
}
