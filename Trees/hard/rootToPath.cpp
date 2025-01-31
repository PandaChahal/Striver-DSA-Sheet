#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

bool getPath(Node *root, vector<int> &ans, int n)
{
    if (root == NULL)
    {
        return false;
    }

    ans.push_back(root->data);
    if (root->data == n)
    {
        return true;
    }

    if (getPath(root->left, ans, n) || getPath(root->right, ans, n))
    {
        return true;
    }
    ans.pop_back();
    return false;
}

int main()
{
    Node *root = new Node(1);
    root->right = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    vector<int> ans;
    cout<<getPath(root,ans,7);
    return 0;
}