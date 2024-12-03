#include <bits/stdc++.h>

void solve()
{
    std::string s;
    std::cin >> s;
    for (auto &c : s)
        c = c  == '+' ? 1 : -1;
    int last = 0;
    s = '\0' + s;
    for (auto &c : s)
        last = c += last;
    std::cout << *max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end()) << std::endl;
}
int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--)
        solve();
}
