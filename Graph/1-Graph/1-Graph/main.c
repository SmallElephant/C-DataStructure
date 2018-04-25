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

int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
    // A B C D E
    // 0 1 2 3 4
    // A B  C D
    // C D
    // D E

//    VNode aNode = {'0',NULL};
//    VNode bNode = {'1',NULL};
//    VNode cNode = {'2',NULL};
//    VNode dNode = {'3',NULL};
//    VNode eNode = {'4',NULL};
//    ArcNode arc1 = {1,NULL,0};
//    ArcNode arc2 = {2,NULL,0};
//    ArcNode arc3 = {3,NULL,0};
//    ArcNode arc4 = {4,NULL,0};
//    aNode.firstarc = &arc1;
//    cNode.firstarc = &arc3;
//    dNode.firstarc = &arc4;
//    insertNextArcNode(&aNode, &arc2);
//    insertNextArcNode(&aNode, &arc3);
//    AGraph graph = {5,5,{aNode,bNode,cNode,dNode,eNode}};
//    DFS(&graph, 0);
//    printf("\n");
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
    return 0;
}
