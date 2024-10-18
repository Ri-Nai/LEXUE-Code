#include <stdio.h>
char op[105];
int stk[3005], top;
int ans[3005], tot;
int main()
{
    while (~scanf("%s", &op))
    {
        if (op[0] == 's')
        {
            if (top) for (int i = 1; i <= top; ++i)
                printf("%d%c", stk[i], " \n"[i == top]);
            else puts("");
        }
        else if (op[2] == 'p')
            ans[++tot] = stk[top--];
        else
        {
            int x;
            sscanf(op, "push(%d)", &x);
            stk[++top] = x;
        }
    }
    while (top)
        ans[++tot] = stk[top--];
    for (int i = 1; i <= tot; ++i)
        printf("%d%c", ans[i], " \n"[i == tot]);
}
