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
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}
