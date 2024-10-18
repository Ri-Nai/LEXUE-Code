#include <stdio.h>
#include <stdlib.h>
int check1(int *arr)
{
    return arr[0] + arr[1] > arr[2];
}
int check2(int *arr)
{
    if (!check1(arr))
        return 0;
    return arr[0] == arr[1] || arr[1] == arr[2];
}
int check3(int *arr)
{
    if (!check1(arr))
        return 0;
    return arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2];
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, l, r;
        scanf("%d%d%d", &n, &l, &r);
        int ans1 = 0;
        int ans2 = 0;
        int ans3 = 0;
        for (int a = l; a <= r; ++a)
        {
            for (int b = a; b <= r; ++b)
            {
                for (int c = b; c <= r; ++c)
                    if (a + b + c == n)
                    {
                        int arr[3] = {a, b, c};
                        // qsort(arr, 3, sizeof(int), cmp);
                        if (arr[1] > arr[2])
                            swap(arr+1, arr+2);
                        if (arr[0] > arr[1])
                            swap(arr+0, arr+1);
                        if (arr[1] > arr[2])
                            swap(arr+1, arr+2);
                        ans1 += check1(arr);
                        ans2 += check2(arr);
                        ans3 += check3(arr);
                    }
            }
        }
        printf("%d %d %d\n", ans1, ans2, ans3);
    }
}
