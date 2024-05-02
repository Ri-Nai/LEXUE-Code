#include <stdio.h>
int A[202025];
int main()
{
    int Q;
    scanf("%d", &Q);
    int n = 0;
    while (Q--)
    {
        int op, x;
        scanf("%d%d", &op, &x);
        if (op)
        {
            printf("%d\n", A[x]);
            for (int i = x; i <= n; ++i)
                A[i] = A[i + 1];
            --n;
        }
        else
        {
            int pos = 1;
            while(pos <= n && A[pos] <= x) ++pos;
            for (int i = n; i >= pos; --i)
                A[i + 1] = A[i];
            ++n;
            A[pos] = x;
        }
    }
}
