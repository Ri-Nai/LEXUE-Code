#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> m >> n;
    vector<string> S(n);
    for (int i = 0; i < n; ++i)
        cin >> S[i];
    int state = 1 << n - 1;
    int ans = 1;
    for (int i = 0; i < state; ++i)
    {
        auto work = [&](int state) -> int
        {
            vector<int> has;
            for (int i = 0; i < n; ++i)
                if (1 << i & state)
                    has.push_back(i);
            for (int i = 0; i < m; ++i)
            {
                auto last = has;
                vector<int> cnt(2);
                has.clear();
                for (int id : last)
                    ++cnt[S[id][i] == '-'];
                if (cnt[1] == cnt[0])
                    return 0;
                for (int id : last)
                    if (S[id][i] == "+-"[cnt[0] < cnt[1]])
                        has.push_back(id);
                if (has[0] != 0)
                    return 0;
            }
            return has.size();
        };
        ans = max(ans, work(i << 1 | 1));
    }
    cout << ans << '\n';
}
/*
4 5
+-+-
++--
+-+-
++-+
+-+-

*/
