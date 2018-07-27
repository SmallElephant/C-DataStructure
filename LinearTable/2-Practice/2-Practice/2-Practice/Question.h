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

void printData(int arr[], int n);
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

// 已知在一维数组A[m+n]中依次存放着两个线性表，将数组中两个顺序表的位置互换

void reverse(int arr[],int left,int right,int n);
void reverseArr(int arr[],int m,int n);

// 顺序表中查找到x元素，如果存在则与后继元素交换，否则将其插入当前的位置，并将元素插入

void searchExchangeInsert(int arr[],int x,int n);

#endif /* Question_h */


