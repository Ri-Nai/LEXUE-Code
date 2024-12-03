#include <vector>
#include <iostream>

const int N = 1e5 + 9;
class Heap
{
private:
    std::vector<int> heap;
    int size() const
    {
        return heap.size();
    }
    int& get(int idx)
    {
        return heap[idx];
    }
    int get(int idx) const
    {
        return heap[idx];
    }

    int getFather(int idx)
    {
        return (idx - 1) / 2;
    }
    int getLeftson(int idx) const
    {
        return idx * 2 + 1;
    }
    int getRightson(int idx) const
    {
        return idx * 2 + 2;
    }
    void maintain(int idx)
    {
        for (int i = idx, j = idx; getLeftson(i) < size(); i = j)
        {
            j = getLeftson(i);
            if (getRightson(i) < size() && get(getRightson(i)) > get(j))
                j = getRightson(i);
            if (get(j) <= get(i))
                break;
            std::swap(get(i), get(j));
        }
    }
public:
    Heap() {}
    void push(int x)
    {
        heap.push_back(x);
    }
    int pop()
    {
        int res = heap.front();
        std::swap(heap.front(), heap.back());
        heap.pop_back();
        return res;
    }
    void sort()
    {
        for (int i = size() - 1; i >= 0; --i)
            maintain(i);
    }
    friend std::ostream &operator<<(std::ostream &os, const Heap &h)
    {
        for (auto x : h.heap)
            os << x << ' ';
        return os;
    }
};

int main()
{
    int n;
    std::cin >> n;
    Heap Q;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        Q.push(x);
    }
    for (int i = 0; i < 3; ++i)
    {
        Q.sort();
        std::cout << Q << std::endl;
        Q.pop();
    }
}