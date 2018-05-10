//
//  Util.c
//  1-BaseSort
//
//  Created by FlyElephant on 2018/5/8.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include "Util.h"

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printData(int a[],int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

