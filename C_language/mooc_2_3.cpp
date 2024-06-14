#include <cmath>
#include <cstdio>
#include <cctype>
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        while (!isalpha(s[i])) ++i;
        while (!isalpha(s[j])) --j;
        if (i >= j)
            break;
        if (s[i] > s[j])
            swap(s[i], s[j]);
        ++i, --j;
    }
    cout << s << endl;

}
