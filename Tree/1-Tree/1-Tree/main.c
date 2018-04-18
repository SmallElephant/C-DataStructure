//
//  main.c
//  1-Tree
//
//  Created by FlyElephant on 2018/4/13.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    testTreeMethod();
    // preOrder: A B D C E
    TBTNode root = {'A',NULL,NULL};
    TBTNode bNode = {'B',NULL,NULL};
    TBTNode cNode = {'C',NULL,NULL};
    TBTNode dNode = {'D',NULL,NULL};
    TBTNode eNode = {'E',NULL,NULL};
    root.leftChild = &bNode;
    root.rightChild = &cNode;
    bNode.rightChild = &dNode;
    cNode.leftChild = &eNode;
//    createInThread(&root);
//    TBTNode *first = First(&root);
//    if (first != NULL) {
//        printf("inOrder first node value:%c\n",first->data);
//    }
//    TBTNode *next = Next(&dNode);
//    if (next != NULL) {
//        printf("inorder current node next value:%c\n",next->data);
//    }
//    threadInOrder(&root);
    
//    createPreThread(&root);
//    if (dNode.rightChild != NULL) {
//        printf("dnode right value:%c\n",dNode.rightChild->data);
//    }
//    threadPreOrder(&root);
    
    createPostThread(&root);
    if (dNode.rightChild != NULL) {
        printf("dnode right value:%c\n",dNode.rightChild->data);
    }
    threadPostOrder(&root);
    return 0;
}
