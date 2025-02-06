#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

vector<int> preorderTraversal(Node *root)
{
    vector<int> ans;
    Node *cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            ans.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            Node *prev = cur->left;
            while (prev->right && prev->right != cur)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = cur;
                ans.push_back(cur->data);
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return ans;
}

int main()
{
    Node * root = new Node (1);
    root -> left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans = preorderTraversal(root);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}