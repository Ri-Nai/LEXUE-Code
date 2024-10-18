#include <stdio.h>
int n, m, x, y, a[401][401];
void dfs(int x, int y, int step);
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < 401; i++)
        for (int j = 0; j < 401; j++)
            a[i][j] = -1; // 这里初始化-1 表示为无法到达
    dfs(1, 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }
    return 0;
}
const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
void dfs(int x, int y, int step)
{
    a[x][y] = step;
    for (int i = 0; i < 8; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx <= 0 || nx > n || ny <= 0 || ny > m || ~a[nx][ny] && a[nx][ny] <= step + 1)
            continue;
        dfs(nx, ny, step + 1);
    }

}
