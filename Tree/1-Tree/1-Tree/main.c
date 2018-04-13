//
//  main.c
//  1-Tree
//
//  Created by FlyElephant on 2018/4/13.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include <stdio.h>

typedef struct BTNode {
    char data;
    struct BTNode *leftNode;
    struct BTNode *rightNode;
} BTNode;

void preOrder(BTNode *root) {
    if (root) {
        printf("%c\t",root->data);
        preOrder(root->leftNode);
        preOrder(root->rightNode);
    }
}

void inOrder(BTNode *root) {
    if (root) {
        inOrder(root->leftNode);
        printf("%c\t",root->data);
        inOrder(root->rightNode);
    }
}

void postOrder(BTNode *root) {
    if (root) {
        postOrder(root->leftNode);
        postOrder(root->rightNode);
        printf("%c\t",root->data);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    BTNode root = {'A',NULL,NULL};
    BTNode bNode = {'B',NULL,NULL};
    BTNode cNode = {'C',NULL,NULL};
    BTNode dNode = {'D',NULL,NULL};
    BTNode eNode = {'E',NULL,NULL};
    BTNode fNode = {'F',NULL,NULL};
    root.leftNode = &bNode;
    root.rightNode = &cNode;
    bNode.leftNode = &dNode;
    cNode.leftNode = &eNode;
    cNode.rightNode = &fNode;
    printf("先序遍历结果:\n");
    preOrder(&root);
    printf("\n");
    printf("中序遍历结果:\n");
    inOrder(&root);
    printf("\n");
    printf("后序遍历结果:\n");
    postOrder(&root);
    printf("\n");
    return 0;
}
