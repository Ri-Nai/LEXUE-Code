#include <stdio.h>
#include <string.h>
#define N 201313
char s[N][6];
int n, A[N], L[N], R[N];
void Del(int p)
{
    L[R[p]] = L[p];
    R[L[p]] = R[p];
    printf("%s %s\n", s[L[p]], s[R[p]]);
}
int main()
{
    scanf("%d", &n);
    strcpy(s[0], "eijuy");
    strcpy(s[n + 1], "vrqfb");
    R[0] = 1, L[n + 1] = n;
    for (int i = 1; i <= n; ++i)
        L[i] = i - 1, R[i] = i + 1, scanf("%d", &A[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%s", s[i]);
    for (int i = 1; i <= n; ++i)
        Del(A[i]);
}
