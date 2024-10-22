#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        minHeap.push(x);
    }
    long long ans = 0;
    while (minHeap.size() > 1)
    {
        int x = minHeap.top();
        minHeap.pop();
        int y = minHeap.top();
        minHeap.pop();
        ans += x + y;
        minHeap.push(x + y);
    }
    cout << "WPL=" << ans << endl;
}
