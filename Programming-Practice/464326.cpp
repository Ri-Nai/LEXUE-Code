#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> index(114, -1);
    struct Doctor
    {
        int x, y, id;
        Doctor() : x(0), y(0), id(0) {}
        Doctor(int id) : id(id), x(0), y(0) {}
        bool operator<(const Doctor &_) const
        {
            if (x && y && _.x && _.y)
            {
                if (x < _.x && y < _.y)
                    return true;
                if (x > _.x && y > _.y)
                    return false;
                if (x < _.x)
                    return (_.x - x) > (y - _.y);
                return (_.y - y) > (x - _.x);
            }
            return 0;
        }
        bool operator==(const Doctor &_) const
        {
            return !(*this < _) && !(_ < *this);
        }
    };

    vector<Doctor> doctors;
    auto getId = [&](int num)
    {
        if (index[num] == -1)
        {
            index[num] = doctors.size();
            doctors.emplace_back(num);
        }
        return index[num];
    };
    auto readDoctors = [&](int p)
    {
        int n;
        cin >> n;
        cin.get();
        int ranking = 1;
        for (int i = 1; i <= n; ++i)
        {
            string s;
            getline(cin, s);
            stringstream ss(s);
            int x;
            int cnt = 0;
            while (ss >> x)
            {
                // cout << x << " ";
                if (p)
                    doctors[getId(x)].y = ranking;
                else
                    doctors[getId(x)].x = ranking;
                ++cnt;
            }
            // cout << endl;
            ranking += cnt;
        }
    };
    readDoctors(0);
    readDoctors(1);
    vector<Doctor> once, twice;
    for (auto d : doctors)
    {
        if (d.x && d.y)
            twice.push_back(d);
        else
            once.push_back(d);
    }
    vector<tuple<int, int, int>> edge;
    vector<int> dis(114);
    for (auto d1 : twice)
        for (auto d2 : twice)
        {
            int u = d1.id, v = d2.id;
            if (u == v)
                continue;
            if (d1 == d2)
            {
                edge.emplace_back(u, v, 0);
                edge.emplace_back(v, u, 0);
            }
            else if (d1 < d2)
                edge.emplace_back(v, u, -1);
        }

    auto BellmanFord = [&]()
    {
        for (int i = 1; i < 114; ++i)
        {
            for (auto e : edge)
            {
                int u = get<0>(e);
                int v = get<1>(e);
                int w = get<2>(e);
                if (dis[v] > dis[u] + w)
                    dis[v] = dis[u] + w;
            }
        }
    };
    BellmanFord();
    const int Error = -1;
    vector<int> equal(114, Error);
    vector<int> mark(114);
    vector<Doctor> valid;
    auto addMark = [&](const vector<Doctor> &doctors)
    {
        for (auto d : doctors)
        {
            int u = d.id;
            for (auto dt : twice)
            {
                int v = dt.id;
                if (d.x && d.x == dt.x || d.y && d.y == dt.y)
                {
                    if (equal[u] != Error && dis[equal[u]] != dis[v])
                        mark[u] = 1;
                    else
                        equal[u] = v;
                }
            }
            if (mark[u] == 1)
                continue;
            if (equal[u] != Error)
            {
                edge.emplace_back(u, equal[u], 0);
                edge.emplace_back(equal[u], u, 0);
                continue;
            }
            for (auto left : twice)
                for (auto right : twice)
                {
                    int l = left.id, r = right.id;
                    if (d.x && d.x > left.x && d.x < right.x && dis[l] >= dis[r]
                     || d.y && d.y > left.y && d.y < right.y && dis[l] >= dis[r])
                    {
                        mark[u] = 1;
                        break;
                    }
                }
        }
    };

    auto linkValid = [&]()
    {
        for (auto d1 : valid)
            for (auto d2 : valid)
            {
                int u = d1.id, v = d2.id;
                if (u == v)
                    continue;
                if (d1.x && d2.x)
                {
                    if (d1.x < d2.x)
                        edge.emplace_back(v, u, -1);
                    if (d1.x == d2.x)
                        edge.emplace_back(u, v, 0);
                }
                if (d1.y && d2.y)
                {
                    if (d1.y < d2.y)
                        edge.emplace_back(v, u, -1);
                    if (d1.y == d2.y)
                        edge.emplace_back(u, v, 0);
                }
            }
        for (auto d1 : valid)
        {
            int u = d1.id;
            if (equal[u] != Error)
                continue;
            for (auto d2 : twice)
            {
                int v = d2.id;
                if (d1.x)
                {
                    if (d1.x < d2.x)
                        edge.emplace_back(v, u, -1);
                    if (d1.x > d2.x)
                        edge.emplace_back(u, v, -1);
                }
                if (d1.y)
                {
                    if (d1.y < d2.y)
                        edge.emplace_back(v, u, -1);
                    if (d1.y > d2.y)
                        edge.emplace_back(u, v, -1);
                }
            }
        }
    };
    auto validTovalids = [&]()
    {
        for (auto d1 : valid)
            for (auto d2 : valid)
            {
                int u = d1.id, v = d2.id;
                if (u == v)
                    continue;
                if (dis[u] != dis[v])
                    continue;
                int val1 = d1.x + d1.y;
                int val2 = d2.x + d2.y;
                if (val1 == val2)
                    edge.emplace_back(u, v, 0);
                if (val1 < val2)
                    edge.emplace_back(v, u, -1);
            }
    };

    addMark(once);
    for (auto d : once)
        if (mark[d.id] == 0)
            valid.push_back(d);
    linkValid();
    BellmanFord();
    for (int i = 0; i < 100; ++i)
        validTovalids(), BellmanFord();
    valid.insert(valid.end(), twice.begin(), twice.end());
    sort(valid.begin(), valid.end(), [&](Doctor a, Doctor b)
         { return dis[a.id] < dis[b.id]; });
    for (int i = 0; i < valid.size(); ++i)
    {
        int j = i;
        while ((j + 1) < valid.size() && dis[valid[j].id] == dis[valid[j + 1].id])
            ++j;
        for (int k = i; k <= j; ++k)
            cout << valid[k].id << " \n"[j == k];
        i = j;
    }
}
