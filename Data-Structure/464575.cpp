#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Stack
{
private:
    Node<T> *topNode;

public:
    Stack() : topNode(nullptr) {}

    bool empty() const
    {
        return topNode == nullptr;
    }

    void push(const T &value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    T top() const
    {
        return topNode->data;
    }

    T pop()
    {
        T result = topNode->data;
        Node<T> *temp = topNode;
        topNode = topNode->next;
        delete temp;
        return result;
    }
};
void solve()
{
    string s;
    cin >> s;
    Stack<char> op;
    string ans;
    auto prior = [](char c)
    {
        if (c == '+' || c == '-')
            return 1;
        if (c == '*' || c == '/')
            return 2;
        if (c == '^')
            return 3;
        return 0;
    };
    for (char c : s)
    {
        if (c == '(')
            op.push('(');
        else if (c == ')')
        {
            while (!op.empty() && op.top() != '(')
                ans += op.pop();
            op.pop();
        }
        else if (prior(c))
        {
            while (!op.empty() && (prior(op.top()) > prior(c) - (prior(op.top()) != 3)))
                ans += op.pop();
            op.push(c);
        }
        else if (c != '#')
            ans += c;
    }
    while (!op.empty())
        ans += op.pop();
    cout << ans << '\n';
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
}
