//
//  InsertSort.c
//  1-BaseSort
//
//  Created by FlyElephant on 2018/5/7.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include "InsertSort.h"

void insertSort(int a[],int n) {
    for (int i = 1; i < n; i++) {
        int j;
        int cur = a[i]; // 选择这种方式，比较容易理解
        for (j = i - 1; j >= 0 && cur < a[j]; j--) {
            a[j+1] = a[j];
        }
        a[j+1] = cur;
    }
}

void insertSort1(int a[],int n) {
    for (int i = 1; i < n; i++) {
        int j;
        int cur = a[i];
        for (j = i; j > 0 && cur < a[j-1]; j--) {
            a[j] = a[j-1];
        }
        a[j] = cur;
    }
}

void shellSort(int a[],int n) {
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int j;
            int cur = a[i];
            for (j = i - gap; j >= 0 && cur < a[j]; j -= gap) {
                a[j+gap] = a[j];
            }
            a[j+gap] = cur;
        }
        gap = gap / 2;
    }
}

