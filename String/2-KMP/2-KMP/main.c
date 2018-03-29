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
        return i - j;
    } else {
        return -1;
    }
}

void getNext(char *pattern, int next[]) {
    int j = -1;  // 记录最长前后缀字符串的长
    int len = strlen(pattern);
    next[0] = -1;  // 初始值设置为-1，有利于首字符串对比的校验
    for (int i = 1; i < len; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1]; // 递归，逐层深入，找到最近的一个设置被标记为0的位置
        }
        if (j == -1 || pattern[i] == pattern[j]) { // j = -1 第一个匹配的字符串长度是0，字符串长度递增
            j++;
        }
        next[i] = j;
    }
}

int kmp_match(char *s, char *p, int next[]) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    if (sLen < pLen) {
        return -1;
    }
    int i = 0;
    int j = 0;
    getNext(p, &next[0]);
    while (i < sLen && j < pLen) {
        if (s[i] == p[j]) {
            i++;
            j++;
        } else {
            j = next[j]; // 相比较一般的字符串遍历，i不回退，j回退至相对应的位置
            if (j == -1) { // 首位字符与主串字符不相等
                j = 0;
                i++;
            }
        }
    }
    if (j == pLen) {
        return i - j;
    } else {
        return -1;
    }
}

//计算 next 数组：根据待匹配的字符串，求出对应每一位的最大相同前后缀的长度
void computeNext(char *str, int next[])
{
    int k = -1;//记录最长前后缀字符串的长
    int i = 1;//
    //next【0】=-1，肯定要遍历模式串
    next[0] = -1;
    //模式串长度
    int len = strlen(str);
    //第一岑循环控制计算到模式串的每一位
    while (i < len) {
        //第二层循环，控制每次计算到某位置时，递归求解 k 的过程
        //next[next[next[k-1]-1]-1……]=next[j+1] 且 next[j]=k
        while (k > 0 && str[i] != str[k]) {
            k = next[k - 1];//递归，逐层深入，调用
        }
        //i 变化，如果 stri=strk，退出递归循环，直接+1求解，否则一直递归到为k<=0退出
        if (k == -1 || str[i] == str[k]) {
            k++;
        }
        //所有情况都处理完毕，存储结果
        next[i] = k;
        i++;
    }
}

int strKMPCompare(char *strMain, char *strSub, int index, int next[])
{
    int iMain = index;
    int jSub = 0;
    int lenMain = strlen(strMain);
    int lenSub = strlen(strSub);
    
    while ((iMain >= 0 && iMain <= lenMain - 1) && ((jSub >= 0 && jSub <= lenSub - 1))){
        if (strMain[iMain] == strSub[jSub]) {
            iMain++;
            jSub++;
        }else{
            //主串的 i 不回溯！
            //计算 next 数组
            computeNext(strSub, &next[0]);
            jSub = next[jSub];
            if (jSub == -1 ) {
                jSub = 0;
                iMain++;
            }
        }
    }
    //如果匹配 ok，肯定子串先比完。
    if (jSub > lenSub - 1) {
        return iMain - lenSub;//得到的就是匹配 ok 后，主串里第一个和模式串第一个字符匹配的字符的位置
    }else{
        return 0;//匹配失败
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char *str1 = "abcdefgh";
    char *str2 = "g";
    int next[100] = {0};
    
    int i = strKMPCompare(str1, str2, 0 , &next[0]);
    for (int i = 0; i < 11; i++) {
        printf("%d\t", next[i]);
    }
    printf("\n");
    printf("相遇的位置：%d\n", i);
    
    int j = kmp_match(str1, str2, &next[0]);
    for (int i = 0; i < 11; i++) {
        printf("%d\t", next[i]);
    }
    printf("\n");
    printf("相遇的位置：%d\n", i);
    return 0;
}
