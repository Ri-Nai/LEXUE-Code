#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n;
    vector<int> lg(n + 1);
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i >> 1] + 1;
    vector<int> a(n + 1);
    vector<vector<int>> st(n + 1, vector<int>(lg[n] + 1));
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        st[i][0] = a[i];
    for (int j = 1; j <= lg[n]; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[i][j] = st[i][j - 1] & st[i + (1 << (j - 1))][j - 1];
    auto query = [&](int l, int k)
    {
        if (a[l] < k)
            return -1;
        int now = a[l];
        int pos = l + 1;
        for (int j = lg[n]; j >= 0; --j)
            if (pos + (1 << j) - 1 <= n && (now & st[pos][j]) >= k)
            {
                now &= st[pos][j];
                pos += (1 << j);
            }
        return pos - 1;
    };
    cin >> q;
    while (q--)
    {
        int l, k;
        cin >> l >> k;
        cout << query(l, k) << " ";
    }
    cout << endl;


}
