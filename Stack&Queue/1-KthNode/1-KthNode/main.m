//
//  main.m
//  1-KthNode
//
//  Created by FlyElephant on 2017/11/20.
//  Copyright © 2017年 FlyElephant. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef struct DataNode {
    int val;
    struct DataNode *next;
} Node;

int main(int argc, const char * argv[]) {
    Node node6 = {6,NULL};
    Node node5 = {5,&node6};
    Node node4 = {4,&node5};
    Node node3 = {3,&node4};
    Node node2 = {2,&node3};
    Node node1 = {1,&node2};
    Node p1 = node1;
    Node p2 = node1;
    int  step = 3;
    for (int i = 0; i < step - 1 ; i++) {
        p2 = *p2.next;
    }
    while (p2.next != NULL) {
        p2 = *p2.next;
        p1= *p1.next;
    }
    printf("倒数k个节点的值:%d\n",p1.val);
    return 0;
}
