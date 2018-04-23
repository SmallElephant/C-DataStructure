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

void testBinaryNonRecursive() {
    BTNode root = {'1',NULL,NULL};
    BTNode bNode = {'2',NULL,NULL};
    BTNode cNode = {'4',NULL,NULL};
    BTNode dNode = {'3',NULL,NULL};
    BTNode eNode = {'5',NULL,NULL};
    root.leftNode = &bNode;
    root.rightNode = &cNode;
    bNode.leftNode = &dNode;
    bNode.rightNode = &eNode;
    preOrderNonRecursive(&root, 6);
    inOrderNonRecursive(&root, 6);
    postOrderNonRecursive(&root, 6);
}

void testThreadMethod() {
//    preOrder: A B D C E
    //    A
    // B      C
    //   D  E
    // inOrder B D A E C
    // postOrder D B E C A
    TBTNode root = {'A',NULL,NULL};
    TBTNode bNode = {'B',NULL,NULL};
    TBTNode cNode = {'C',NULL,NULL};
    TBTNode dNode = {'D',NULL,NULL};
    TBTNode eNode = {'E',NULL,NULL};
    root.leftChild = &bNode;
    root.rightChild = &cNode;
    bNode.rightChild = &dNode;
    cNode.leftChild = &eNode;
    createInThread(&root);
    TBTNode *first = First(&root);
    if (first != NULL) {
        printf("inOrder first node value:%c\n",first->data);
    }
    TBTNode *next = Next(&dNode);
    if (next != NULL) {
        printf("inorder current node next value:%c\n",next->data);
    }
    TBTNode *last = InOrderLastNode(&root);
    if (last != NULL) {
        printf("inorder last node value:%c\n",last->data);
    }
    TBTNode *priorNode = InOrderPriorNode(&root);
    if (priorNode != NULL) {
        printf("inorder prior node value:%c\n",priorNode->data);
    }
    TBTNode *preNext = InOrderPreNext(&dNode);
    if (preNext != NULL) {
        printf("inorder node in preorder next value:%c\n",preNext->data);
    }
    threadInOrder(&root);

//    createPreThread(&root);
//    if (dNode.rightChild != NULL) {
//        printf("dnode right value:%c\n",dNode.rightChild->data);
//    }
//    threadPreOrder(&root);
//
//    createPostThread(&root);
//    if (dNode.rightChild != NULL) {
//        printf("dnode right value:%c\n",dNode.rightChild->data);
//    }
//    threadPostOrder(&root);
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

void postOrderNonRecursive(BTNode *root, int maxSize) {
    if (root != NULL) {
        BTNode *stack1[maxSize];
        BTNode *stack2[maxSize];
        int top1 = -1;
        int top2 = -1;
        BTNode *node;
        stack1[++top1] = root;
        while (top1 >= 0) {
            node = stack1[top1--];
            stack2[++top2] = node;
            if (node->leftNode != NULL) {
                stack1[++top1] = node->leftNode;
            }
            if (node->rightNode != NULL) {
                stack1[++top1] = node->rightNode;
            }
        }
        while (top2 >= 0) {
            node = stack2[top2--];
            printf("%c\t",node->data);
        }
        printf("\n");
    }
}

TBTNode *pre = NULL;
void createInThread(TBTNode *root) {
    if (root != NULL) {
        inThread(root);
        pre->rightChild = NULL; //非空二叉树线索化
        pre->rightTag = 1; // 处理最后一个节点
    }
}

void inThread(TBTNode *p) {
    if (p != NULL) {
        inThread(p->leftChild);
        if (p->leftChild == NULL) {
            p->leftChild = pre;
            p->leftTag = 1; // 0表示节点本身指向的leftChild，1表示当前节点的前驱节点
        }
        if (pre != NULL && pre->rightChild == NULL) {
            pre->rightChild = p;
            pre->rightTag = 1; // 0表示节点本身指向的rightChild，1表示当前的节点的后继节点
        }
        pre = p;
        inThread(p->rightChild);
    }
}

TBTNode *First(TBTNode *p) {
    while (p->leftTag == 0) {
        p = p->leftChild;
    }
    return p;
}

TBTNode *InOrderLastNode(TBTNode *p) {
    while (p && p->rightTag == 0) {
        p = p->rightChild;
    }
    return p;
}

TBTNode *InOrderPriorNode(TBTNode *p) {
    if (p != NULL) {
        if (p->leftTag == 1) {
            return p->leftChild;
        } else {
            return InOrderLastNode(p->leftChild); // 如果leftTag为0，则前驱为左子树的最后一个节点
        }
    } else {
        return NULL;
    }
}

TBTNode *InOrderPreNext(TBTNode *t) { // 结点p在中序线索二叉树查找前序下的后继
    TBTNode *p = t;
    if (!p->leftTag) {
        p = p->leftChild;
    } else if(!p->rightTag) {
        p = p->rightChild;
    } else {
        p = t;
        while (p && p->rightTag) {
            p = p->rightChild;
        }
        if (p) {
            p = p->rightChild;
        }
    }
    return p;
}


TBTNode *Next(TBTNode *p) {
    if (p->rightTag == 0) {
        return First(p->rightChild);
    } else {
        return p->rightChild; // rightTag == 1 直接返回当前节点
    }
}

void threadInOrder(TBTNode *root) {
    printf("thread in order:");
    for (TBTNode *p = First(root); p != NULL; p = Next(p)) {
        printf("%c\t",p->data);
    }
    printf("\n");
}

void createPreThread(TBTNode *root) {
    if (root != NULL) {
        preThread(root);
        pre->rightChild = NULL; //非空二叉树线索化
        pre->rightTag = 1; // 处理最后一个节点
    }
}

void preThread(TBTNode *p) {
    if (p != NULL) {
        if (p->leftChild == NULL) {
            p->leftChild = pre;
            p->leftTag = 1;
        }
        if (pre != NULL && pre->rightChild == NULL) {
            pre->rightChild = p;
            pre->rightTag = 1;
        }
        pre = p;
        if (p->leftTag == 0) { //左右指针不是线索化才能继续执行递归操作
            preThread(p->leftChild);
        }
        if (p->rightTag == 0) {
            preThread(p->rightChild);
        }
    }
}

void threadPreOrder(TBTNode *root) {
    if (root != NULL) {
        TBTNode *p = root;
        while (p != NULL) {
            while (p->leftTag == 0) {
                printf("%c\t",p->data);
                p = p->leftChild;
            }
            printf("%c\t",p->data);
            p = p->rightChild;
        }
        printf("\n");
    }
}

void createPostThread(TBTNode *p) {
    if (p != NULL) {
        postThread(p);
    }
}

void postThread(TBTNode *p) {
    if (p != NULL) {
        postThread(p->leftChild);
        postThread(p->rightChild);
        if (p->leftChild == NULL) {
            p->leftChild = pre;
            p->leftTag = 1;
        }
        if (pre != NULL && pre->rightChild == NULL) {
            pre->rightChild = p;
            pre->rightTag = 1;
        }
        pre = p;
    }
}

// 后序D B E C A 逆后序结果:A    C    E    B    D
void threadPostOrder(TBTNode *root) { // D B E C A
    if (root != NULL) {
        TBTNode *p = root;
        while (p != NULL) {
            while (p && p->rightTag == 0) {
                printf("%c\t",p->data);
                p = p->rightChild;
            }
            printf("%c\t",p->data);
            while (p->leftChild && p->leftTag == 1) {
                p = p->leftChild;
                printf("%c\t",p->data);
            }
            p = p->leftChild;
        }
        printf("\n");
    }
}




