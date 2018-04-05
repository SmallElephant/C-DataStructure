//
//  main.c
//  2-KMP
//
//  Created by FlyElephant on 2018/3/29.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <stdio.h>
#include <string.h>

//http://www.pandademo.com/2015/10/kmp-how-i-understand/
//http://www.cnblogs.com/kubixuesheng/p/4322612.html

int index_substring(char *source, char *sub) {
    int len = strlen(source);
    int len2 = strlen(sub);
    if (len < len2) {
        return -1;
    }
    int pos = -1;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len2; j++) {
            if (source[i+j] != sub[j]) {
                break;
            }
            if (j == (len2-1)) {
                pos = i;
                break;
            }
        }
    }
    return pos;
}

int index_match(char *s, char *p) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    if (sLen < pLen) {
        return -1;
    }
    int i = 0;
    int j = 0;
    while (i < sLen && j < pLen) {
        if (s[i] == p[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == pLen) {
        return i - pLen;
    } else {
        return -1;
    }
}

void getNext(char *p, int *next) {
    int j = 0;
    int k = -1; // 字符串真前缀和真后缀的匹配的最大长度
    int len = (int)strlen(p);
    next[0] = -1;
    while (j < len - 1) {
        if (k == -1 || p[j] == p[k]) {
            k++;
            j++;
            next[j] = k; // next[j]表示字符串在j号字符之前，最多有k个字符与开头的字符相同
        } else {
            k = next[k]; // 递归寻找更小的对称性，如果一直str[j]与str[k]不相等，k=-1
        }
    }
}

int kmp_index(char *s, char *p) {
    int sLen = (int)strlen(s);
    int pLen = (int)strlen(p);
    if (sLen < pLen) {
        return -1;
    }
    int i = 0;
    int j = 0;
    int next[100] = {0};
    getNext(p, next);
    for (int i = 0; i < strlen(p); i++) {
        printf("%d\t", next[i]);
    }
    printf("\n");
    while (i < sLen && j < pLen) {
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j >= pLen) {
        return i - pLen;
    } else {
        return -1;
    }
}

void getNextVal(char *p, int *next) {
    int j = 0;
    int k = -1; // 字符串真前缀和真后缀的匹配的最大长度
    int len = (int)strlen(p);
    next[0] = -1;
    while (j < len) {
        if (k == -1 || p[j] == p[k]) {
            k++;
            j++;
            if (p[j] != p[k]) {
                next[j] = k; // next[j]表示字符串在j号字符之前，最多有k个字符与开头的字符相同
            } else {
                next[j] = next[k]; // 如果next[j] 与 next[k]相等，继续往下寻找前后缀最大公共长度
            }
        } else {
            k = next[k]; // 递归寻找更小的对称性，如果一直str[j]与str[k]不相等，k=-1
        }
    }
}

int kmp_indexVal(char *s, char *p) {
    int sLen = (int)strlen(s);
    int pLen = (int)strlen(p);
    if (sLen < pLen) {
        return -1;
    }
    int i = 0;
    int j = 0;
    int next[100] = {0};
    getNext(p, next);
    for (int i = 0; i < strlen(p); i++) {
        printf("%d\t", next[i]);
    }
    printf("\n");
    while (i < sLen && j < pLen) {
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j >= pLen) {
        return i - pLen;
    } else {
        return -1;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char *str = "ababcababaf";
    char *pattern = "bca";
    int index = kmp_indexVal(str, pattern);
    printf("%s在%s中的匹配位置:%d\n",pattern,str,index);
    char *str1 = "aaaab";
    int next[100] = {0};
    getNext(str1, next);
    for (int i = 0; i < strlen(str1); i++) {
        printf("%d\t", next[i]);
    }
    printf("\n");
    int nextVal[100] = {0};
    getNextVal(str1, nextVal);
    for (int i = 0; i < strlen(str1); i++) {
        printf("%d\t", nextVal[i]);
    }
    printf("\n");
    return 0;
}
