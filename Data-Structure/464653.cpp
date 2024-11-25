#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int CUTOFF = 5;
void numInput(vector<int> &input)
{
    string x;
    while (cin >> x, x != "#")
        input.push_back(stoi(x));
}

void insertSort(vector<int> &arr, int lPos, int rPos)
{
    for (int i = lPos + 1; i <= rPos; ++i)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= lPos && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;
    }
}

int median3(vector<int> &arr, int lPos, int rPos)
{
    int mid = (lPos + rPos) / 2;
    vector<int> tmp = {arr[lPos], arr[mid], arr[rPos]};
    sort(tmp.begin(), tmp.end());
    arr[lPos] = tmp[0];
    arr[mid] = tmp[2];
    arr[rPos] = tmp[1];
    return arr[rPos];
}

int partition(vector<int> &arr, int lPos, int rPos, vector<int> &mds)
{
    mds.push_back(median3(arr, lPos, rPos));
    int pivot = arr[rPos];
    int left = lPos;
    int right = rPos - 1;

    while (true)
    {
        while (left <= right && arr[left] < pivot)
            ++left;
        while (left <= right && arr[right] > pivot)
            --right;
        if (left < right)
        {
            swap(arr[left], arr[right]);
            ++left;
            --right;
        }
        else
        {
            break;
        }
    }

    if (arr[left] > pivot)
    {
        arr[rPos] = arr[left];
        arr[left] = pivot;
    }

    return left;
}
void quickSort(vector<int> &arr, int lPos, int rPos, vector<int> &mds)
{
    if (rPos - lPos < CUTOFF)
        insertSort(arr, lPos, rPos);
    else
    {
        int block = partition(arr, lPos, rPos, mds);
        quickSort(arr, lPos, block - 1, mds);
        quickSort(arr, block + 1, rPos, mds);
    }
}

void printResults(const vector<int> &input, const vector<int> &mds)
{
    cout << "After Sorting:" << endl;
    for (int num : input)
        cout << num << " ";
    cout << endl;
    cout << "Median3 Value:" << endl;
    if (mds.empty())
        cout << "none" << endl;
    else
    {
        for (int num : mds)
            cout << num << " ";
        cout << endl;
    }
}

int main()
{
    vector<int> input;
    vector<int> mds;

    numInput(input);
    quickSort(input, 0, input.size() - 1, mds);
    printResults(input, mds);

    return 0;
}
