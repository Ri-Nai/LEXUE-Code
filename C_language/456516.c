#include <stdio.h>
#include <limits.h>
#define int long long
int calculate_conflict(int n, int matrix[20][20], int team[])
{
    int conflict = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (team[i] == team[j])
            { // Only add conflict if soldiers are in the same team
                conflict += matrix[i][j];
            }
        }
    }
    return conflict;
}

int find_min_conflict(int n, int matrix[20][20])
{
    int min_conflict = 1e18;
    // Iterate over all possible team assignments
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int team[20];
        for (int i = 0; i < n; i++)
        {
            team[i] = (mask >> i) & 1;
        }
        int conflict = calculate_conflict(n, matrix, team);
        if (conflict < min_conflict)
        {
            min_conflict = conflict;
        }
    }
    return min_conflict;
}

main()
{
    int n;
    scanf("%d", &n);
    int matrix[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &matrix[i][j]);
        }
    }

    printf("%lld\n", find_min_conflict(n, matrix));

    return 0;
}
