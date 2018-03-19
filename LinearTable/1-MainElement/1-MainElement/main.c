//
//  main.c
//  1-MainElement
//
//  Created by FlyElephant on 2018/3/19.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <stdio.h>

//已知一个整数序列 A =(a 0 ，a 1 ，..., a n-1 ) ， 其中0≤ai<n(0≤i<n)。 若存在a p1 =a p2 =...=a pm =x且m>n/2(0≤p k <n，1≤k≤m)，则称 x 为 A 的主元素。 例如A= ( 0， 5， 5， 3， 5， 7， 5， 5 )，则 5 为主元素；又如 A= ( 0， 5， 5， 3， 5， 1， 5， 7 )， 则A 中没有主元素。假设 A 中的 n 个元素保存在一个一维数组中，请设计一个尽可能高效的算法，找出 A 的主元素。若存在主元素， 则输出该元素；否则输出-1。要求：
//
//（1）给出算法的基本设计思想。
//（2）根据设计思想，采用 C 或 C++或 Java 语言描述算法，关键之处给出注释。
//（3）说明你所设计算法的时间复杂度和空间复杂度。

//1.从前到后扫描数组中的元素元素，标记可能的主元素为num，出现的次数count设置为0
//2.将遇到的第一个元素赋值给num，count设置为0，扫描数组，如果元素的值和num相等，count加1.如果不相等，对count进行判断，count如果大于0，count减1，否则将count设置为0，重新赋值num.
//3.统计num出现的次数，判断是否符合要求.

int majority(int a[], int n) {
    int count = 0;
    int num = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] == num) {
            count++;
        } else {
            if (count > 0) {
                count--;
            } else {
                num = a[i];
                count = 1;
            }
        }
    }
    if (count > 0) {
        count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == num) {
                count++;
            }
        }
    }
    if (count > n / 2) {
        return num;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[8] = {0, 5, 5, 3, 5, 7, 5, 5};
    int num = majority(a, 8);
    if (num >= 0) {
        printf("主元素---%d\n",num);
    } else {
        printf("不存在主元素\n");
    }
    return 0;
}
