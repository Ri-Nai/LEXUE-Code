#include <bits/stdc++.h>
using namespace std;
struct Matrix
{
    int n, m;
    map<pair<int, int>, int> result;

    void input()
    {
        cin >> n >> m;
        int t;
        cin >> t;
        while (t--)
        {
            int x, y, z;
            cin >> x >> y >> z;
            result[make_pair(x, y)] = z;
        }
    }
    Matrix operator *(const Matrix &_)const
    {
        Matrix res;
        res.n = n;
        res.m = _.m;
        for (auto i : result)
            for (auto j : _.result)
                if (i.first.second == j.first.first)
                    res.result[make_pair(i.first.first, j.first.second)] += i.second * j.second;
        return res;
    }
    void show()
    {
        cout << n << endl << m << endl;
        vector<pair<int, int>> dels;
        for (auto i : result)
            // cout << i.first.first << "," << i.first.second << "," << i.second << endl;
            if (i.second == 0)
                dels.push_back(i.first);
        for (auto i : dels)
            result.erase(i);
        cout << result.size() << endl;
        for (auto i : result)
            cout << i.first.first << "," << i.first.second << "," << i.second << endl;

    }
};
int main()
{
    Matrix A, B;
    A.input();
    B.input();
    (A * B).show();
}
