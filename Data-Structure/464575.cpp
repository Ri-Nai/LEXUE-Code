#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    stack<char> op;
    string ans;
    auto prior = [](char c)
    {
        if (c == '+' || c == '-')
            return 1;
        if (c == '*' || c == '/')
            return 2;
        if (c == '^')
            return 3;
        return 0;
    };
    for (char c : s)
    {
        if (c == '(')
            op.push('(');
        else if (c == ')')
        {
            while (!op.empty() && op.top() != '(')
                ans += op.top(), op.pop();
            op.pop();
        }
        else if (prior(c))
        {
            while (!op.empty() && (prior(op.top()) > prior(c) - (prior(op.top()) != 3)))
                ans += op.top(), op.pop();
            op.push(c);
        }
        else if (c != '#')
            ans += c;
    }
    while (!op.empty())
        ans += op.top(), op.pop();
    cout << ans << '\n';
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
}
