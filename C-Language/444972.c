#include <stdio.h>
#define N 1005
int cnt[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int op, n;
        scanf("%d%d", &op, &n);
        if (op == 1)
        {
            int mxS = 0, mxd = 0;
            for (int i = 0, x; i < n; ++i)
            {
                scanf("%d", &x);
                x = x - i;
                if (x < 0) x += n;
                if (++cnt[x] > mxS)
                    mxS = cnt[x], mxd = x;
                else if (cnt[x] == mxS && x < mxd)
                    mxd = x;
            }
            for (int i = 0; i < n; ++i)
                cnt[i] = 0;
            printf("%d %d\n", mxS, mxd);
        }
        else printf("%d\n", 2 - (n & 1));
    }
}
