int f(int n, int m)
{
    if (n > m && m > 0 && n < 4)
        return 1;
    if (n > m && m > 4 && m % 2 == 0)
        return f(n, m - 1) + f(n, m - 3);
    if (n > m && m > 4 && m % 2 == 1)
        return f(n, m - 2) + f(n - 4, m);
    return -1;
}
