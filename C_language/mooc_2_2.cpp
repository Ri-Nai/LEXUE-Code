#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int n;
    char c;
    scanf("%d,%c", &n, &c);
    long long ans = 0;
    auto nxt = [&](char &c)
    {
        char t = c;
        if (c == 'z')
            c = 'a' - 1;
        ++c;
        return t;
    };
    for (int i = 1; i <= n; ++i)
        cout << nxt(c);
    cout << endl;
    for (int i = 1; i < n - 1; ++i)
    {
        for (int j = 1; j < n - i; ++j)
            putchar(' ');
        cout << nxt(c) << endl;
    }
    for (int i = 1; i <= n; ++i)
        cout << nxt(c);
    cout << endl;

}
