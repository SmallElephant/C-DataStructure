//
//  main.c
//  1-Graph
//
//  Created by FlyElephant on 2018/4/24.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include <stdio.h>
#include "Graph.h"

#define MaxSize 5

int visit[MaxSize];

void Visit(int v) {
    printf("%d->",v);
}

void DFS(AGraph *graph,int v) {
    visit[v] = 1; // 1表示已访问
    Visit(v);
    ArcNode *p = graph->adjlist[v].firstarc; // 访问结点v的第一条边指向的节点
    while (p != NULL) {
        if (visit[p->adjvex] == 0) {
            DFS(graph, p->adjvex);
        }
        p = p->nextarc;
    }
}

void BFS(AGraph *graph,int v,int visit[MaxSize]) {
    int front = 0;
    int rear = 0;
    int que[MaxSize];
    que[rear] = v; // 先进入队列，在赋值，也可以先更新rear，再赋值
    rear = (rear + 1) % MaxSize;
    Visit(v);
    visit[v] = 1;
    ArcNode *p;
    while (front != rear) {
        int j = que[front]; // 顶点出队列，保持与队列的操作一致，先取值，后更新位置
        front = (front + 1) % MaxSize; // 出队，pushBack
        p = graph->adjlist[j].firstarc;
        while (p != NULL) {
            if (visit[p->adjvex] == 0) { // 节点没有被访问，将所有的孩子都添加进入队列中
                visit[p->adjvex] = 1; // 标记为已访问
                Visit(p->adjvex);
                que[rear] = p->adjvex; // 入队 push
                rear = (rear + 1) % MaxSize;
            }
            p = p->nextarc;
        }
    }
}

int maxDist(AGraph *graph, int v) {
    int que[MaxSize];
    int front = 0;
    int rear = 0;
    que[rear] = v;
    rear = (rear + 1) % MaxSize;
    for (int i = 0; i < graph->n; i++) {
        visit[i] = 0;
    }
    ArcNode *p;
    int j = 0;
    while (front != rear) {
        j = que[front];
        front = (front + 1) % MaxSize;
        p = graph->adjlist[j].firstarc;
        while (p != NULL) {
            int i = p->adjvex;
            if (visit[i] == 0) {
                visit[i] = 1;
                que[rear] = p->adjvex;
                rear = (rear + 1) % MaxSize;
            }
            p = p->nextarc;
        }
    }
    return j;
}

void insertNextArcNode(VNode *vNode, ArcNode *data) {
    ArcNode *p = vNode->firstarc;
    while (p->nextarc != NULL) {
        p = p->nextarc;
    }
    p->nextarc = data;
}

void DFSTest() {
    // insert code here...
    //    printf("Hello, World!\n");
    // A B C D E
    // 0 1 2 3 4
    // A B  C D
    // C D
    // D E
    
    VNode aNode = {'0',NULL};
    VNode bNode = {'1',NULL};
    VNode cNode = {'2',NULL};
    VNode dNode = {'3',NULL};
    VNode eNode = {'4',NULL};
    ArcNode arc1 = {1,NULL,0};
    ArcNode arc2 = {2,NULL,0};
    ArcNode arc3 = {3,NULL,0};
    ArcNode arc4 = {4,NULL,0};
    aNode.firstarc = &arc1;
    cNode.firstarc = &arc3;
    dNode.firstarc = &arc4;
    insertNextArcNode(&aNode, &arc2);
    insertNextArcNode(&aNode, &arc3);
    AGraph graph = {5,5,{aNode,bNode,cNode,dNode,eNode}};
    DFS(&graph, 0);
    printf("\n");
}

