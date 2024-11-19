#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    vector<int> ans;
    for (int i = 0; i < n; ++i)
        if (a[i] == i)
            ans.push_back(i);
    if (ans.empty())
        puts("No ");
    else
    {
        for (int x : ans)
            cout << x << " ";
        cout << endl;
    }
}
