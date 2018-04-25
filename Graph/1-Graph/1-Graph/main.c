//
//  main.c
//  1-Graph
//
//  Created by FlyElephant on 2018/4/24.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include <stdio.h>
#include "Graph.h"

int visit[5];

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
    return 0;
}
