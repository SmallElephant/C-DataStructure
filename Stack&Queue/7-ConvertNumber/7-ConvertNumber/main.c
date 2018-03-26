//
//  main.c
//  7-ConvertNumber
//
//  Created by FlyElephant on 2018/3/26.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <stdio.h>

int convertNumber(int a[], int number) {
    int num = number;
    int i = 0;
    while (num != 0) {
        a[i] = num % 2;
        num = num / 2;
        i++;
    }
    return i;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[100] = {0};
    int end = convertNumber(a, 1);
    for (int i = 0; i < end; i++) {
        printf("%d--",a[i]);
    }
    printf("\n");
    return 0;
}
