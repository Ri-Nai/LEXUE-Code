#include <vector>
#include <iostream>
#include <algorithm>
int main()
{
    const int mod = 167772161;
    int ans = 1, n;
    std::cin >> n;
    std::vector<int> A(n);
    for (int i = 0; i < n; ++i)
        std::cin >> A[i];
    std::sort(A.begin(), A.end());
    for (int i = 0; i < n; ++i)
        ans = 1ll * ans * (A[i] - i) % mod;
    printf("%d\n", ans);
}
