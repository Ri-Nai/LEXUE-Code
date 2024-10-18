/*
题目描述：

Jaanai最近知道了质数的定义是指有且只有两个因数的自然数。而Jaanai在写数学题的时候，她突然发现有很多自然数刚好拥有3个因数，她感到非常神奇，于是便把这种数命名为“Jaanai数”。但是现在她碰到一个难题，想让你帮她判断一个数是否为“Jaanai数”。

（提示：建议使用并修改质数筛函数）

输入格式：

一行输入n个正整数（可能出现1）。

输出格式：

n行，第i行代表第i个数是否为“Jaanai数”。如果是，输出“TQL!”；如果不是，输出“TCL!”。

样例输入：

4 9 16 25 36 49 64 81 100
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 20005
int P[M];
void Euler()
{
    P[1] = 1;
    for (int i = 2; i < M; ++i)
        if (!P[i])
            for (int j = i * i; j < M; j += i)
                P[j] = 1;
}
int main()
{
    Euler();
    int x;
    while(~scanf("%d", &x))
    {
        int t = sqrt(x);
        if (!P[t] && t * t == x)
            printf("TQL!\n");
        else
            printf("TCL!\n");
    }
}
