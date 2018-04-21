//
//  Practice.c
//  1-Tree
//
//  Created by FlyElephant on 2018/4/21.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include "Practice.h"

BTNode *createBTree(char pre[],char in[], int preLeft, int preRight, int inLeft, int inRight) {
    if (preLeft > preRight) {
        return NULL;
    }
    BTNode *s = (BTNode *)malloc(sizeof(BTNode));
    s->leftNode = NULL;
    s->rightNode = NULL;
    char root = pre[preLeft];
    int i;
    for (i = inLeft; i <= inRight; i++) {
        if (in[i] == root) {
            break;
        }
    }
    s->data = in[i];
    s->leftNode = createBTree(pre, in, preLeft + 1, preLeft + i - inLeft, inLeft, i - 1);
    s->rightNode = createBTree(pre, in, preLeft + i - inLeft + 1, preRight, i + 1, inRight);
    return s;
}

BTNode *createBTTreePost(char post[], char in[], int postLeft, int postRight, int inLeft, int inRight) {
    if (postLeft > postRight) {
        return NULL;
    }
    BTNode *s = (BTNode *)malloc(sizeof(BTNode));
    s->leftNode = NULL;
    s->rightNode = NULL;
    char root = post[postRight];
    int i;
    for (i = inLeft; i <= inRight; i++) {
        if (in[i] == root) {
            break;
        }
    }
    s->data = root;
    // D B E A F C in
    // D E B F C A post
    s->leftNode = createBTTreePost(post, in, postLeft, postLeft + i - inLeft - 1, inLeft, i - 1);
    s->rightNode = createBTTreePost(post, in, postLeft + i - inLeft, postRight - 1, i + 1, inRight);
    return s;
}

int countNode(BTNode *node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftCount = countNode(node->leftNode);
        int rightCount = countNode(node->rightNode);
        return leftCount + rightCount + 1;
    }
}

int leafNodeCount(BTNode *node) {
    if (node == NULL) {
        return 0;
    } else if (node->leftNode == NULL && node->rightNode == NULL) {
        return 1;
    } else {
        int leftCount = leafNodeCount(node->leftNode);
        int rightCount = leafNodeCount(node->rightNode);
        return leftCount + rightCount;
    }
}

BTNode *linkHead = NULL;
BTNode *linkTail = NULL;

void linkLeafNode(BTNode *node) {
    if (node == NULL) {
        return;
    }
    if (node->leftNode == NULL && node->rightNode == NULL) {
        if (linkHead == NULL) {
            linkHead = node;
            linkTail = node;
        } else {
            linkTail->rightNode = node;
            linkTail = node;
        }
    }
    linkLeafNode(node->leftNode);
    linkLeafNode(node->rightNode);
}

void printLeafNodeLink() {
    if (linkHead != NULL && linkTail != NULL) {
        printf("link head value:%c---link tail value:%c\n",linkHead->data,linkTail->data);
    }
}

void updateParentTree(BTParentNode *cur, BTParentNode *par) {
    if (cur == NULL) {
        return;
    }
    cur->parentNode = par;
    par = cur;
    updateParentTree(cur->leftNode, par);
    updateParentTree(cur->rightNode, par);
}

void printParentNodePath(BTParentNode *node) {
    while (node != NULL) {
        printf("%c->",node->data);
        node = node->parentNode;
    }
    printf("\n");
}

void printParentAllPath(BTParentNode *root) {
    if (root != NULL) {
        printParentNodePath(root);
        printParentAllPath(root->leftNode);
        printParentAllPath(root->rightNode);
    }
}


