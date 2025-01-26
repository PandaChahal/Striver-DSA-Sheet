#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int val)
    {
        data = val;
        right = left = NULL;
    }
};

vector<vector<int>> verticalOrder(Node *root)
{
    queue<pair<Node *, pair<int, int>>> q;
    map<int, map<int, multiset<int>>> nodes;

    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        Node *temp = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(temp->data);

        if (temp->left)
        {
            q.push({temp->left, {x - 1, y + 1}});
        }
        if (temp->right)
        {
            q.push({temp->right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto level : p.second)
        {
            col.insert(col.end(), level.second.begin(), level.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    vector<vector<int>> ans = verticalOrder(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "]";
    }

    return 0;
}