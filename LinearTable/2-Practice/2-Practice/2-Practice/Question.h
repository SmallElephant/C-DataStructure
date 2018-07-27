//
//  Question.h
//  2-Practice
//
//  Created by FlyElephant on 2018/7/26.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#ifndef Question_h
#define Question_h

#include <stdio.h>
#include <stdbool.h>

#define MaxSize 100

typedef struct SqlList {
    int data[MaxSize];
    int length;
} SqlList;

void swap(int *a,int *b);
bool deleteMinNumber(SqlList *list,int num);

// 将顺序表的所有元素逆置
void reverseList(int a[],int n);

// 删除线性表中所有值为x的数据元素

void deleteSpecialNumber(SqlList *list,int num);
// 有序表中删除s和t区间的数字
void deleteRangeNumber(SqlList *list,int s,int t);

// 删除顺序表中在s和t区间范围的数字
void delte_from_sequence(SqlList *list,int s,int t);

// 从有序顺序表中删除所有值重复的元素，使表中所有元素的值均不同
void delete_same(SqlList *list);

// 将两个有序顺序表合并成一个新的有序顺序表,并由函数返回结果顺序表

void mergeList(SqlList *list1,SqlList *list2,SqlList *res);

#endif /* Question_h */


