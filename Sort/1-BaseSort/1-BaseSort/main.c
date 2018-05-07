//
//  main.c
//  1-BaseSort
//
//  Created by FlyElephant on 2018/5/7.
//  Copyright © 2018年 rrd. All rights reserved.
//

#include <stdio.h>
#include "InsertSort.h"

void printData(int a[],int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {10,9,8,7,6,5,4,3,2,1};
    insertSort(a, 10);
    printData(a, 10);
    return 0;
}
