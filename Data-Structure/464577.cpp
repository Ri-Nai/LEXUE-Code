#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> ans;
    auto solve = [&](string s)
    {
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
                    int x = num.top();
                    num.pop();
                    num.push(-x);
                }
                return ;
            }
            int r = num.top();
            num.pop();
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
                num.push(l / r);
            else if (op == '%')
                num.push(l % r);
            else if (op == '^')
                num.push(Qpow(l, r));
        };
        int first = 1, now = 0;
        int maybe = 1;
        string name = "";
        for (char c : s)
        {
            // putchar(c);
            if (isdigit(c))
            {
                now = (now << 1) + (now << 3) + (c ^ 48);
                first = 0;
                continue;
            }
            if (isalpha(c))
            {
                name += c;
                first = 0;
                continue;
            }
            if (!first)
            {
                if (name.empty())
                    num.push(now);
                else num.push(ans[name]);
                name = "";
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
                    work();
                ops.pop();
                maybe = 0;
            }
            else if (prior(c))
            {
                char op = c;
                if (maybe)
                    if (prior(op) == 1)
                        op = -op;
                while (!ops.empty() && (prior(ops.top()) > prior(op) - (prior(ops.top()) != 3 && op >= 0)))
                    work();
                ops.push(op);
                maybe = 1;
            }
        }
        // cout << "?\n";
        while (!ops.empty())
            work();
        return num.top();
    };
    string s;
    while (cin >> s)
    {
        if (s == "end")
            break;
        if (!s.empty() && s.front() == '?')
        {
            cin >> s;
            cout << s << "=" << ans[s] << "\n";
        }
        else
        {
            int pos = s.find('=');
            string name = s.substr(0, pos);
            string op = s.substr(pos + 1);
            ans[name] = solve(op);
        }
    }
}
