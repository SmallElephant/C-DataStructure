//
//  Practice.c
//  1-Graph
//
//  Created by FlyElephant on 2018/5/4.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include "Practice.h"

void appendArcNode(VNode *vNode, ArcNode *data) {
    ArcNode *p = vNode->firstarc;
    while (p->nextarc != NULL) {
        p = p->nextarc;
    }
    p->nextarc = data;
}

void testBFSPath() {
    VNode aNode = {'0',NULL};
    VNode bNode = {'1',NULL};
    VNode cNode = {'2',NULL};
    VNode dNode = {'3',NULL};
    VNode eNode = {'4',NULL};
    ArcNode arc1 = {1,NULL,0}; // B
    ArcNode arc2 = {2,NULL,0}; // C
    ArcNode arc3 = {3,NULL,0}; // D
    ArcNode arc4 = {4,NULL,0}; // E
    // 0 1 3 4 A B D
    aNode.firstarc = &arc1;
    appendArcNode(&aNode, &arc3);
    appendArcNode(&aNode, &arc4);
    // 1 2 B C E
    bNode.firstarc = &arc2;
    AGraph graph = {5,5,{aNode,bNode,cNode,dNode,eNode}};
    int res = isBFSPath(&graph, 0, 4);
    if (res) {
        printf("节点之间存在路径\n");
    } else {
        printf("节点之间不存在路径\n");
    }
}


// 邻接表判断vi vj之间是否存在路径
int isBFSPath(AGraph *graph,int vi,int vj) {
    int maxSize = graph->n;
    int visit[maxSize];
    int queue[maxSize];
    for (int i = 0; i < maxSize; i++) {
        visit[i] = 0;
    }
    int front = 0;
    int rear = 0;
    queue[rear] = vi; // 将vi节点加入队列中
    rear = (rear + 1) % maxSize;
    visit[vi] = 1;
    while (front != rear) {
        int cur = queue[front];
        front = (front + 1) % maxSize;
        printf("%d被访问\n",cur);
        if (cur == vj) { // 如果vj已经被加入了队列中，说明两点之间存在路径
            return 1;
        }
        ArcNode *p = graph->adjlist[cur].firstarc;
        while (p != NULL) {
            if (visit[p->adjvex] == 0) { // 判断节点有没有被访问过
                queue[rear] = p->adjvex;
                rear = (rear + 1) % maxSize;
                visit[p->adjvex] = 1;
            }
            p = p->nextarc;
        }
    }
    return 0;
}

int rootVisist[5];
int rootSum;
void testDFSRootPath() {
    // 邻接表VNode表示顶点，ArcNode也表示的是顶点，ArcNode中的adjvex表示在数组中的索引，或者说与VNode的值一致
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
    appendArcNode(&aNode, &arc2);
    appendArcNode(&aNode, &arc3);
    dNode.firstarc = &arc4;
    AGraph graph = {5,4,{aNode,bNode,cNode,dNode,eNode}};
    printAllRootVertex(&graph);
}

void rootDFS(AGraph *graph,int vertex) {
    ArcNode *p = graph->adjlist[vertex].firstarc;
    rootSum++;
    rootVisist[vertex] = 1;
    while (p != NULL) {
        if (rootVisist[p->adjvex] == 0) {
            rootDFS(graph, p->adjvex);
        }
        p = p->nextarc;
    }
}

void printAllRootVertex(AGraph *graph) {
    int vertexs = graph->n;
    for (int i = 0; i < vertexs; i++) {
        rootSum = 0;
        for (int j = 0; j < vertexs; j++) {
            rootVisist[j] = 0;
        }
        rootDFS(graph, i);
        printf("index:%d----sum:%d\n",i,rootSum);
        if (rootSum == vertexs) {
            printf("%d\n",i);
        }
    }
}



