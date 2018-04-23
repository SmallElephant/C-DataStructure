//
//  main.c
//  1-Tree
//
//  Created by FlyElephant on 2018/4/13.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"
#include "Practice.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    testTreeMethod();
//    testThreadMethod();
//    testPath();
//    A    B    E    D    C    F    G
//    E    D    B    F    G    C    A
    BTNode root = {'A',NULL,NULL};
    BTNode bNode = {'B',NULL,NULL};
    BTNode cNode = {'C',NULL,NULL};
    BTNode dNode = {'D',NULL,NULL};
    BTNode eNode = {'E',NULL,NULL};
    BTNode fNode = {'F',NULL,NULL};
    BTNode gNode = {'G',NULL,NULL};
    root.leftNode = &bNode;
    root.rightNode = &cNode;
    bNode.rightNode = &dNode;
    bNode.leftNode = &eNode;
    cNode.leftNode = &fNode;
    cNode.rightNode = &gNode;
    preOrder(&root);
    printf("\n");
    postOrder(&root);
    printf("\n");
    char pre[] = {'A','B','E','D','C','F','G'};
    char post[] = {'\0','\0','\0','\0','\0','\0','\0'};
    changePreToPost(pre, post, 0, 6, 0, 6);
    for (int i = 0; i < 7; i++) {
        printf("%c\t",post[i]);
    }
    printf("\n");
    levelNode(&root, 'D');
    int level = levelNode2(&root, 'D', 1);
    printf("D level is %d\n",level);
    return 0;
}