void dfsTest() {
    // A B D
    // B C E
    VNode aNode = {'0',NULL};
    VNode bNode = {'1',NULL};
    VNode cNode = {'2',NULL};
    VNode dNode = {'3',NULL};
    VNode eNode = {'4',NULL};
    ArcNode arc1 = {1,NULL,0}; // B
    ArcNode arc2 = {2,NULL,0}; // C
    ArcNode arc3 = {3,NULL,0}; // D
    ArcNode arc4 = {4,NULL,0}; // E
    aNode.firstarc = &arc1;
    insertNextArcNode(&aNode, &arc3);
    bNode.firstarc = &arc2;
    insertNextArcNode(&aNode, &arc4);
    AGraph graph = {5,5,{aNode,bNode,cNode,dNode,eNode}};
    int bfs[MaxSize] = {0};
    BFS(&graph, 0, bfs);
    printf("\n");
    int distance = maxDist(&graph, 0);
    printf("max far distance:%d\n",distance);
}

void DFS2(AGraph *graph,int v,int *vn,int *en) {
    ArcNode *p = graph->adjlist[v].firstarc;
    visit[v] = 1;
    (*vn)++; // 顶点加1
    while (p != NULL) {
        (*en)++; // 边数加1
        int i = p->adjvex;
        if (visit[i] == 0) {
            DFS2(graph, i, vn, en);
        }
        p = p->nextarc;
    }
}

int GisTree(AGraph *graph) {
    int vn = 0;
    int en = 0;
    int i;
    for (i = 0; i < graph->n; i++) {
        visit[i] = 0;
    }
    DFS2(graph, 0, &vn, &en);
    if (vn == graph->n && graph->n - 1 == en / 2) { // 访问过程中的顶点数与图中的顶点数相等，且边数等于顶点数减1
        return 1;
    } else {
        return 0;
    }
}
// 判断图是否是一棵树，如果是返回1，如果不是返回0
void validTree() {
    //A
    //B C D
    //D
    //A
    // A 0 B 1 C 2 D 3
    // 顶点 vertex  边 edge
    VNode aNode = {'0',NULL};
    VNode bNode = {'1',NULL};
    VNode cNode = {'2',NULL};
    VNode dNode = {'3',NULL};
    ArcNode arc1 = {1,NULL,0};
    ArcNode arc2 = {2,NULL,0};
    ArcNode arc3 = {3,NULL,0};
    aNode.firstarc = &arc1;
    insertNextArcNode(&aNode, &arc2);
    insertNextArcNode(&aNode, &arc3);
    bNode.firstarc = &arc3;
    dNode.firstarc = &arc1;
    AGraph graph = {4,5,{aNode,bNode,cNode,dNode}};
    int res = GisTree(&graph);
    if (res) {
        printf("graph is a tree\n");
    } else {
        printf("graph is not a valid tree\n");
    }
}

// 图采用邻接表存储，设计一个算法，判断顶点i与顶点j之间是否存在路径

int DFSTravse(AGraph *graph,int i,int j) {
    int k;
    for (k = 0; k < graph->n; k++) {
        visit[k] = 0;
    }
    DFS(graph, i);
    if (visit[j] == 1) {
        return 1;
    } else {
        return 0;
    }
}

void isDFSTravse() {
    //A
    //B C D
    //D
    //A
    // A 0 B 1 C 2 D 3
    // 顶点 vertex  边 edge
    VNode aNode = {'0',NULL};
    VNode bNode = {'1',NULL};
    VNode cNode = {'2',NULL};
    VNode dNode = {'3',NULL};
    ArcNode arc1 = {1,NULL,0};
    ArcNode arc2 = {2,NULL,0};
    ArcNode arc3 = {3,NULL,0};
    aNode.firstarc = &arc1;
    insertNextArcNode(&aNode, &arc2);
    insertNextArcNode(&aNode, &arc3);
    bNode.firstarc = &arc3;
    dNode.firstarc = &arc1;
    AGraph graph = {4,5,{aNode,bNode,cNode,dNode}};
    int res = DFSTravse(&graph, 0, 3);
    if (res) {
        printf("A and D is exist path\n");
    } else {
        printf("A and D is not exist path\n");
    }
}
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

int main(int argc, const char * argv[]) {
    validTree();
    isDFSTravse();
    primeTest();
    return 0;
}
