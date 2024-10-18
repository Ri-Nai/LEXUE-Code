#include <stdio.h>
void solve(int l, int r, int L, int R, int p)
{
    if (l == L && R == r)
    {
        printf("%d %d %d\n", p, L, R);
        return;
    }
    int mid = L + R >> 1;
    if (r <= mid)
        solve(l, r, L, mid, p << 1);
    else if (l > mid)
        solve(l, r, mid + 1, R, p << 1 | 1);
    else
        solve(l, mid, L, mid, p << 1), solve(mid + 1, r, mid + 1, R, p << 1 | 1);
}
int main()
{
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    solve(l, r, 1, n, 1);
}
