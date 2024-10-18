/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */
#include <stdio.h>
void solve(int pos, int opt);
int main()
{
    int n;
    scanf("%d", &n);
    solve(n, 0);
    puts("");
    return 0;
}
void solve(int pos, int opt)
{
    if (pos <= 0)
        return;
    if (opt == 0)
    {
        solve(pos - 2, 0);
        printf("%d ", pos);
        solve(pos - 2, 1);
        solve(pos - 1, 0);
    }
    else
    {
        solve(pos - 1, 1);
        solve(pos - 2, 0);
        printf("%d ", pos);
        solve(pos - 2, 1);
    }
}
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
