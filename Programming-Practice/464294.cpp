#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> A;
    for (int i = 0; i < n; ++i)
        A.push_back(s[i] ^ 48);
    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
        if (A[i])
            A[i] ^= 1, A[i + 1] ^= 1, ++ans;
    if (A.back())
        puts("-1");
    else 
        cout << ans << '\n';
}
