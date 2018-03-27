//
//  main.c
//  1-BaseOperate
//
//  Created by FlyElephant on 2018/3/27.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_length(char *s) { // 字符串的长度
    int len = 0;
    while (*s != '\0') {
        s++;
        len++;
    }
    return len;
}

int str_compare(char *s1, char *s2) { // 字符串长度比较
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

char *str_cat(char *s1, char *s2) { // 字符串拼接
    char *res = (char *)malloc(str_length(s1) + str_length(s2) + 1);
    char *head = res;
    while (*s1) {
        *res++ = *s1++;
    }
    while (*s2) {
        *res++ = *s2++;
    }
    *res = '\0';
    return head;
}

char *str_sub(char *s1, int pos, int len) { // 字符串截取
    char *res = (char *)malloc(len + 1);
    char *head = res;
    int i = 0;
    while (*s1) {
        if (i >= pos && (i - pos) < len) {
             *res++ = *s1;
        }
        s1++;
        i++;
    }
    *res = '\0';
    return head;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char *str1 = "abc";
    int n = str_length(str1);
    printf("字符串的长度:%d\n",n);
    char *str2 = "defg";
    int res = strcmp(str1, str2);
    if (res < 0) {
        printf("字符串%s小于%s\n",str1, str2);
    } else if (res == 0) {
        printf("字符串%s等于%s\n",str1, str2);
    } else {
        printf("字符串%s等于%s\n",str1, str2);
    }
    char *result = str_cat("abc", "def");
    printf("字符串拼接的结果:%s\n",result);
    char *sub = str_sub("abcdefg", 1, 2);
    printf("截取的结果:%s\n",sub);
    return 0;
}
