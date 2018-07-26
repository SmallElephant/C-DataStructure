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
#endif /* Question_h */


