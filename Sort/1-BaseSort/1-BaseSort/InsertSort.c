//
//  InsertSort.c
//  1-BaseSort
//
//  Created by FlyElephant on 2018/5/7.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include "InsertSort.h"


void insertSort(int a[],int n) {
    for (int i = 1; i < n; i++) {
        int cur = a[i]; // current value
        int j = i - 1;
        while (cur < a[j] && j >= 0) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = cur;
    }
}
