#include <bits/stdc++.h>
using namespace std;
struct Matrix
{
    int n, m;
    vector<vector<double>> data;
    Matrix() {}
    void input()
    {
        cin >> n;
        m = n + 1;
        data.resize(n, vector<double>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> data[i][j];
    }
    int GaussianElimination()
    {
        vector<int> Top;
        auto isZero = [](double x)
        {
            return fabs(x) < 1e-8;
        };
        auto clear = [&](int col0, int by, int from, int to)
        {
            for (int i = from; i < to; ++i)
            {
                if (isZero(data[i][col0]))
                    continue;
                double times = data[i][col0] / data[by][col0];
                for (int j = 0; j < m; ++j)
                    data[i][j] = data[i][j] - times * data[by][j];
            }
        };
        for (int i = 0, j = 0; i < n && j < m; ++i, ++j)
        {
            // show();
            int num = i;
            for (int nxt = i + 1; nxt < n; ++nxt)
                if (fabs(data[num][j]) < fabs(data[nxt][j]))
                    num = nxt;
            if (isZero(data[num][j]))
                --i;
            else
            {
                Top.push_back(j);
                swap(data[i], data[num]);
                clear(j, i, i + 1, n);
            }
        }
        int rank = Top.size();
        for (int i = rank - 1; i >= 0; --i)
            clear(Top[i], i, 0, i);
        for (int i = 0; i < rank; ++i)
        {
            int col0 = Top[i];
            for (int j = m - 1; j >= col0; --j)
                data[i][j] = data[i][j] / data[i][col0];
        }
        return rank;
    }
    void show()
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};
int main()
{
    Matrix A;
    A.input();
    int rank = A.GaussianElimination();
    if (rank != A.n)
        cout << "No Solution" << endl;
    else
        for (int i = 0; i < rank; ++i)
            cout << fixed << setprecision(2) << A.data[i].back() << endl;
}
