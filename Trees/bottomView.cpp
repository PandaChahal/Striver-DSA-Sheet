#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> mpp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int level = it.second;
        mpp[level] = node->data;
        if (node->left)
        {
            q.push({node->left, level - 1});
        }
        if (node->right)
        {
            q.push({node->right, level + 1});
        }
    }
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(11);
    root->right->left = new Node(9);

    vector<int> ans = topView(root);

    cout << "Bottom View Traversal: " << endl;
    for (auto node : ans)
    {
        cout << node << " ";
    }
    return 0;
}
