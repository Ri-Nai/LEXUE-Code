#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0, val = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        if (arr[i] > 50)
            --i, --n;
        else
        {
            sum += arr[i];
            val = max(val, arr[i]);
        }
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    for (int len = val; len <= sum; ++len)
    {
        if (sum % len)
            continue;
        vector<int> usd(n);
        function<int(int, int, int)> dfs = [&](int now, int rest, int last) -> int
        {
            if (now == 0)
                return 1;
            if (rest == 0)
                return dfs(now - 1, len, 0);
            int fail = 0;
            for (int i = last; i < n; ++i)
            {
                if (!usd[i] && rest - arr[i] >= 0 && fail != arr[i])
                {
                    usd[i] = now;
                    if (dfs(now, rest - arr[i], i + 1))
                        return 1;
                    fail = arr[i];
                    usd[i] = 0;
                    if (rest == len || rest - arr[i] == 0)
                        return 0;
                }
            }
            return 0;
        };

        if (dfs(sum / len, len, 0))
        {
            cout << len << endl;
            break;
        }
    }
}
