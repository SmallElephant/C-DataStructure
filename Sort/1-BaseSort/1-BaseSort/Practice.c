//
//  Practice.c
//  1-BaseSort
//
//  Created by FlyElephant on 2018/5/10.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include "Practice.h"

void resort(int a[],int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            swap(&a[i], &a[j]);
            j++;
        }
    }
}
