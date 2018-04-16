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

int getDepth(BTNode *root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftDepth = getDepth(root->leftNode);
        int rightDepth = getDepth(root->rightNode);
        return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
    }
}

BTNode *search(BTNode *root,char key) {
    if (root != NULL) {
        if (root->data == key) {
            return root;
        } else {
            BTNode *res = search(root->leftNode, key);
            if (res != NULL) {
                return res;
            } else {
                return search(root->rightNode, key);
            }
        }
    }
    return NULL;
}

void level(BTNode *root, int maxSize) { // 数组实现循环队列功能，需要预留一个空间，不然无法进行队满和队空的判断
    int front = 0;
    int rear = 0;
    BTNode *queue[maxSize];
    if (root != NULL) {
        queue[rear] = root; // 初始元素入队列
        rear = (rear + 1) % maxSize;
        while (front != rear) {
            BTNode *node = queue[front];
            front = (front + 1) % maxSize;
            printf("%c\t",node->data);
            if (node->leftNode != NULL) {
                queue[rear] = node->leftNode;
                rear = (rear + 1) % maxSize;
            }
            if (node->rightNode != NULL) {
                queue[rear] = node->rightNode;
                rear = (rear + 1) % maxSize;
            }
        }
    }
    printf("\n");
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
    level(&root, 7);
    int treeDepth = getDepth(&root);
    printf("tree depth:%d\n",treeDepth);
    BTNode *searchRes = search(&root, 'E');
    if (searchRes != NULL) {
        printf("exist node value:%c\n",searchRes->data);
    }
    return 0;
}
