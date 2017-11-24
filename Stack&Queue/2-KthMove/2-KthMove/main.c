//
//  main.c
//  2-KthMove
//
//  Created by FlyElephant on 2017/11/23.
//  Copyright © 2017年 FlyElephant. All rights reserved.
//

#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(int *a, int b, int e) {
    while (b < e) {
        swap(&a[b], &a[e]);
        b++;
        e--;
    }
}

void show(int *a, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 7;
    int k = 2 % n;
    int a[7] = {1,2,3,4,5,6,7};
    reverse(a, 0, n - 1);
    reverse(a, 0, k - 1);
    reverse(a, k, n - 1);
    show(a, n);
    return 0;
}
