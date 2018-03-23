//
//  main.c
//  6-CountCombination
//
//  Created by FlyElephant on 2018/3/23.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <stdio.h>

//n个元素进栈，共有多少种出栈顺序？
// https://blog.csdn.net/zyearn/article/details/7758716
// C(2n,n) / (n+1)
void catalan(int n) {
    int a[100] = {0};
    a[0] = a[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            a[i] += a[j] * a[i - j - 1];
        }
    }
    for (int i = 0; i <= n; i++) {
        printf("i == %d时候，排列组合数量:%d\n",i,a[i]);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    catalan(6);
    return 0;
}
