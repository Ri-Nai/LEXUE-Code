#include <bits/stdc++.h>
using namespace std;
int main()
{
    string post, in;
    cin >> in >> post;
    struct BiTree
    {
        struct Node
        {
            char data;
            vector<Node *> son;
            Node() : son(2, nullptr) {}
        };
        Node *root;
        int n;
        BiTree(string postOrdered, string inOrdered)
        {
            n = postOrdered.size();
            int d = n;
            build(root, postOrdered, inOrdered, 0, n, d);
            levelOrder();
        }
        void build(Node *&rt, const string &postOrdered, const string &inOrdered, int l, int r, int &d)
        {
            if (l >= r)
                return;
            int index = find(inOrdered.begin() + l, inOrdered.begin() + r, postOrdered[d - 1]) - inOrdered.begin();
            if (index == r)
                return;
            rt = new Node;
            rt->data = postOrdered[--d];
            build(rt->son[1], postOrdered, inOrdered, index + 1, r, d);
            build(rt->son[0], postOrdered, inOrdered, l, index, d);
        }
        void levelOrder()
        {
            queue<Node *> q;
            q.push(root);
            while (!q.empty())
            {
                Node *t = q.front();
                q.pop();
                cout << t->data;
                for (Node *son : t->son)
                    if (son)
                        q.push(son);
            }
            cout << endl;
        }
    } BiTree(post, in);
    return 0;
}
