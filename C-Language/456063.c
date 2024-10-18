/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>

int m, n, t, p, q, num;
void dfs(int a, int b);
int main()
{
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        t = 0;
        scanf("%d%d%d%d", &n, &m, &p, &q);
        dfs(p, q);
        printf("%d\n", t);
    }
    return 0;
}
const int dx[] = {1, 2, -1, -2};
const int dy[] = {2, 1, 2, 1};
void dfs(int p, int q)
{
    if (p < 0 || q < 0 || p > n || q > m)
        return;
    if (p == n && q == m)
    {
        ++t;
        return ;
    }
    for (int i = 0; i < 4; ++i)
        dfs(p + dx[i], q + dy[i]);
}
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
