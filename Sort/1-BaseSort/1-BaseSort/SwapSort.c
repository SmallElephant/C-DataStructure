//
//  SwapSort.c
//  1-BaseSort
//
//  Created by FlyElephant on 2018/5/7.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include "SwapSort.h"

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int a[],int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) { // 方案实现比较简单，强烈推荐
            if (a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

void bubbleSort1(int a[],int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}


