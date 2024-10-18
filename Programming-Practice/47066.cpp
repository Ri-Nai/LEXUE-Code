
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> ans;
    vector<int> point;
    string last;
    int base;
    Solution(int n, int m)
    {
        // write your code here
        // int base = 0
        srand(time(NULL));
        point.assign(n, 1);
        last.resize(n);
        base = 0;
    }
    int doJudge(string usersAnswer, int lastAnswer)
    {
        // write your code here
        int cnt = 0;
        for (int i = 0; i < point.size(); i++)
        {
            if (last[i] - '0' == lastAnswer)
                ++point[i];
        }
        // for (auto x : usersAnswer)
        for (int i = 0; i < usersAnswer.size(); i++)
        {
            if (usersAnswer[i] == '1')
                cnt += point[i];
            else
                cnt -= point[i];
        }
        last = usersAnswer;
        int res = cnt > 0 ? 1 : 0;
        if (lastAnswer != -1 && ans.back() != lastAnswer)
            base ^= rand() % 2;
        res ^= base;
        ans.push_back(res);
        return res;
    }
}; // you should finish this

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<string> usersAnswers;
    vector<int> answers;
    for (int i = 0; i < m; i++)
    {
        char s[25555];
        int ans;
        scanf("%s%d", s, &ans);
        usersAnswers.push_back(s);
        answers.push_back(ans);
    }
    Solution yourSolution(n, m);
    for (int i = 0; i < m; i++)
    {
        int result = yourSolution.doJudge(usersAnswers[i], i == 0 ? -1 : answers[i - 1]);
        printf("%d\n", result);
    }
    return 0;
}
