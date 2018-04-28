//
//  Graph.c
//  1-Graph
//
//  Created by FlyElephant on 2018/4/24.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include "Graph.h"

#define INF 10000
void prime(MGraph *graph, int v) { // U 已选定最小值集合 V-U待选定集合
    // i表示V-U中结点 cloest[i] 表示距离U集合中路径最短的结点编号 lowcost[i] 表示V-U中距离U集合中距离最短的节点的权重
    // lowcost[i] = 0 表示已经加入U中
    
    // 1 初始化U
    int vertexs = graph->n;
    int visit[vertexs]; // 是否被访问
    int lowcost[vertexs];
    for (int i = 0; i < vertexs; i++) {
        visit[i] = 0; // 所有结点默认未加入
        lowcost[i] = graph->edges[v][i]; // 其他结点到结点v的最短路径
    }
    visit[v] = 1; // 结点v被访问，即加入选定集合
    // 2.遍历其他的n-1个结点
    int min;
    int k = 0;
    for (int i = 0; i < vertexs - 1; i++) {
        min = INF;
        for (int j = 0; j < vertexs; j++) { // 在V-U中找出距离U中最近的结点
            if (visit[j] == 0 && lowcost[j] < min) { //  未被访问
                min = lowcost[j];
                k = j;
            }
        }
        visit[k] = 1; // k加入U中,k被访问过
        printf("FlyElephant:%d加入节点的权重为:%d\n",k,min);
        //        假设第一次：lowcost[2]代表与1相连的点的权值，现在加入了k点。则比较k点与2点的边edges[k][2]和lowcost[2]的大小，若lowcost[2]大，则lowcost[2] = edges[k][2]。（关键步骤：实质就是每在最小生成树集合中加入一个点就需要把这个点与集合外的点比较，不断的寻找两个集合之间最小的边）
        for (int j = 0; j < vertexs; j++) {
            if (visit[j] == 0 && graph->edges[k][j] < lowcost[j]) {
                lowcost[j] = graph->edges[k][j];
            }
        }
    }
}

void primeTest() { // 最小代价树
    //      0
    //1     2   3
    //      4
    VertexType aVertex = {0,'A'};
    VertexType bVertex = {1,'B'};
    VertexType cVertex = {2,'B'};
    VertexType dVertex = {3,'B'};
    VertexType eVertex = {4,'B'};
    int test = INF;
    MGraph graph = {5,8,{aVertex,bVertex,cVertex,dVertex,eVertex},{{test,5,1,2,test},{5,test,3,test,4},{1,3,test,6,2},{2,test,6,test,3},{0,4,2,3,0}}};
    prime(&graph, 0);
}

void printEdges(MEdge edges[],int n) {
    for (int i = 0; i < n; i++) {
        MEdge edge = edges[i];
        printf("%d---%d weight is:%d\n",edge.a,edge.b,edge.w);
    }
}

void sort(MEdge edges[], int n) {
    for (int i = 0; i < n; i++) {
        int min = edges[i].w;
        int index = i;
        for (int j = i; j < n; j++) {
            if (edges[j].w < min) {
                min = edges[j].w;
                index = j;
            }
        }
        MEdge temp = edges[i];
        edges[i] = edges[index];
        edges[index] = temp;
    }
}

int getKruskalRoot(int vertexs[], int a) { // 并查集，a表示当前节点，vertex[a]存储a的父节点
    while (a != vertexs[a]) {
        a = vertexs[a];
    }
    return a;
}

void kruskal(MGraph graph,MEdge edges[]) {
    int n = graph.n; // 顶点的数量
    int e = graph.e; // 图中边的数量
    int vertexs[n];
    for (int i = 0; i < n ; i++) { // 初始化并查集，结点的上一层结点指向本身
        vertexs[i] = i;
    }
    sort(edges, e); // 边按照权重进行排序
    for (int i = 0; i < e; i++) { // 枚举所有的边
        MEdge cur = edges[i]; // 当前的边
        int aRoot = getKruskalRoot(vertexs, cur.a);
        int bRoot = getKruskalRoot(vertexs, cur.b);
        if (aRoot != bRoot) { //a,b父节点不一样
            vertexs[aRoot] = bRoot;
            printf("add new edge:%d--->%d weight is:%d\n",cur.a,cur.b,cur.w);
        }
    }
}

void kruskalTest() {
    MEdge edge1 = {0,1,5};
    MEdge edge2 = {0,2,1};
    MEdge edge3 = {0,3,2};
    MEdge edge4 = {1,2,3};
    MEdge edge5 = {1,4,4};
    MEdge edge6 = {2,3,6};
    MEdge edge7 = {2,4,2};
    MEdge edge8 = {3,4,3};
    MEdge edges[8] = {edge1,edge2,edge3,edge4,edge5,edge6,edge7,edge8};
    VertexType aVertex = {0,'A'};
    VertexType bVertex = {1,'B'};
    VertexType cVertex = {2,'B'};
    VertexType dVertex = {3,'B'};
    VertexType eVertex = {4,'B'};
    int test = INF;
    MGraph graph = {5,8,{aVertex,bVertex,cVertex,dVertex,eVertex},{{test,5,1,2,test},{5,test,3,test,4},{1,3,test,6,2},{2,test,6,test,3},{0,4,2,3,0}}};
    kruskal(graph, edges);
}

