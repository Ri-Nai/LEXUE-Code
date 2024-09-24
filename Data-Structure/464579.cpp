#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, land_time, takeoff_time;
    cin >> n >> land_time >> takeoff_time;
    int land_id = 5000, takeoff_id = 0;
    struct runway
    {
        int need, total;
        runway() : need(0), total(0) {}
    };
    vector<runway> runways(n + 1);
    queue<pair<int, int>> wating_land, waiting_takeoff;
    vector<int> nums(2), times(2);
    int current_time = 0;
    auto work = [&](bool is_input)
    {
        bool status = 1;
        bool flag = 0;
        printf("Current Time: %4d\n", current_time++);
        vector<int> empties;
        for (int i = 1; i <= n; ++i)
        {
            if (runways[i].need > 0)
            {
                if (--runways[i].need == 0)
                    printf("runway %02d is free\n", i);
                ++runways[i].total;
            }
            if (runways[i].need == 0)
                empties.push_back(i);
            else 
                flag = 1;
        }
        if (is_input)
        {
            int land_number, takeoff_number;
            cin >> land_number >> takeoff_number;
            if (land_number < 0 && takeoff_number < 0)
                status = 0;
            while (land_number-- > 0)
                wating_land.push({++land_id, current_time});
            while (takeoff_number-- > 0)
                waiting_takeoff.push({++takeoff_id, current_time});
        }
        for (auto x : empties)
        {
            if (wating_land.empty() && waiting_takeoff.empty())
                break;
            flag = 1;
            auto &Q = wating_land.empty() ? waiting_takeoff : wating_land;
            int id = Q.front().first;
            int type = id <= takeoff_id;
            ++nums[type];
            times[type] += current_time - Q.front().second;
            Q.pop();
            // cout << times[type] << endl;
            runways[x].need = id <= takeoff_id ? takeoff_time : land_time;
            printf("airplane %04d is ready to %s on runway %02d\n", id, type ? "takeoff" : "land", x);
        }
        if (is_input)
            return status;
        return flag;
    };
    while (work(1))
        ;
    while (work(0))
        ;
    printf("simulation finished\n");
    printf("simulation time: %4d\n", --current_time);
    printf("average waiting time of landing: %4.1f\n", 1. * times[0] / nums[0]);
    printf("average waiting time of takeoff: %4.1f\n", 1. * times[1] / nums[1]);
    for (int i = 1; i <= n; ++i)
        printf("runway %02d busy time: %4d\n", i, runways[i].total);
    int total = 0;
    for (int i = 1; i <= n; ++i)
        total += runways[i].total;
    printf("runway average busy time percentage: %4.1f%%\n", 100. * total / n / current_time);
}
