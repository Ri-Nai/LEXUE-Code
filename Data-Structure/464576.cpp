#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    s += '#';
    stack<char> ops;
    stack<int> num;
    auto prior = [](char op)
    {
        if (op < 0)
            return 4;
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/' || op == '%')
            return 2;
        if (op == '^')
            return 3;
        return 0;
    };
    auto work = [&]()
    {
        char op = ops.top();
        ops.pop();
        if (op < 0)
        {
            if (-op == '-')
            {
                if (num.empty())
                    return -1;
                int x = num.top();
                num.pop();
                num.push(-x);
            }
            return 0;
        }
        if (num.empty())
            return -1;
        int r = num.top();
        num.pop();
        if (num.empty())
            return -1;
        int l = num.top();
        num.pop();
        auto Qpow = [](int x, int p)
        {
            int res = 1;
            for (; p; p >>= 1, x *= x)
                if (p & 1)
                    res *= x;
            return res;
        };
        if (op == '+')
            num.push(l + r);
        else if (op == '-')
            num.push(l - r);
        else if (op == '*')
            num.push(l * r);
        else if (op == '/')
        {
            if (r == 0)
                return -2;
            num.push(l / r);
        }
        else if (op == '%')
        {
            if (r <= 0)
                return -1;
            num.push(l % r);
        }
        else if (op == '^')
        {
            if (r < 0)
                return -1;
            num.push(Qpow(l, r));
        }
        else
            return -1;
        // cout << op << '\n';
        return 0;
    };
    auto deal_work = [&](int error = 0)
    {
        if (error)
        {
            puts("error.");
            return 1;
        }
        int status = work();
        if (!status)
            return 0;
        if (status == -1)
            puts("error.");
        else
            puts("Divide 0.");
        return 1;
    };
#define warning_work(x) \
    if (deal_work(x))   \
    return
    int first = 1, now = 0;
    int maybe = 1;
    for (char c : s)
    {
        // putchar(c);
        if (isdigit(c))
        {
            now = (now << 1) + (now << 3) + (c ^ 48);
            first = 0;
            continue;
        }
        else if (!first)
        {
            num.push(now);
            now = 0;
            first = 1;
            maybe = 0;
        }
        if (c == '(')
        {
            ops.push('(');
            maybe = 1;
        }
        else if (c == ')')
        {
            while (!ops.empty() && ops.top() != '(')
                warning_work();
            if (ops.empty())
                warning_work(1);
            ops.pop();
            maybe = 0;
        }
        else if (prior(c))
        {
            char op = c;
            if (maybe)
                if (prior(op) == 1)
                    op = -op;
                else 
                    warning_work(-1);
            while (!ops.empty() && (prior(ops.top()) > prior(op) - (prior(ops.top()) != 3 && op >= 0)))
                warning_work();
            ops.push(op);
            maybe = 1;
        }
    }
    // cout << "?\n";
    while (!ops.empty())
        warning_work();
    if (num.size() != 1)
        warning_work(1);
    cout << num.top() << '\n';
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
}
