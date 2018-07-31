//
//  Node.h
//  2-Practice
//
//  Created by FlyElephant on 2018/7/31.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#ifndef Node_h
#define Node_h

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

#include <stdio.h>

#endif /* Node_h */

void printList(ListNode *head);

// 设计一个递归算法,删除不带头结点的单链表L中所有值为x的值

void delete_node_x(ListNode *list,int x);

// 在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一

void delete_node_normal(ListNode *list,int x);

// 设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值

void reverse_print(ListNode *list);

// 在带头结点的单链表L中删除一个最小值结点的高效算法

void delete_min_node(ListNode *list);

// 将带头结点的单链表就地逆置

ListNode *reverse_list(ListNode *list);

// 有一个带头结点的单链表L，设计一个算法使其元素递增有序

// 设在一个带表头结点的单链表中所有元素结点数值无序，删除表中所有结余给定的两个值之间的元素的元素

// 给定两个单链表，找出两个链表的公共结点
