//
//  Topology.c
//  1-Graph
//
//  Created by FlyElephant on 2018/5/3.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include "Topology.h"

void appendNextArcNode(VNode *vNode, ArcNode *data) {
    ArcNode *p = vNode->firstarc;
    while (p->nextarc != NULL) {
        p = p->nextarc;
    }
    p->nextarc = data;
}

void testTopology() {
    // 0  1 2 3
    // 1  2 4
    // 2  4 5
    // 3  5
    // 4  6
    // 5  4 6
    // 6
    VNode aNode = {'0',NULL,0};
    VNode bNode = {'1',NULL,1};
    VNode cNode = {'2',NULL,2};
    VNode dNode = {'3',NULL,1};
    VNode eNode = {'4',NULL,3};
    VNode fNode = {'5',NULL,2};
    VNode gNode = {'6',NULL,2};
    ArcNode arc1 = {1,NULL,0};
    ArcNode arc2 = {2,NULL,0};
    ArcNode arc3 = {3,NULL,0};
    ArcNode arc4 = {4,NULL,0};
    ArcNode arc5 = {5,NULL,0};
    ArcNode arc6 = {6,NULL,0};
    aNode.firstarc = &arc1;
    appendNextArcNode(&aNode, &arc2);
    appendNextArcNode(&aNode, &arc3);
    ArcNode arc2b = {2,NULL,0};
    bNode.firstarc = &arc2b;
    appendNextArcNode(&bNode, &arc4);
    ArcNode arc4c = {4,NULL,0};
    cNode.firstarc = &arc4c;
    appendNextArcNode(&cNode, &arc5);
    ArcNode arc5d = {5,NULL,0};
    dNode.firstarc = &arc5d;
    eNode.firstarc = &arc6;
    ArcNode arc4f = {4,NULL,0};
    fNode.firstarc = &arc4f;
    appendNextArcNode(&fNode, &arc6);
    AGraph graph = {7,11,{aNode,bNode,cNode,dNode,eNode,fNode,gNode}};
    topoSort(graph);
}

//以邻接表的形式进行拓扑排序
// 基本算法思想 首先将入度是零的点加入栈中，然后将其关联的点的入度减去1，继续将入度是零的点加入栈中，直至栈不为空
void topoSort(AGraph graph) {
    int vertexs = graph.n;
    int top = -1;
    int stack[vertexs];
    for (int i = 0; i < vertexs; i++) {
        if (graph.adjlist[i].count == 0) { // no other vertext point this
            stack[++top] = i;
        }
    }
    printf("topology sort result:");
    int count = 0;
    while (top != -1) {
        int val = stack[top--];
        printf("%d\t",val);
        count++;
        ArcNode *p = graph.adjlist[val].firstarc;
        while (p != NULL) {
            int adjvex = p->adjvex;// 与顶点相邻的编号
            graph.adjlist[adjvex].count--;
            p = p->nextarc;
            if (graph.adjlist[adjvex].count == 0) {
                stack[++top] = adjvex;
            }
        }
    }
    printf("\n");
    if (count == graph.n) {
        printf("all node is print topology is success\n");
    } else {
        printf("topology is failed\n");
    }
}
