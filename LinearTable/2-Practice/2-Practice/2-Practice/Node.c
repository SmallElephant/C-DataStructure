//
//  Node.c
//  2-Practice
//
//  Created by FlyElephant on 2018/7/31.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include "Node.h"
#include <stdlib.h>

void printList(ListNode *head) {
    ListNode *node = head;
    while (node != NULL) {
        printf("%d  ",node->val);
        node = node->next;
    }
    printf("\n");
}

int list_length(ListNode *list) {
    ListNode *p = list;
    int count = 0;
    while (p != NULL) {
        p = p->next;
        count++;
    }
    return count;
}

void delete_node_x(ListNode *list,int x) {
    if (list == NULL) {
        return;
    }
    if (list->val == x) {
        ListNode *next = list->next;
        list->val = next->val;
        list->next = next->next; // 覆盖当前结点，实现删除功能
        delete_node_x(list, x);
    } else {
        delete_node_x(list->next, x);
    }
}

void delete_node_normal(ListNode *list,int x) {
    ListNode *pre = list; // 前驱结点
    ListNode *node = list;
    while (node != NULL) {
        if (node->val == x) {
            pre->next = node->next;
            node = node->next;
        } else {
            pre = node;
            node = node->next;
        }
    }
}

// 逆序输出链表的值可以通过栈来实现，也可以递归实现

void reverse_print(ListNode *list) {
    if (list->next != NULL) {
        reverse_print(list->next);
    }
    printf("%d  ",list->val);
}

// 删除最小的结点
void delete_min_node(ListNode *list) {
    ListNode *pre = list;
    ListNode *node = list->next;
    ListNode *minPre = list;
    ListNode *min = list->next;
    while (node != NULL) {
        if (node->val < min->val) {
            minPre = pre;
            min = node;
            pre = node;
            node = node->next;
        }
        pre = node;
        node = node->next;
    }
    minPre->next = min->next;
}

ListNode *reverse_list(ListNode *list) {
    ListNode *pre = NULL;
    ListNode *node = list;
    while (node != NULL) {
        ListNode *next = node->next;
        node->next = pre;
        pre = node;
        node = next;
    }
    return pre;
}

void sort_list(ListNode *list) {
    ListNode *p = list->next;
    ListNode *q = p->next; // 持有p的后继结点指针
    ListNode *pre;
    p->next = NULL; // 构造只有一个结点的有序表
    p = q;
    while (p != NULL) {
        q = p->next;
        pre = list;
        while (pre->next != NULL && pre->next->val < p->val) { // 在有序表中找到p结点的插入位置
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}

void delete_range(ListNode *list, int min, int max) {
    ListNode *pre = list;
    ListNode *p = list->next; // 检测指针
    while (p != NULL) {
        if (p->val > min && p->val < max) {
            pre->next = p->next;
            pre = p;
        }
        p = p->next;
    }
}


ListNode *search_first_common(ListNode *list1,ListNode *list2) {
    // 如果两个链表有一个公共结点，那么该公共结点之后的所有结点是重合的，即它们的最后一个节点必然是重合的
    int len1 = list_length(list1);
    int len2 = list_length(list2);
    int diff = 0;
    ListNode *longList;
    ListNode *shortList;
    if (len1 > len2) {
        diff = len1 - len2;
        longList = list1;
        shortList = list2;
    } else {
        diff = len2 - len1;
        longList = list2;
        shortList = list1;
    }
    for (int i = 0; i < diff; i++) {
        longList = longList->next;
    }
    // 同步，寻找到一个相同的结点
    while (longList && shortList && longList->val != shortList->val) {
        longList = longList->next;
        shortList = shortList->next;
    }
    return longList;
}

void delete_min_sequence(ListNode *list) {
    ListNode *head = list;
    while (head != NULL) {
        ListNode *pre = head;
        if (pre && pre->next == NULL) {
            printf("%d  ",pre->val);
            head = NULL;
        } else {
            ListNode *p = pre->next;
            while (p && p->next != NULL) {
                if (p->next->val < pre->next->val) {
                    pre = p;
                }
                p = p->next;
            }
            printf("%d  ",pre->next->val);
            ListNode *min = pre->next;
            pre->next = min->next;
        }
    }
    printf("\n");
}

void discreate(ListNode *list) {
    ListNode *list1 = NULL;
    ListNode *list2 = NULL;
    ListNode *head1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *head2 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p = list;
    int i = 0;
    while (p != NULL) {
        i++;
        if (i%2==1) { // 如果序号是奇数
            if (i == 1) {
                head1->val = p->val;
                head1->next = NULL;
                list1 = head1;
            } else {
                list1->next = p;
                list1 = p;
            }
        } else {
            if (i == 2) {
                head2->val = p->val;
                head2->next = NULL;
                list2 = head2;
            } else {
                list2->next = p;
                list2 = p;
            }
        }
        p = p->next;
    }
    list1->next = NULL;
    list2->next = NULL;
    printList(head1);
    printList(head2);
}


void discreate2(ListNode *list) {
    ListNode *head2 = (ListNode *)malloc(sizeof(ListNode));
    head2->val = -1;
    head2->next = NULL;
    ListNode *rb = head2;
    ListNode *ra = list;
    ListNode *p = list->next;
    int i = 0;
    while (p != NULL) {
        i++;
        if (i%2==1) { // 如果序号是奇数
            ra->next = p;
            ra = p;
        } else {
            rb->next = p;
            rb = p;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
    printList(head2);
    printList(list);
}


