#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        vector<int> level;
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front();

            q.pop();

            level.push_back(node->data);
            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}

void print(const vector<int>& ans)
{
    for (int num : ans) 
    {
        cout << num << " ";
    }
    cout << endl;
}
int main()
{
    Node *root = new Node(1);
    root->right = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<vector<int>> result = levelOrder(root);
    for (const vector<int>& level : result) 
    {
        print(level);
    }
    return 0;
}