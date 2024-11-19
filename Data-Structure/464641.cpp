#include <bits/stdc++.h>
using namespace std;
int main()
{
    struct BiTree
    {
        struct Node
        {
            int data;
            vector<Node*> son;
            Node() : son(2, nullptr) {}
        };
        Node* root;
        int n;
        BiTree() : root(nullptr), n(0) {}
        void insert(Node *&rt, int x)
        {
            if (rt == nullptr)
            {
                rt = new Node;
                rt->data = x;
            }
            else
            {
                if (x < rt->data)
                    insert(rt->son[0], x);
                else
                    insert(rt->son[1], x);
            }
        }
        void show(Node *rt, int depth, int p)
        {
            if (rt == nullptr)
                return;
            show(rt->son[p], depth + 1, p);
            cout << string(depth * 4, ' ') << rt->data << endl;
            show(rt->son[p ^ 1], depth + 1, p);
        }
        void inOrdered(Node* rt, int p)
        {
            if (rt == nullptr)
                return;
            inOrdered(rt->son[p], p);
            cout << " " << rt->data;
            inOrdered(rt->son[p ^ 1], p);
        }
        void solve()
        {
            for (int x; cin >> x, x;)
                insert(root, x);
            show(root, 0, 0);
            cout << endl;
            inOrdered(root, 0);
            cout << endl;
        }
    };
    BiTree().solve();
}
