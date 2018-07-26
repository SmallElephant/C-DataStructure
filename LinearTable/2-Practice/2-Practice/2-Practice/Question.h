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

bool deleteMinNumber(SqlList *list,int num);

void swap(int *a,int *b);
void reverseList(int a[],int n);

#endif /* Question_h */


