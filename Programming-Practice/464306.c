#include <stdio.h>
#define N 100005
#define int long long
int heap[N];
int size = 0;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insert(int x)
{
    heap[++size] = x;
    int i = size;
    while (i > 1 && heap[i] < heap[i / 2])
    {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}
int extractMin()
{
    int min = heap[1];
    heap[1] = heap[size--];
    int i = 1;
    while (i <= size / 2)
    {
        int j = 2 * i;
        if (j < size && heap[j] > heap[j + 1])
            j++;
        if (heap[i] <= heap[j])
            break;
        swap(&heap[i], &heap[j]);
        i = j;
    }
    return min;
}

void main()
{
    int n;
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%lld", &x);
        insert(x);
    }
    int ans = 0;
    while (size > 1)
    {
        int x = extractMin();
        int y = extractMin();
        insert(x + y);
        ans += x + y;
    }
    printf("%lld\n", ans);
}
