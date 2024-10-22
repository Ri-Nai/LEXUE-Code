#include <bits/stdc++.h>
using namespace std;
int main()
{
    int total, n;
    cin >> total >> n;
    vector<int> values(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> values[i];
    vector<vector<int>> ans(total + 1);
    ans[0] = {0};
    for (int i = 1; i <= n; ++i)
        for (int j = total; j >= values[i]; --j)
            if (!ans[j - values[i]].empty())
            {
                auto tmp = ans[j - values[i]];
                tmp.push_back(i);
                if (ans[j].empty() || tmp < ans[j])
                    ans[j] = tmp;
            }
    for (int i = total; i >= 0; --i)
        if (!ans[i].empty())
        {
            cout << i << endl;
            for (int j = 1; j < ans[i].size(); ++j)
                cout << ans[i][j] << " ";
            cout << endl;
            return 0;
        }
}
