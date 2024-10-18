#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    struct BiTree
    {
        struct Node
        {
            char data;
            vector<Node*> son;
            Node() : son(2, nullptr) {}
        };
        Node* root;
        int n;
        BiTree(string s)
        {
            n = s.size();
            Build(s, root, 0);
        }
        int Build(string s, Node*& rt, int index)
        {
            if (s[index] == '#')
                return index;
            rt = new Node();
            rt->data = s[index];
            int nxt = Build(s, rt->son[0], index + 1);
            return Build(s, rt->son[1], nxt + 1);
        }
        void show(Node *rt, int depth, int p)
        {
            if (rt == nullptr)
                return;
            cout << string(depth * 4, ' ') << rt->data << endl;
            show(rt->son[p], depth + 1, p);
            show(rt->son[p ^ 1], depth + 1, p);
        }
        void preOrdered(Node* rt, int p)
        {
            if (rt == nullptr)
                return;
            cout << rt->data;
            preOrdered(rt->son[p], p);
            preOrdered(rt->son[p ^ 1], p);
        }
        void inOrdered(Node* rt, int p)
        {
            if (rt == nullptr)
                return;
            inOrdered(rt->son[p], p);
            cout << rt->data;
            inOrdered(rt->son[p ^ 1], p);
        }
        void postOrdered(Node *rt, int p)
        {
            if (rt == nullptr)
                return;
            postOrdered(rt->son[p], p);
            postOrdered(rt->son[p ^ 1], p);
            cout << rt->data;
        }
        int countLeaves(Node *rt)
        {
            if (rt == nullptr)
                return 0;
            if (rt->son[0] == nullptr && rt->son[1] == nullptr)
                return 1;
            return countLeaves(rt->son[0]) + countLeaves(rt->son[1]);
        }
        void solve()
        {
            cout << "BiTree" << endl;
            show(root, 0, 0);
            cout << "pre_sequence  : ";
            preOrdered(root, 0);
            cout << endl;
            cout << "in_sequence   : ";
            inOrdered(root, 0);
            cout << endl;
            cout << "post_sequence : ";
            postOrdered(root, 0);
            cout << endl;
            cout << "Number of leaf: " << countLeaves(root) << endl;
            cout << "BiTree swapped" << endl;
            show(root, 0, 1);
            cout << "pre_sequence  : ";
            preOrdered(root, 1);
            cout << endl;
            cout << "in_sequence   : ";
            inOrdered(root, 1);
            cout << endl;
            cout << "post_sequence : ";
            postOrdered(root, 1);
            cout << endl;

        }
    }BiTree(s);
    BiTree.solve();
    return 0;
}
