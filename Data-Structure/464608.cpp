#include <bits/stdc++.h>
using namespace std;
struct Tree
{
    struct Node
    {
        string name;
        vector<Node *> children;
    };
    vector<int> degreeCount;
    Node *root;
    Tree() : degreeCount(1) {}
    int build(Node *&rt, const string &s, int pos)
    {
        ++pos;
        if (s[pos] == ')')
            return pos;
        rt = new Node;
        while (pos < s.size() && s[pos] != ')' && s[pos] != ',')
            rt->name += s[pos++];
        while (pos < s.size() && s[pos] != ')')
        {
            if (s[pos] == ',')
                ++pos;
            Node *child = new Node;
            pos = build(child, s, pos);
            if (child->name.empty())
                delete child;
            else
                rt->children.push_back(child);
        }
        if (rt->children.size() >= degreeCount.size())
            degreeCount.resize(rt->children.size() + 1);
        ++degreeCount[rt->children.size()];
        return ++pos;
    }
    int getDegree()
    {
        return degreeCount.size() - 1;
    }
    void showDegree()
    {
        cout << "Degree of tree: " << getDegree() << endl;
        for (int i = 0; i < degreeCount.size(); ++i)
            cout << "Number of nodes of degree " << i << ": " << degreeCount[i] << endl;
    }
    void show(Node *rt, int depth, int p)
    {
        if (rt == nullptr || rt->name.empty())
            return;
        cout << string(depth * 4, ' ') << rt->name << endl;
        for (auto child : rt->children)
            show(child, depth + 1, p);
    }
    void solve(const string &s)
    {
        build(root, s, 0);
        show(root, 0, 0);
        showDegree();
    }
} Tr;
int main()
{
    string s;
    cin >> s;
    Tr.solve(s);
}
//
