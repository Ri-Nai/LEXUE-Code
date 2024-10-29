#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    struct Mat
    {
        vector<vector<ll>> A;
        int mod;
        Mat(int k, int _mod)
            : A(2, vector<ll>(2))
        {
            A[0][0] = A[1][1] = k;
            A[0][1] = A[1][0] = 0;
            mod = _mod;
        }
        Mat operator*(const Mat &_) const
        {
            Mat res(0, mod);
            for (int i = 0; i <= 1; ++i)
                for (int j = 0; j <= 1; ++j)
                    for (int k = 0; k <= 1; ++k)
                        res.A[i][j] = (res.A[i][j] + A[i][k] * _.A[k][j] % mod) % mod;
            return res;
        }
        Mat Pow(ll n)
        {
            Mat res(1, mod);
            Mat p = *this;
            while (n)
            {
                if (n & 1)
                    res = res * p;
                p = p * p;
                n >>= 1;
            }
            return res;
        }
    };
    int x, y, mod;
    cin >> x >> y >> mod;
    const double pi = acos(-1);
    const double phi = cos(36 * pi / 180) * 2;
    // cout << phi * phi << endl;
    // ll first = (ll)(x * 2.618033988749894902525738871190696954727172851562L) - 1;
    ll first = (ll)(x * phi * phi) - 1;
    ll second = first + first - x + 1;
    first %= mod;
    second %= mod;
    Mat F(0, mod), P(0, mod);
    F.A[0][0] = first, F.A[1][0] = (mod + second - first) % mod;
    P.A[0][0] = P.A[0][1] = P.A[1][0] = 1;
    Mat T = P.Pow(y - 1) * F;
    cout << T.A[0][0] << endl;
}
/*
1 1 2 3 5
1 1 4 9
1 2 6 15

1 1 0    1 1 0
0 0 0    1 0 1
0 0 0    0 0 1
*/
