#include <stdio.h>
#define N 1005
const char dc[] = {'D', 'L', 'R', 'U'};
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, -1, 1, 0};
int n, m;
char s[N][N];
int Sx, Sy;
int pre[N][N];
int X[2], Y[2];
int Qx[N * N], Qy[N * N], head, tail;
void get_ans(int x, int y)
{
    if (x == Sx && y == Sy)
        return;
    int p = pre[x][y];
    get_ans(x - dx[p], y - dy[p]);
    putchar(dc[p]);
}
int check(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return 0;
    if (pre[x][y] != -1 || s[x][y] == '#')
        return 0;
    return 1;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", s[i]);
        for (int j = 0; j < m; ++j)
        {
            pre[i][j] = -1;
            if (s[i][j] == 'S')
                Sx = i, Sy = j;
            else if (s[i][j] == '1' || s[i][j] == '2')
                X[s[i][j] - '1'] = i, Y[s[i][j] - '1'] = j;
        }
    }
    pre[Sx][Sy] = 114514;
    Qx[tail] = Sx, Qy[tail++] = Sy;
    while (head < tail)
    {
        int x = Qx[head];
        int y = Qy[head++];
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!check(nx, ny))
                continue;
            Qx[tail] = nx;
            Qy[tail++] = ny;
            pre[nx][ny] = i;
        }
    }
    for (int i = 0; i <= 1; ++i)
    {
        if (pre[X[i]][Y[i]] == -1)
            puts("-1");
        else get_ans(X[i], Y[i]), puts("");
    }

}
