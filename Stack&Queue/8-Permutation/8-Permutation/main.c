//
//  main.c
//  8-Permutation
//
//  Created by FlyElephant on 2018/3/26.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void allRange(char *str, int start, int length) {
    if (start == length - 1) {
        printf("%s\n",str);
    } else {
        for (int i = start; i <= length - 1; i++) {
            swap(&str[start], &str[i]); // 下标为start的数开始，分别与它后面的数字交换
            allRange(str, start + 1, length);
            swap(&str[start], &str[i]); // 为了防止重复的情况，还需要将start处的元素重新换回来
        }
    }
    
}

void permutation(char *str) {
    if (str == NULL) {
        return;
    }
    allRange(str, 0, strlen(str));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char str[] = "abc";
    permutation(str);
    return 0;
}
