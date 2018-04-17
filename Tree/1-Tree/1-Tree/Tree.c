//
//  Tree.c
//  1-Tree
//
//  Created by FlyElephant on 2018/4/17.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include "Tree.h"

void testTreeMethod() {
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
    int treeWidth = getBinaryTreeWidth(&root, 7);
    printf("当前二叉树的宽度是%d\n",treeWidth);
    int treeDepth = getDepth(&root);
    printf("tree depth:%d\n",treeDepth);
    BTNode *searchRes = search(&root, 'E');
    if (searchRes != NULL) {
        printf("exist node value:%c\n",searchRes->data);
    }
}

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

int getBinaryTreeWidth(BTNode *root, int maxSize) {
    if (root != NULL) {
        LevelNode queue[maxSize];
        int front = 0;
        int rear = 0;
        int max = 0;
        int level = 0;
        queue[rear].node = root;
        queue[rear].level = 1;
        rear++;
        while (front != rear) {
            BTNode *node = queue[front].node;
            level = queue[front].level;
            front++;
            if (node->leftNode != NULL) {
                queue[rear].node = node->leftNode;
                queue[rear].level = level + 1;
                rear++;
            }
            if (node->rightNode != NULL) {
                queue[rear].node = node->rightNode;
                queue[rear].level = level + 1;
                rear++;
            }
        }
        for (int i = 1; i <= level; i++) {
            int n = 0;
            for (int j = 0; j < maxSize; j++) {
                if (queue[j].level == i) {
                    n++;
                }
            }
            if (n > max) {
                max = n;
            }
        }
        return max;
    } else {
        return 0;
    }
}

void preOrderNonRecursive(BTNode *root,int maxSize) {
    if (root != NULL) {
        BTNode *list[maxSize];
        int top = -1;
        list[++top] = root; // top指向栈顶元素
        while (top >= 0) {
            BTNode *node = list[top--]; // 出站的时候先取值
            printf("%c\t",node->data);
            if (node->rightNode != NULL) { // 先进入右孩子，因为会先序遍历会先输出左孩子
                list[++top] = node->rightNode;
            }
            if (node->leftNode != NULL) {
                list[++top] = node->leftNode; // 入栈的时候先更新栈顶元素的位置
            }
        }
        printf("\n");
    }
}

void inOrderNonRecursive(BTNode *root, int maxSize) {
    if (root != NULL) {
        BTNode *list[maxSize];
        int top = -1; // top指向栈顶也就是最高的元素
        BTNode *node = root;
        while (top >= 0 || node != NULL) {
            while (node != NULL) {
                list[++top] = node;
                node = node->leftNode;
            }
            if (top >= 0) {
                node = list[top--];
                printf("%c\t",node->data);
                node = node->rightNode;
            }
        }
        printf("\n");
    }
}




