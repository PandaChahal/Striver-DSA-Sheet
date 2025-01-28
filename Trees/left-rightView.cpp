#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
    Node(int val)
    {
        left = right = NULL;
        data = val;
    }
};

vector<int> leftSide(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return ans;
    }
    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }
    leftSide(root->left, level + 1, ans);
    leftSide(root->right, level + 1, ans);
    return ans;
}

vector<int> rightSide(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return ans;
    }
    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }
    leftSide(root->right, level + 1, ans);
    leftSide(root->left, level + 1, ans);
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(11);
    int level = 0;
    vector<int> ans;
    cout << "enter if you want to view right or left view :" << " ";
    string s;
    cin >> s;
    cout << endl;
    vector<int> view;
    if (s == "right")
    {
        view = rightSide(root, level, ans);
        for (int i : view)
        {
            cout << i << " ";
        }
    }
    else if (s == "left")
    {
        view = leftSide(root, level, ans);
        for (int i : view)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "Invalid input! Please enter 'right' or 'left'.";
    }
    return 0;
}